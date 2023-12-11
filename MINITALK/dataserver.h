/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dataserver.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:14:32 by agomez-m          #+#    #+#             */
/*   Updated: 2023/12/11 20:46:14 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATASERVER_H
# define DATASERVER_H
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_server_data
{
	int				i;
	pid_t			client_pid;
	unsigned char	c;
}				t_server_data;

size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);

#endif