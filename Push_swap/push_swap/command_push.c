/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:07:11 by agomez-m          #+#    #+#             */
/*   Updated: 2023/11/28 18:24:33 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **dest, t_node **src)
{
	t_node	*topush;

	if (*src == NULL)
		return ;
	topush = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	topush->prev = NULL;
	if (*dest == NULL)
	{
		*dest = topush;
		topush->next = NULL;
	}
	else
	{
		topush->next = *dest;
		topush->next->prev = topush;
		*dest = topush;
	}
}

void	pa(t_node **a, t_node **b, bool checker)
{
	push(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_node **b, t_node **a, bool checker)
{
	push(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}