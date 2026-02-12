/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodmorei <rodmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:23:58 by rodmorei          #+#    #+#             */
/*   Updated: 2025/09/17 15:54:14 by rodmorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	table;

	memset(&table, 0, (sizeof(t_data)));
	if (ver_args(argc, argv) == -1)
		return (-1);
	if (init_table(argc, argv, &table) == -1)
		return (-1);
	if (table.nb_philo == 1)
		one_philo(&table);
	else if (start_meal(&table) == -1)
		return (-1);
	free_table(&table);
	return (0);
}
