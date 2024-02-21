/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:54:35 by agomez-m          #+#    #+#             */
/*   Updated: 2024/02/21 16:32:24 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	nap(t_philo *p)
{
	if (printstate(p, SLEEPING, now(p)) == 1)
		return (1);
	usleep(p->d->t_sleep);
	return (0);
}

int	think(t_philo *p)
{
	if (printstate(p, THINKING, now(p)) == 1)
		return (1);
	usleep(p->d->t_think);
	return (0);
}

int	philo_routine(t_philo *p)
{
	set_time(p);
	while (1)
	{
		if (p->d->n_philo < 2)
			continue ;
		sem_wait(p->d->sem_go);
		if (grab_fork(p) == 0 && grab_fork(p) == 0)
		{
			sem_post(p->d->sem_go);
			if (eat(p) == 1 || nap(p) == 1 || think(p) == 1)
				endr(p);
		}
		else
			endr(p);
	}
	return (0);
}
