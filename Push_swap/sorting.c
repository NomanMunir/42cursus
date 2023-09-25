/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:40:28 by nmunir            #+#    #+#             */
/*   Updated: 2023/09/22 21:41:12 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stack **stk)
{
	t_stack	*max_node;

	max_node = max(*stk);
	if (sorted(*stk))
		return ;
	max_node = max(*stk);
	if (*stk == max_node)
		ra(stk, 1);
	else if ((*stk)->next == max_node)
		rra(stk, 1);
	if ((*stk)->value > (*stk)->next->value)
		sa(stk, 1);
}

void	ft_sort_5(t_stack **stk_a, t_stack **stk_b)
{
	while (lstsize(*stk_a) > 3)
	{
		init_nodes(*stk_a, *stk_b);
		finish_rotations(stk_a, min(*stk_a), 'a');
		pb(stk_b, stk_a, 1);
	}
}
