/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:21:24 by agomez-m          #+#    #+#             */
/*   Updated: 2023/12/13 18:15:19 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list1 **lst, t_list1 *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/* agrega un elemento al principio de la lista */