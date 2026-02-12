/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodmorei <rodmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:13:15 by rodmorei          #+#    #+#             */
/*   Updated: 2025/09/18 15:19:19 by rodmorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_table(int argc, char **argv, t_data *table)
{
	int	i;

	i = 1;
	table->nb_philo = ft_atol(argv[1]);
	table->time_die = ft_atol(argv[2]);
	table->time_eat = ft_atol(argv[3]);
	table->time_sleep = ft_atol(argv[4]);
	table->nb_must_eat = -1;
	table->start = 0;
	table->end = 0;
	table->full = 0;
	if (argc == 6)
		table->nb_must_eat = ft_atol(argv[5]);
	if (pthread_mutex_init(&table->data_mtx, NULL) == -1)
		return (send_error("TABLE MUTEX FAILED"));
	table->ptr_philos = malloc(sizeof(t_philo) * table->nb_philo);
	table->ptr_forks = malloc(sizeof(t_fork) * table->nb_philo);
	if (!table->ptr_philos || !table->ptr_forks)
		return (free_table(table), send_error("MALLOC FAILED"));
	if (init_forks(table) == -1)
		return (free_table(table), -1);
	if (init_philo_list(table) == -1)
		return (free_table(table), -1);
	return (0);
}

int	init_forks(t_data *table)
{
	long	i;
	long	nb_f;

	i = 0;
	nb_f = table->nb_philo;
	while (i++ != nb_f)
	{
		table->ptr_forks[i - 1].id = i;
		if (pthread_mutex_init(&table->ptr_forks[i - 1].frk_mtx, NULL) == -1)
			return (free_table(table), send_error("FORK MUTEX INIT FAILED"));
	}
	return (0);
}

int	init_philo_list(t_data	*table)
{
	long	i;
	t_philo	*p_list;

	p_list = table->ptr_philos;
	i = -1;
	while (++i < table->nb_philo)
	{
		p_list[i].id = i + 1;
		p_list[i].is_full = 0;
		p_list[i].last_eat = 0;
		p_list[i].nb_meals = 0;
		p_list[i].max_meals = table->nb_must_eat;
		assign_fork(&p_list[i], table);
		if (pthread_mutex_init(&p_list[i].ph_mtx, NULL) == -1)
			return (free_table(table), send_error("PHILO MUTEX INIT FAILED"));
		p_list[i].data = table;
	}
	return (0);
}

void	assign_fork(t_philo *philo, t_data	*table)
{
	philo->r_fork = &table->ptr_forks[philo->id - 1];
	if (philo->id == 1)
	{
		if (table->nb_philo == 1)
			philo->l_fork = NULL;
		else
			philo->l_fork = &table->ptr_forks[table->nb_philo - 1];
	}
	else
		philo->l_fork = &table->ptr_forks[(philo->id) - 2];
}

void	free_table(t_data *table)
{
	if (table->ptr_philos)
		free(table->ptr_philos);
	if (table->ptr_forks)
		free(table->ptr_forks);
}
