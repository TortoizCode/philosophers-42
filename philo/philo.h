/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodmorei <rodmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:19:38 by rodmorei          #+#    #+#             */
/*   Updated: 2025/09/18 16:44:47 by rodmorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_philo	t_philo;
typedef struct s_data	t_data;
typedef struct s_fork	t_fork;

struct s_data
{
	long			time_die;
	long			time_eat;
	long			time_sleep;
	long			nb_philo;
	long			nb_must_eat;
	long			nb_running;
	long			start;
	long			full;
	int				end;
	t_philo			*ptr_philos;
	t_fork			*ptr_forks;
	pthread_mutex_t	data_mtx;
	pthread_t		monitor;
};

struct	s_philo
{
	int				id;
	int				is_full;
	pthread_t		ph_thread;
	t_fork			*r_fork;
	t_fork			*l_fork;
	long			last_eat;
	long			nb_meals;
	long			max_meals;
	pthread_mutex_t	ph_mtx;
	t_data			*data;
};

struct	s_fork
{
	int				id;
	pthread_mutex_t	frk_mtx;
};

int		ver_args(int argc, char **argv);
int		send_error(char *err_msg);
int		ft_is_digit(char *str);
long	ft_atol(char *str);
int		init_table(int argc, char **argv, t_data *table);
void	free_table(t_data *table);
int		init_forks(t_data *table);
void	assign_fork(t_philo *philo, t_data	*table);
int		init_philo_list(t_data	*table);
int		start_meal(t_data	*table);
void	*ph_handle(void	*ph);
void	*monitor_handle(void	*data);
int		thread_init(t_data *data);
long	ms_time_get(void);
int		end_table(t_data	*table);
int		check_death(t_philo	*ph);
int		check_full(t_philo *ph);
void	print_state(t_philo *philo, int state);
void	ft_eat(t_philo *philo);
void	ft_think(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	one_philo(t_data *data);
#endif
