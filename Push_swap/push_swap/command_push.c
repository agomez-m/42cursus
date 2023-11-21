/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:07:11 by agomez-m          #+#    #+#             */
/*   Updated: 2023/11/05 16:39:11 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push(t_stack **dest, t_stack **src)
{
	t_stack *topush;

	if (*src == NULL)
		return ;
	topush = *src;
	*src = (*src)->next; /* src apunta al 2 elemento de la lista */
	if (*src)
		(*src)->prev = NULL; /*eliminamos el primer nodo*/
	topush->prev = NULL; 
	if (dest == NULL)
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

void	pa(t_stack **a, t_stack **b, bool checker)
{
	push(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a, bool checker)
{
	push(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}