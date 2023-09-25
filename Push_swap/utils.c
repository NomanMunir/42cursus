/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:43:01 by nmunir            #+#    #+#             */
/*   Updated: 2023/09/22 21:44:02 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstsize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

t_stack	*max(t_stack *stack)
{
	int		max;
	t_stack	*max_node;

	max = INT_MIN;
	max_node = NULL;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack	*min(t_stack *stack)
{
	long	smallest;
	t_stack	*smallest_node;

	if (NULL == stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

bool	sorted(t_stack *stk)
{
	while (stk->next)
	{
		if (stk->value > stk->next->value)
			return (false);
		stk = stk->next;
	}
	return (true);
}

long	ft_atol(const char *str, int *error)
{
	long long	result;
	int			nagetive;

	result = 0;
	nagetive = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			nagetive = -1;
	}
	while (ft_isdigit(*str))
	{
		if (nagetive && ((result * 10) + *str - '0') < result)
			*error = 1;
		else if (!nagetive && ((result * 10) + *str - '0') < result)
			*error = 1;
		result = result * 10 + (*str++ - '0');
	}
	return (result * nagetive);
}
