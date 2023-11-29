/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:58:58 by agomez-m          #+#    #+#             */
/*   Updated: 2023/11/28 14:19:21 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_node
{
	int					value;
	int					current_position;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_node		*target_node;
	struct s_node		*next;
	struct s_node		*prev;
}				t_node;

char			**ft_split(char *str, char separator);

void			ft_free_matrix(char **argv);
void			ft_error_free(t_node **a, char **argv, bool flag_argc_2);
int				ft_error_repetition(t_node *a, int nbr);
int				ft_error_syntax(char *str_nbr);
void			ft_free_stack(t_node **stack);

void			ft_stack_init(t_node **a, char **argv, bool flag_argc_2);
void			init_nodes(t_node *a, t_node *b);
void			set_current_position(t_node *stack);
void			set_price(t_node *a, t_node *b);
void			set_cheapest(t_node *b);

void			ft_append_node(t_node **stack, int nbr);
t_node			*ft_find_last_node(t_node *head);
t_node			*find_smallest(t_node *stack);
t_node			*return_cheapest(t_node *stack);
bool			ft_sorted(t_node *stack);
int				stack_len(t_node *stack);
void			finish_rotation(t_node **s, t_node *n, char c);

void			ft_three(t_node **a);
void			ft_five(t_node **a, t_node **b);
void			push_swap(t_node **a, t_node **b);

void			sa(t_node **a, bool checker);
void			sb(t_node **b, bool checker);
void			ss(t_node **a, t_node **b, bool checker);
void			ra(t_node **a, bool checker);
void			rb(t_node **b, bool checker);
void			rr(t_node **a, t_node **b, bool checker);
void			rra(t_node **a, bool checker);
void			rrb(t_node **b, bool checker);
void			rrr(t_node **a, t_node **b, bool checker);
void			pa(t_node **a, t_node **b, bool checker);
void			pb(t_node **b, t_node **a, bool checker);

#endif