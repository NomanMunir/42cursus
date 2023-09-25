/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:58:38 by nmunir            #+#    #+#             */
/*   Updated: 2023/09/25 13:26:27 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (exit(0), 0);
	init_stack(check_arg(av), &a);
	if (sorted(a))
		return (ft_free_nodes(&a), 0);
	if (lstsize(a) == 2)
		sa(&a, 1);
	else if (lstsize(a) == 3)
		ft_sort_3(&a);
	else
		push_swap(&a, &b);
	ft_free_nodes(&a);
	return (0);
}
