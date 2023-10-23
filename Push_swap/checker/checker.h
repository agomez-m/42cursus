/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:04:06 by agomez-m          #+#    #+#             */
/*   Updated: 2023/10/23 18:15:59 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define BUFFER_SIZE 4
# include <fcntl.h>
# include "../push_swap/push_swap.h"

/*
 * Linked list for get next line
*/
typedef struct sc_list
{
	char			*str_buf;
	struct sc_list	*next;
}				tc_list;

//*** Get next line utlis ***
int				found_newline(tc_list *list);
tc_list			*find_last_node(tc_list *list);
char			*get_line(tc_list *list);
void			copy_str(tc_list *list, char *str);
int				len_to_newline(tc_list *list);
void			polish_list(tc_list **list);
char			*get_next_line(int fd);
void			dealloc(tc_list **list, tc_list *clean_node, char *buf);
void			create_list(tc_list **list, int fd);

#endif