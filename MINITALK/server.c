/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:30:18 by agomez-m          #+#    #+#             */
/*   Updated: 2023/12/11 23:46:21 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dataserver.h"

void	init_sig(int sig, void (*handler)(int, siginfo_t *, void *))
{
	struct sigaction	susr;

	susr.sa_sigaction = handler;
	susr.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
	sigemptyset(&susr.sa_mask);
	if (sig == SIGUSR1)
		sigaction(SIGUSR1, &susr, 0);
	else if (sig == SIGUSR2)
		sigaction(SIGUSR2, &susr, 0);
}

void	user_signal(int sig, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bit = -1;

	(void)context;
	if (kill(info->si_pid, 0) < 0)
	{
		write(1, "ERROR : cant send sig to pid ", 29);
		exit(EXIT_FAILURE);
	}
	if (bit < 0 && !c)
		write(1, "\nClient say : ", 14);
	if (bit < 0)
		bit = __CHAR_BIT__ * sizeof(c) - 1;
	if (sig == SIGUSR1)
		c |= 1 << bit;
	else if (sig == SIGUSR2)
		c &= ~(1 << bit);
	if (!bit && c)
		ft_putchar_fd(c, 1);
	else if (!bit && !c)
		kill(info->si_pid, SIGUSR2);
	bit--;
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	init_sig(SIGUSR1, &user_signal);
	init_sig(SIGUSR2, &user_signal);
	write(1, "Server PID: ", 12);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		sleep(1);
	return (0);
}

/*
susr.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
- utiliza siginfo_t para obtener información adicional
 sobre la señal, como el ID del proceso que envió 
 la señal (si_pid) y el ID de usuario (si_uid).
-  si se interrumpe la llamada sleep, 
se reiniciará automáticamente 
gracias al uso de SA_RESTART.
- SA_NODEFER permite que las señales se entregue nuevamente 
mientras se están manejando en el manejador 
de señales. Esto evita el bloqueo temporal de las señales.

sigemptyset(&susr.sa_mask);
- inicializa el conjunto de señales bloqueadas
 a vacío, lo que significa que no se bloqueará ninguna señal.
- Esto es importante porque SA_NODEFER no bloquea
 las señales que se están manejando,
 por lo que si se bloquean otras señales,
  podrían interrumpir el manejador de señales.
*/
