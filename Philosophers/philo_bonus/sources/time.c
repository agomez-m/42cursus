/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:04:12 by agomez-m          #+#    #+#             */
/*   Updated: 2024/02/21 16:34:44 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	set_time(t_philo *p)
{
	if (sem_wait(p->d->sem_time) == 0)
	{
		if (gettimeofday(&p->t, NULL) == -1)
		{
			printf("Error: gettimeofday\n");
			return (1);
		}
		if (sem_post(p->d->sem_time) != 0)
			printf("Error: sem_post (time)\n");
	}
	return (0);
}

struct timeval	now(t_philo *p)
{
	struct timeval	now;

	ft_bzero(&now, sizeof(struct timeval));
	if (sem_wait(p->d->sem_time) == 0)
	{
		now = p->t;
		if (sem_post(p->d->sem_time) != 0)
			printf("Error: sem_post (time)\n");
	}
	return (now);
}

long long	utime(struct timeval t)
{
	return (t.tv_sec * 1000000 + t.tv_usec);
}

long long	deltatime(struct timeval t0, struct timeval t1)
{
	return ((utime(t1) - utime(t0)) / 1000);
}
