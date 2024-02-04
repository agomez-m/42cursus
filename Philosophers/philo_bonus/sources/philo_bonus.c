/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:55:47 by agomez-m          #+#    #+#             */
/*   Updated: 2024/02/02 19:33:16 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	ft_run(t_data *data)
{
	pid_t	p_id;
	int		i;

	i = 0;
	data->start_time = ft_get_time();
	while (i++ < data->nb_philos)
	{
		p_id = fork();
		if (p_id == 0)
		{
			ft_routine(data, i);
		}
		else if (p_id == -1)
		{
			printf("Error: Fork error\n");
			return (1);
		}
	}
	p_id = waitpid(0, NULL, 0);
	while (p_id != -1)
		p_id = waitpid(0, NULL, 0);
	return (0);
}

int	ft_philobonus(int argc, char **argv)
{
	t_data	data;

	if (ft_init_data(&data, argc, argv) != 0)
		return (1);
	ft_run(&data);
	sem_close(data.sem_forks);
	sem_close(data.sem_print);
	return (0);
}

int	main(int argc, char **argv)
{
	if (ft_check_args(argc, argv) == 1)
		return (1);
	ft_philobonus(argc, argv);
	return (0);
}
