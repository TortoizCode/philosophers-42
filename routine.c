/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodmorei <rodmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:51:56 by rodmorei          #+#    #+#             */
/*   Updated: 2025/09/18 16:44:36 by rodmorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	ft_eat(t_philo *philo)
{
	pthread_mutex_t	*fork_1;
	pthread_mutex_t	*fork_2;

	fork_1 = &philo->l_fork->frk_mtx;
	fork_2 = &philo->r_fork->frk_mtx;
	if (philo->id % 2 == 0)
	{
		fork_1 = &philo->r_fork->frk_mtx;
		fork_2 = &philo->l_fork->frk_mtx;
	}
	pthread_mutex_lock(fork_1);
	print_state(philo, 4);
	pthread_mutex_lock(fork_2);
	print_state(philo, 4);
	print_state(philo, 1);
	pthread_mutex_lock(&philo->ph_mtx);
	philo->last_eat = ms_time_get();
	philo->nb_meals++;
	pthread_mutex_unlock(&philo->ph_mtx);
	usleep(philo->data->time_eat * 1000);
	pthread_mutex_unlock(fork_1);
	print_state(philo, 5);
	pthread_mutex_unlock(fork_2);
	print_state(philo, 5);
}

void	ft_sleep(t_philo *philo)
{
	print_state(philo, 2);
	usleep(philo->data->time_sleep * 1000);
}

void	ft_think(t_philo *philo)
{
	print_state(philo, 3);
}
