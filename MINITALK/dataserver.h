/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dataserver.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:14:32 by agomez-m          #+#    #+#             */
/*   Updated: 2023/12/11 17:17:13 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATASERVER_H
# define DATASERVER_H
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "Libft/libft.h"

typedef struct s_server_data
{
	int				i;
	pid_t			client_pid;
	unsigned char	c;
}				t_server_data;

#endif