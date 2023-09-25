/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:59:52 by nmunir            #+#    #+#             */
/*   Updated: 2023/09/22 21:42:47 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib/libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				final_index;
	int				push_price;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

char				**check_arg(char **av);
void				error_handling(void);
void				ft_free(char **str);
void				ft_free_nodes(t_stack **stk);
void				init_stack(char **args, t_stack **stk_a);
bool				sorted(t_stack *stk);
long				ft_atol(const char *str, int *error);
void				sa(t_stack **stack_a, int flag);
void				sb(t_stack **stack_b, int flag);
void				ss(t_stack **stack_a, t_stack **stack_b, int flag);
void				rb(t_stack **stack_b, int flag);
void				ra(t_stack **stack_a, int flag);
void				pa(t_stack **stack_a, t_stack **stack_b, int flag);
void				pb(t_stack **stack_a, t_stack **stack_b, int flag);
void				rr(t_stack **stack_a, t_stack **stack_b, int flag);
void				rra(t_stack **stack_a, int flag);
void				rrb(t_stack **stack_b, int flag);
void				rrr(t_stack **stack_a, t_stack **stack_b, int flag);
t_stack				*min(t_stack *stack);
t_stack				*max(t_stack *stack);
void				ft_sort_3(t_stack **stk);
void				ft_sort_5(t_stack **stk_a, t_stack **stk_b);
void				finish_rotations(t_stack **stk, t_stack *top,
						char stack_name);
int					lstsize(t_stack *stack);
t_stack				*lastnode(t_stack *stack);
void				init_nodes(t_stack *stk_a, t_stack *stk_b);
void				push_swap(t_stack **stk_a, t_stack **stk_b);
void				set_nodes_position(t_stack *stk);
void				set_cheapest(t_stack *stk_b);
void				set_price(t_stack *stk_a, t_stack *stk_b);
void				set_target(t_stack *stk_a, t_stack *stk_b);
void				move_nodes(t_stack **stk_a, t_stack **stk_b);
t_stack				*return_cheapest(t_stack *stack);

#endif