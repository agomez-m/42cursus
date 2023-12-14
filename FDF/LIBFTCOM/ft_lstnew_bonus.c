/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:19:58 by agomez-m          #+#    #+#             */
/*   Updated: 2023/12/14 14:07:08 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list1	*ft_lstnew(void *content)
{
	t_list1	*new;

	new = (t_list1 *)malloc(sizeof(t_list1));
	if (!(new))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/* crea un nuevo elemento de la lista
con el argumento pasado como contenido*/
