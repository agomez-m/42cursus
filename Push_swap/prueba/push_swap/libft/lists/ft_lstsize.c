/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:44:35 by alaparic          #+#    #+#             */
/*   Updated: 2023/02/22 18:05:05 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 1;
	if (lst)
	{
		while (lst->next != 0)
		{
			lst = lst->next;
			len++;
		}
		return (len);
	}
	return (0);
}
