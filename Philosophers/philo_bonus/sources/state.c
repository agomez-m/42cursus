/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:09:41 by agomez-m          #+#    #+#             */
/*   Updated: 2024/02/21 16:34:26 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	set_offset(t_philo *p)
{
	int		i;
	t_philo	*tmp;

	if (gettimeofday(&p->d->offset, NULL) == -1)
	{
		printf("Error: gettimeofday\n");
		return (1);
	}
	i = p->d->n_philo;
	tmp = p;
	while (i--)
	{
		tmp->t0 = p->d->offset;
		tmp = tmp->next;
	}
	return (0);
}

int	deathcheck(t_philo *p)
{
	if (sem_wait(p->d->sem_death) == 0)
	{
		if (set_time(p) == 0)
		{
			if (utime(p->t) - utime(p->t0) > p->d->t_die)
			{
				printstate(p, 4, p->t);
				endr(p);
				return (0);
			}
		}
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
	return (0);
}

int	printstate(t_philo *p, int state, struct timeval t)
{
	if (sem_wait(p->d->sem_print) == 0)
	{
		if (state == FORK)
			printf("%lld %d has taken a fork\n", \
				deltatime(p->d->offset, t), p->id);
		else if (state == EATING)
			printf("%lld %d is eating\n", deltatime(p->d->offset, t), p->id);
		else if (state == SLEEPING)
			printf("%lld %d is sleeping\n", deltatime(p->d->offset, t), p->id);
		else if (state == THINKING)
			printf("%lld %d is thinking\n", deltatime(p->d->offset, t), p->id);
		else if (state == DEAD)
			printf("%lld %d died\n", deltatime(p->d->offset, t), p->id);
		if (sem_post(p->d->sem_print) != 0)
		{
			printf("Error: sem_post (sem_print)\n");
			return (1);
		}
	}
	else
	{
		printf("Error: sem_wait (sem_print)\n");
		return (1);
	}
	return (0);
}

void	*bigbrother(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (1)
	{
		if (deathcheck(p) != 0)
			return (NULL);
	}
	return (0);
}
