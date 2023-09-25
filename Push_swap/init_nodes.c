/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:38:36 by nmunir            #+#    #+#             */
/*   Updated: 2023/09/25 13:19:35 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target(t_stack *stk_a, t_stack *stk_b)
{
	t_stack	*tmp_a;
	t_stack	*target_node;
	long	best_match;

	while (stk_b)
	{
		best_match = LONG_MAX;
		tmp_a = stk_a;
		while (tmp_a)
		{
			if (tmp_a->value > stk_b->value && tmp_a->value < best_match)
			{
				best_match = tmp_a->value;
				target_node = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (best_match == LONG_MAX)
			stk_b->target_node = min(stk_a);
		else
			stk_b->target_node = target_node;
		stk_b = stk_b->next;
	}
}

void	set_price(t_stack *stk_a, t_stack *stk_b)
{
	int	len_a;
	int	len_b;

	len_a = lstsize(stk_a);
	len_b = lstsize(stk_b);
	while (stk_b)
	{
		stk_b->push_price = stk_b->index;
		if (!(stk_b->above_median))
			stk_b->push_price = len_b - (stk_b->index);
		if (stk_b->target_node->above_median)
			stk_b->push_price += stk_b->target_node->index;
		else
			stk_b->push_price += len_a - (stk_b->target_node->index);
		stk_b = stk_b->next;
	}
}

void	set_cheapest(t_stack *stk_b)
{
	long	best_value;
	t_stack	*best_node;

	if (stk_b == NULL)
		return ;
	best_value = INT_MAX;
	best_node = NULL;
	while (stk_b)
	{
		if (stk_b->push_price < best_value)
		{
			best_value = stk_b->push_price;
			best_node = stk_b;
		}
		stk_b = stk_b->next;
	}
	if (best_node)
		best_node->cheapest = true;
}

void	set_nodes_position(t_stack *stk)
{
	int	middle;
	int	i;

	if (!stk)
		return ;
	i = 0;
	middle = lstsize(stk) / 2;
	while (stk)
	{
		stk->cheapest = false;
		stk->index = i;
		if (i <= middle)
			stk->above_median = true;
		else
			stk->above_median = false;
		stk = stk->next;
		i++;
	}
}

void	init_nodes(t_stack *stk_a, t_stack *stk_b)
{
	set_nodes_position(stk_a);
	set_nodes_position(stk_b);
	set_target(stk_a, stk_b);
	set_price(stk_a, stk_b);
	set_cheapest(stk_b);
}
