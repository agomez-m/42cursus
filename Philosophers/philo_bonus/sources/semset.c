/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:49:20 by agomez-m          #+#    #+#             */
/*   Updated: 2024/02/02 19:37:42 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	set_philo_state(t_data *data, t_state state)
{
	sem_wait(data->philo.sem_philo);
	data->philo.state = state;
	sem_post(data->philo.sem_philo);
}

void	update_last_meal_time(t_data *data)
{
	sem_wait(data->philo.sem_philo);
	data->philo.last_eat_time = ft_get_time();
	sem_post(data->philo.sem_philo);
}

int	print_msg(t_data *data, char *msg)
{
	sem_wait(data->sem_print);
	if (someone_died())
	{
		sem_post(data->sem_print);
		return (1);
	}
	printf("%llu %d %s\n", ft_get_time() - data->start_time,
		data->philo.id, msg);
	sem_post(data->sem_print);
	return (0);
}

void	print_sem(t_data *data, char *str)
{
	sem_wait(data->sem_print);
	printf("%s\n", str);
	sem_post(data->sem_print);
}
