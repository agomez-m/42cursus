/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:26:40 by agomez-m          #+#    #+#             */
/*   Updated: 2023/10/23 16:37:49 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_stack **stack)
{
    t_stack *torot;

    if (*stack == NULL || stack == NULL)
        return ;
    torot = ft_find_last_node(*stack);
    torot->next = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    torot->next->prev = torot;
    torot->next->next = NULL;
}

void	ra(t_stack **a, bool checker)
{
	rotate(a);
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, bool checker)
{
	rotate(b);
	if (!checker)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		write(1, "rr\n", 3);
}