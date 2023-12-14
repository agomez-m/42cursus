/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:35:08 by agomez-m          #+#    #+#             */
/*   Updated: 2023/12/13 18:15:25 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list1 **lst, void (*del)(void *))
{
	t_list1	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

/* elimina y libera la memoria del elementoNODO pasado como     
parámetro y de todos los elementosNODOS siguientes, con ’del’ y free(3).
Por último, el puntero inicial debe pasar a NULL.*/