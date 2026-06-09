/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodmorei <rodmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:14:04 by rodmorei          #+#    #+#             */
/*   Updated: 2025/09/18 16:30:41 by rodmorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	thread_init(t_data *data)
{
	long	i;

	i = -1;
	while (++i != data->nb_philo)
	{
		if (pthread_create(&data->ptr_philos[i].ph_thread,
				NULL, ph_handle, &data->ptr_philos[i]) != 0)
			return (-1);
	}
	if (pthread_create(&data->monitor, NULL, monitor_handle, data) != 0)
		return (-1);
	return (0);
}
