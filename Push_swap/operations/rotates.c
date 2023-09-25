/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:32:19 by nmunir            #+#    #+#             */
/*   Updated: 2023/09/24 13:40:20 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (!stack || !*stack || lstsize(*stack) == 1)
		return ;
	last_node = lastnode(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack **a, int flag)
{
	rotate(a);
	if (flag == 1)
		ft_putendl_fd("ra", 1);
}

void	rb(t_stack **b, int flag)
{
	rotate(b);
	if (flag == 1)
		ft_putendl_fd("rb", 1);
}

void	rr(t_stack **a, t_stack **b, int flag)
{
	rotate(a);
	rotate(b);
	if (flag == 1)
		ft_putendl_fd("rr", 1);
}
