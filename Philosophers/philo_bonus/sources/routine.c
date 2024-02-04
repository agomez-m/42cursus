/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:54:35 by agomez-m          #+#    #+#             */
/*   Updated: 2024/02/03 18:21:46 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	set_philo(t_data *data, int id)
{
	char	*sem_name;

	sem_name = ft_strjoin("/philo_", ft_itoa(id));
	if (sem_name == NULL)
		exit(1);
	sem_unlink(sem_name);
	data->philo.sem_philo = sem_open(sem_name, O_CREAT, 0644, 1);
	sem_unlink(sem_name);
	free(sem_name);
	data->philo.id = id;
	data->philo.last_eat_time = data->start_time;
	return (0);
}

bool	stop_if(t_state	state)
{
	if (state == DEAD)
		return (true);
	if (state == FINISH)
		return (true);
	if (state == FULL)
		return (true);
	return (false);
}

void	*ft_routine(t_data *data, int id)
{
	if (set_philo (data, id))
		exit(1);
	if (pthread_create(&data->monitor, NULL, &monitor_death, data))
		exit (1);
	while (true)
	{
		
		if (ft_eat(data) || stop_if(get_philo_state(data)))
		{
			break ;
		}
		if (ft_sleep(data) || stop_if(get_philo_state(data)))
		{
			break ;
		}
		if (ft_think(data) || stop_if(get_philo_state(data)))
		{
			break ;
		}
	}
	if (pthread_join(data->monitor, NULL))
		exit(1);
	sem_close(data->philo.sem_philo);
	exit(0);
}
