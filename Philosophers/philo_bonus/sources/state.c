/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:09:41 by agomez-m          #+#    #+#             */
/*   Updated: 2024/02/04 18:00:05 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

bool	someone_died(void)
{
	sem_t	*death;

	death = sem_open("/death", AT_EACCESS, 0);
	if (death == SEM_FAILED)
		return (false);
	sem_close(death);
	return (true);
}

/*	la funcion comprueba si el semaforo "/death" existe y si el usuario tiene 
	permiso para acceder a el (leer/escribir)
	0: abrir para leer/escribir (O_RDWR)
	0: permisos (ignorados ya que el semaforo ya existe)
	// AT_EACCESS: check if semaphore exists and user has permission 
		to access it (read/write)
	// 0: open for read/write access (O_RDWR) 
	// 0: permissions (ignored since semaphore already exists)
*/

bool	philo_died(t_data *data)
{
	if (data->philo.state != EATING
		&& ft_get_time() - data->philo.last_eat_time > data->die_time)
		return (true);
	return (false);
}

void	*monitor_death(void *data_p)
{
	t_data	*data;

	data = (t_data *)data_p;
	while (stop_if(data->philo.state) == false)
	{
		if (someone_died())
			return (data->philo.state = FINISH, NULL);
		if (philo_died(data))
		{
			sem_wait(data->sem_print);
			if (philo_died(data) && someone_died() == false)
			{
				data->philo.state = DEAD;
				sem_open("/death", O_CREAT, 0644, 0);
				printf("%llu %d %s\n", ft_get_time() - data->start_time,
					data->philo.id, DIED);
				sem_post(data->sem_print);
				return (NULL);
			}
			sem_post(data->sem_print);
		}
	}
	return (NULL);
}

/*
sem_open("/death", O_CREAT, 0644, 0); sirve para avisar a los demas hilos
de que uno de ellos ha muerto
*/