/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:40:08 by agomez-m          #+#    #+#             */
/*   Updated: 2024/02/21 17:10:10 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	grab_fork(t_philo *p)
{
	if (sem_wait(p->d->sem_forks) == 0)
	{
		if (printstate(p, FORK, now(p)) == 1)
			return (1);
	}
	else
	{
		printf("Error: sem_wait (forks)\n");
		return (1);
	}
	return (0);
}

int	drop_fork(t_philo *p)
{
	if (sem_post(p->d->sem_forks) != 0)
	{
		printf("Error: sem_post (fork)\n");
		return (1);
	}
	return (0);
}

int	ft_eat(t_philo *p)
{
	if (sem_wait(p->d->sem_death) == 0)
	{
		p->t0 = now(p);
		if (sem_post(p->d->sem_death) != 0)
		{
			printf("Error: sem_post (sem_death)\n");
			return (1);
		}
	}
	else
	{
		printf("Error: sem_wait (sem_death)\n");
		return (1);
	}
	printstate(p, EATING, now(p));
	usleep(ft_min(p->d->t_eat, p->d->t_die));
	p->t0 = now(p);
	if (drop_fork(p) == 1 || drop_fork(p) == 1)
		return (1);
	if (p->d->cap != NULL && ++p->meals == *p->d->cap)
		sem_post(p->d->sem_end);
	return (0);
}