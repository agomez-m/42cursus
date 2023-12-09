/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:02:03 by agomez-m          #+#    #+#             */
/*   Updated: 2023/12/09 12:26:02 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static int	ft_strcmp(char *str_1, char *str_2)
{
	while (*str_1 == *str_2
		&& *str_1)
	{
		++str_1;
		++str_2;
	}
	return (*str_1 - *str_2);
}

static void	error(t_node **a, t_node **b)
{
	ft_free_stack(a);
	ft_free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

static void	parse_command(t_node **a, t_node **b, char *command)
{
	if (!ft_strcmp(command, "pa\n"))
		pa(a, b, true);
	else if (!ft_strcmp(command, "pb\n"))
		pb(b, a, true);
	else if (!ft_strcmp(command, "sa\n"))
		sa(a, true);
	else if (!ft_strcmp(command, "sb\n"))
		sb(b, true);
	else if (!ft_strcmp(command, "ss\n"))
		ss(a, b, true);
	else if (!ft_strcmp(command, "ra\n"))
		ra(a, true);
	else if (!ft_strcmp(command, "rb\n"))
		rb(b, true);
	else if (!ft_strcmp(command, "rr\n"))
		rr(a, b, true);
	else if (!ft_strcmp(command, "rra\n"))
		rra(a, true);
	else if (!ft_strcmp(command, "rrb\n"))
		rrb(b, true);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(a, b, true);
	else
		error(a, b);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	*next_line;
	int		len;

	a = NULL;
	b = NULL;
	if (1 == argc)
		return (0);
	else if (2 == argc)
		argv = ft_split(argv[1], 32);
	ft_stack_init(&a, argv + 1, 2 == argc);
	len = stack_len(a);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line && ft_strcmp(next_line, "\n"))
	{
		parse_command(&a, &b, next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	if (ft_sorted(a) && len == stack_len(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(a);
}
