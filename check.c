/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodmorei <rodmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:52:46 by rodmorei          #+#    #+#             */
/*   Updated: 2025/09/18 16:30:41 by rodmorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ver_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 5 && argc != 6)
		return (send_error("ARG COUNT WRONG"));
	while (++i != argc)
	{
		if (ft_is_digit(argv[i]) == -1)
			return (send_error("INVALID ARGUMENTS"));
		else if (ft_atol(argv[i]) <= 0 || ft_atol(argv[i]) > INT_MAX)
			return (send_error("INVALID ARGUMENTS"));
	}
	return (0);
}

int	send_error(char *err_msg)
{
	printf("ERROR: %s\n", err_msg);
	return (-1);
}

int	end_table(t_data	*table)
{
	pthread_mutex_lock(&table->data_mtx);
	if (table->full == table->nb_philo || table->end == 1)
	{
		pthread_mutex_unlock(&table->data_mtx);
		return (1);
	}
	pthread_mutex_unlock(&table->data_mtx);
	return (0);
}

int	check_full(t_philo *ph)
{
	if (ph->max_meals == ph->nb_meals)
	{
		pthread_mutex_lock(&ph->data->data_mtx);
		ph->data->full++;
		ph->is_full = 1;
		if (ph->data->full == ph->data->nb_philo)
			ph->data->end = 1;
		pthread_mutex_unlock(&ph->data->data_mtx);
		return (1);
	}
	return (0);
}

int	check_death(t_philo	*ph)
{
	long	curr_time;
	long	compare_time;

	pthread_mutex_lock(&ph->ph_mtx);
	curr_time = ms_time_get();
	if (ph->nb_meals == 0)
		compare_time = ph->data->start;
	else
		compare_time = ph->last_eat;
	if (curr_time - compare_time > ph->data->time_die)
	{
		pthread_mutex_lock(&ph->data->data_mtx);
		ph->data->end = 1;
		pthread_mutex_unlock(&ph->data->data_mtx);
		pthread_mutex_unlock(&ph->ph_mtx);
		print_state(ph, 6);
		return (1);
	}
	pthread_mutex_unlock(&ph->ph_mtx);
	return (0);
}
