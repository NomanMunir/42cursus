/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:32:06 by nmunir            #+#    #+#             */
/*   Updated: 2023/09/24 22:17:41 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*node;

	if (!*src || !src)
		return ;
	node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node->prev = NULL;
	if (!*dest)
	{
		*dest = node;
		node->next = NULL;
	}
	else
	{
		node->next = *dest;
		node->next->prev = node;
		*dest = node;
	}
}

void	pa(t_stack **a, t_stack **b, int flag)
{
	push(a, b);
	if (flag == 1)
		ft_putendl_fd("pa", 1);
}

void	pb(t_stack **b, t_stack **a, int flag)
{
	push(b, a);
	if (flag == 1)
		ft_putendl_fd("pb", 1);
}
