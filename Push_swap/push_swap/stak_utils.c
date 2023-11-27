/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stak_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:55:48 by agomez-m          #+#    #+#             */
/*   Updated: 2023/11/26 20:12:23 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_find_last_node(t_node *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	ft_append_node(t_node **stack, int nbr)
{
	t_node	*node;
	t_node	*last_node;

	if (NULL == stack)
		return ;
	node = malloc(sizeof(t_node));
	if (NULL == node)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (NULL == *stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

t_node	*find_smallest(t_node *stack)
{
	long		smallest;
	t_node		*smallest_node;

	if (NULL == stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

/*
 * Return the cheapest node 
 * that is already flagged
*/
t_node	*return_cheapest(t_node *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	stack_len(t_node *stack)
{
	int	count;

	if (NULL == stack)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}