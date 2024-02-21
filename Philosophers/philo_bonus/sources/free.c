/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:45:04 by agomez-m          #+#    #+#             */
/*   Updated: 2024/02/21 18:28:32 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	datafree(t_data *d)
{
	if (d->cap != NULL)
		free(d->cap);
	free(d);
	return (0);
}

void	ft_philofree(t_philo *p)
{
	t_philo	*tmp;
	t_philo	*next;

	tmp = p;
	next = tmp;
	datafree(p->d);
	if (p != NULL)
	{
		while (tmp->next != NULL && tmp->next != p)
		{
			next = tmp->next;
			free(tmp);
			tmp = next;
		}
		free(tmp);
	}
}

int	semunlinker(void)
{
	if (sem_unlink("forks") != 0 || sem_unlink("print") != 0)
	{
		printf("Error: sem_unlink (forks)\n");
		return (1);
	}
	if (sem_unlink("death") != 0 || sem_unlink("end") != 0)
	{
		printf("Error: sem_unlink (death)\n");
		return (1);
	}
	if (sem_unlink("time") != 0 || sem_unlink("go") != 0)
	{
		printf("Error: sem_unlink (time)\n");
		return (1);
	}
	return (0);
}

int	ft_destroyer(t_data *d)
{
	if (sem_close(d->sem_forks) != 0 || sem_close(d->sem_print) != 0)
	{
		printf("Error: sem_close (forks)\n");
		return (1);
	}
	if (sem_close(d->sem_death) != 0 || sem_close(d->sem_end) != 0)
	{
		printf("Error: sem_close (death)\n");
		return (1);
	}
	if (sem_close(d->sem_time) != 0 || sem_close(d->sem_go) != 0)
	{
		printf("Error: sem_close (time)\n");
		return (1);
	}
	if (semunlinker() == 1)
		return (1);
	return (0);
}
