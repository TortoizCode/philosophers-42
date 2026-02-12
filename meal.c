/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodmorei <rodmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:24:16 by rodmorei          #+#    #+#             */
/*   Updated: 2025/09/18 16:45:36 by rodmorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	start_meal(t_data	*table)
{
	long	i;

	i = -1;
	table->start = ms_time_get();
	if (thread_init(table) != 0)
		return (free_table(table), send_error("THREAD INIT FAILED"));
	while (++i < table->nb_philo)
	{
		if (pthread_join(table->ptr_philos[i].ph_thread, NULL) != 0)
			return (free_table(table), send_error("THREAD JOIN FAILED"));
	}
	pthread_join(table->monitor, NULL);
	return (0);
}

void	*ph_handle(void	*ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	pthread_mutex_lock(&philo->data->data_mtx);
	philo->data->nb_running++;
	pthread_mutex_unlock(&philo->data->data_mtx);
	while (!end_table(philo->data))
	{
		ft_eat(philo);
		check_full(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}

void	*monitor_handle(void	*data)
{
	long	i;
	t_data	*table;

	table = (t_data *)data;
	i = 0;
	while (!end_table(data))
	{
		i = 0;
		while (i < table->nb_philo)
		{
			if (check_death(&table->ptr_philos[i]) == 1)
				break ;
			i++;
			usleep(100);
		}
	}
	return (NULL);
}

void	one_philo(t_data *data)
{
	printf("%ld %i has taken a fork\n", ms_time_get(), 1);
	usleep(data->time_die * 1000);
	printf("%ld %i died\n", ms_time_get(), 1);
}
