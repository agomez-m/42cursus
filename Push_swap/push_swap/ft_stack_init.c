/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:01:33 by agomez-m          #+#    #+#             */
/*   Updated: 2023/10/23 18:37:03 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	long	ft_atol(const char *str)
{
	long	num;
	int		isneg;
	int		i;

	num = 0;
	isneg = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if ('-' == str[i] || '+' == str[i])
	{
		if ('-' == str[i])
			isneg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * isneg);
}

void	ft_stack_init(t_stack **a, char **argv, bool flag_argc_2)
{
	long	nbr;
	int		i;
	
	i = 0;
	while (argv[i])
	{
		if (ft_error_syntax(argv[i]))
			ft_error_free(a, argv, flag_argc_2);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_error_free(a, argv, flag_argc_2);
		if (ft_error_repetition (*a, (int)nbr))
			ft_error_free(a, argv, flag_argc_2);
		ft_append_node(a, (int)nbr);
		i++;
	}
	if (flag_argc_2)
		ft_free_matrix(argv);
}
/*
#include <stdio.h>
int main ()
{
	t_stack		*a;
	a = NULL;
	printf("a = %p\n", a);
	
	char *v[5] = {v[0] = "\0", v[1] = "2", v[2] = "30", v[3] = "400", v[4] = NULL};
	ft_stack_init(&a, v+1, false);
	printf("a = %p\n", a);
	while (a)
	{
		printf("a->data = %d\n with node adress %p\n", a->value, a);
		a = a->next;
	}
}*/