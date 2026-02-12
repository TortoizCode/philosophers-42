/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodmorei <rodmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:48:31 by rodmorei          #+#    #+#             */
/*   Updated: 2025/09/18 16:30:41 by rodmorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

long	ms_time_get(void)
{
	struct timeval	curr_time;
	long			ms_time;

	gettimeofday(&curr_time, NULL);
	ms_time = (curr_time.tv_sec * 1000) + (curr_time.tv_usec / 1000);
	return (ms_time);
}

int	ft_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		i++;
	}
	return (0);
}

long	ft_atol(char *str)
{
	int		i;
	long	res;

	res = 0;
	i = 0;
	while (str[i])
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res);
}

void	print_state(t_philo *philo, int state)
{
	long	time;
	long	id;

	id = philo->id;
	time = ms_time_get() - philo->data->start;
	if (state == 6)
		printf("%ld %ld died\n", time, id);
	if (end_table(philo->data))
		return ;
	if (state == 1)
		printf("%ld %ld is eating\n", time, id);
	if (state == 2)
		printf("%ld %ld is sleeping\n", time, id);
	if (state == 3)
		printf("%ld %ld is thinking\n", time, id);
	if (state == 4)
		printf("%ld %ld has taken a fork\n", time, id);
	if (state == 5)
		printf("%ld %ld has put down a fork\n", time, id);
}
