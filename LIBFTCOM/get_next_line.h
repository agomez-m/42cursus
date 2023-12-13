/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:14:36 by agomez-m          #+#    #+#             */
/*   Updated: 2023/09/29 13:21:42 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

/*Nodo de la lista linkeada*/
typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}					t_list;

char		*get_next_line(int fd);
char		*get_line(t_list *list);
void		create_list(t_list **list, int fd);
void		append(t_list **list, char *buf);
void		polish_list(t_list **list);
t_list		*find_last_node(t_list *list);
int			found_new_line(t_list *list);
void		copy_str(t_list *list, char *str);
int			len_to_newline(t_list *list);
void		dealloc(t_list **list, t_list *clean_node, char *buf);

#endif