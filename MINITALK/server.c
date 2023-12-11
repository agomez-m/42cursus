/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:30:18 by agomez-m          #+#    #+#             */
/*   Updated: 2023/12/11 17:19:45 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dataserver.h"

static void	action(int sig, siginfo_t *info, void *context)
{
	static t_server_data	server_data = {0};

	(void)context;
	if (!server_data.client_pid)
		server_data.client_pid = info->si_pid;
	server_data.c |= (sig == SIGUSR2);
	if (++server_data.i == 8)
	{
		server_data.i = 0;
		if (!server_data.c)
		{
			kill(server_data.client_pid, SIGUSR2);
			server_data.client_pid = 0;
			write(1, "\n", 1);
			return ;
		}
		ft_putchar_fd(server_data.c, 1);
		server_data.c = 0;
		kill(server_data.client_pid, SIGUSR1);
	}
	else
		server_data.c <<= 1;
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s_sigaction.sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
