/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:36:28 by nmunir            #+#    #+#             */
/*   Updated: 2023/09/24 22:18:57 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handling(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_nodes(t_stack **stk)
{
	t_stack	*tmp;

	tmp = NULL;
	while (*stk)
	{
		tmp = *stk;
		*stk = (*stk)->next;
		free(tmp);
	}
}
