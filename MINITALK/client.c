/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:30:13 by agomez-m          #+#    #+#             */
/*   Updated: 2023/12/11 17:18:28 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dataserver.h"

static void	sigcounter(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_putnbr_fd(received, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

static void	my_kill(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	ft_putstr_fd("Client Sent    : ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Server Received: ", 1);
	signal(SIGUSR1, sigcounter);
	signal(SIGUSR2, sigcounter);
	my_kill(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
