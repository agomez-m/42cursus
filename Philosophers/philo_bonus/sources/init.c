/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:19:55 by agomez-m          #+#    #+#             */
/*   Updated: 2024/02/02 19:41:06 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	ft_init_sem(t_data *data)
{
	sem_unlink("/death");
	sem_unlink("/forks");
	sem_unlink("/print");
	data->sem_forks = sem_open("/forks", O_CREAT, 0644, data->nb_philos);
	data->sem_print = sem_open("/print", O_CREAT, 0644, 1);
	if (data->sem_forks == SEM_FAILED)
	{
		printf("SEM FAILED\n");
		return (1);
	}
	if (data->sem_print == SEM_FAILED)
	{
		printf("SEM FAILED\n");
		return (1);
	}
	sem_unlink("/forks");
	sem_unlink("/print");
	return (0);
}

// es necesario sem_unlink()?

int	ft_init_data(t_data *data, int argc, char **argv)
{
	data->nb_philos = ft_atoi(argv[1]);
	data->die_time = (u_int64_t) ft_atoi(argv[2]);
	data->eat_time = (u_int64_t) ft_atoi(argv[3]);
	data->sleep_time = (u_int64_t) ft_atoi(argv[4]);
	data->nb_meals = -1;
	if (argc == 6)
		data->nb_meals = ft_atoi(argv[5]);
	data->philo.data = data;
	data->philo.nb_meals_had = 0;
	data->philo.state = IDLE;
	return (ft_init_sem(data));
}

