/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:38:40 by agomez-m          #+#    #+#             */
/*   Updated: 2023/12/13 18:16:02 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list1	*ft_lstmap(t_list1 *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list1	*new_list;
	t_list1	*new_node;
	void	*set;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		set = f(lst->content);
		new_node = ft_lstnew(set);
		if (!new_node)
		{
			del(set);
			ft_lstclear(&new_list, (*del));
			return (new_list);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/* Itera la lista ’lst’ y aplica la función ’f’ al contenido de cada 
elementoNODO.
Crea una nueva lista que resulta de las aplicaciones sucesivas de la función ’f’.
La función ’del’ se usa para borrar el contenido de un elementoNODO si es
necesario. */
