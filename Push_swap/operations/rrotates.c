/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotates.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:32:24 by nmunir            #+#    #+#             */
/*   Updated: 2023/09/22 21:32:43 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !stack || lstsize(*stack) == 1)
		return ;
	last = lastnode(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack **a, int flag)
{
	reverse_rotate(a);
	if (flag)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **b, int flag)
{
	reverse_rotate(b);
	if (flag)
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack **a, t_stack **b, int flag)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (flag)
		ft_putendl_fd("rrr", 1);
}
