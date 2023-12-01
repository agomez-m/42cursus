/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6threefive.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:55:51 by agomez-m          #+#    #+#             */
/*   Updated: 2023/11/28 13:03:28 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"  

bool	ft_sorted(t_node *stack)
{
	if (NULL == stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static t_node	*find_highest(t_node *stack)
{
	int			highest;
	t_node		*highest_node;

	if (NULL == stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void ft_three(t_node **a)
{
	t_node	*bigger;
	
	bigger = find_highest(*a); 
	if (*a == bigger)
		ra(a, false);
	else if ((*a)->next == bigger)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
	
}

void	ft_five(t_node **a, t_node **b)
{
	while (stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a, false);
	}
}
