/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:05:02 by alaparic          #+#    #+#             */
/*   Updated: 2023/06/26 14:50:33 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_new(t_list **list, void *context)
{
	t_list	*new_node;

	new_node = ft_lstnew(context);
	if (!*list)
		*list = new_node;
	else
		ft_lstadd_back(list, new_node);
}
