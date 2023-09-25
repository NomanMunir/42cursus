/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:21:14 by nmunir            #+#    #+#             */
/*   Updated: 2023/09/21 17:59:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rr(a, b, 1);
	set_nodes_position(*a);
	set_nodes_position(*b);
}

void	finish_rotations(t_stack **stk, t_stack *top, char stack_name)
{
	while (*stk != top)
	{
		if (stack_name == 'a')
		{
			if (top->above_median)
				ra(stk, 1);
			else
				rra(stk, 1);
		}
		else if (stack_name == 'b')
		{
			if (top->above_median)
				rb(stk, 1);
			else
				rrb(stk, 1);
		}
	}
}

static void	reverse_rotate_both(t_stack **a, t_stack **b,
		t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b, 1);
	set_nodes_position(*a);
	set_nodes_position(*b);
}

void	move_nodes(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*cheapest;

	cheapest = return_cheapest(*stk_b);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(stk_a, stk_b, cheapest);
	else if (!(cheapest->above_median)
		&& !(cheapest->target_node->above_median))
		reverse_rotate_both(stk_a, stk_b, cheapest);
	finish_rotations(stk_b, cheapest, 'b');
	finish_rotations(stk_a, cheapest->target_node, 'a');
	pa(stk_a, stk_b, 1);
}

void	push_swap(t_stack **stk_a, t_stack **stk_b)
{
	int		len;
	t_stack	*smallest;

	len = lstsize(*stk_a);
	if (len == 5)
		ft_sort_5(stk_a, stk_b);
	else
	{
		while (len-- > 3)
			pb(stk_b, stk_a, 1);
	}
	ft_sort_3(stk_a);
	while (*stk_b)
	{
		init_nodes(*stk_a, *stk_b);
		move_nodes(stk_a, stk_b);
	}
	set_nodes_position(*stk_a);
	smallest = min(*stk_a);
	if (smallest->above_median)
		while (*stk_a != smallest)
			ra(stk_a, 1);
	else
		while (*stk_a != smallest)
			rra(stk_a, 1);
}
