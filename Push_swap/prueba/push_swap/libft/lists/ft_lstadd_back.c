/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:53:08 by alaparic          #+#    #+#             */
/*   Updated: 2023/08/03 11:57:58 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == 0)
		*lst = new;
	else
	{
		while ((*lst)->next != 0)
			lst = &(*lst)->next;
		(*lst)->next = new;
	}
}
