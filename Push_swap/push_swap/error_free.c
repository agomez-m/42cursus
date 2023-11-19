/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:23:04 by agomez-m          #+#    #+#             */
/*   Updated: 2023/11/05 18:21:52 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error_syntax(char *str_nbr)
{
	if (!(*str_nbr == '+'
			|| *str_nbr == '-'
			|| (*str_nbr >= '0' && *str_nbr <= '9')))
		return (1);
	if ((*str_nbr == '+'
			|| *str_nbr == '-')
		&& !(str_nbr[1] >= '0' && str_nbr[1] <= '9'))
		return (1);
	while (*++str_nbr)
	{
		if (!(*str_nbr >= '0' && *str_nbr <= '9'))
			return (1);
	}
	return (0);
}

void	ft_free_matrix(char **argv)
{
	int	i;

	i = -1;
	if (NULL == argv || NULL == *argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv -1);
}

/*-1 se hace para asegurar que todos los elementos de la matriz 
argv se liberen , incluyendo el último elemento, que es NULL.
 Si comenzáramos desde 0, no liberaríamos NULL, ya que el bucle while se 
 detendría cuando llegara a NULL.*/

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*act;

	if (NULL == stack)
		return ;
	act = *stack;
	while (act)
	{
		tmp = act->next;
		free(act);
		act = tmp;
	}
	*stack = NULL;
}

void	ft_error_free(t_stack **a, char **argv, bool flag_argc_2)
{
	ft_free_stack(a);
	if (flag_argc_2)
		ft_free_matrix(argv);
	write(2, "Error\n", 6);
	exit(1);
}

int		ft_error_repetition(t_stack *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}