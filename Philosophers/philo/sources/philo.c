/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:55:47 by agomez-m          #+#    #+#             */
/*   Updated: 2024/01/29 10:43:57 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_program(int argc, char **argv)
{
	t_data	data;

	if (init_data(&data, argc, argv) != 0)
		return (1);
	init_philos(&data);
	init_forks(&data);
	init_threads(&data);
	join_threads(&data);
	ft_free_data(&data);
	return (0);
}

int	main(int argc, char **argv)
{
	if (check_args(argc, argv) == 1)
		return (1);
	if (init_program(argc, argv) == 1)
	{
		printf("Error: Malloc error\n");
		return (1);
	}
	return (0);
}
