/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:03:11 by codespace         #+#    #+#             */
/*   Updated: 2023/09/25 13:43:16 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../lib/get_next_line/get_next_line.h"
# include "../push_swap.h"

void	validate_command(char *line, t_stack **a, t_stack **b);
void	ft_input(t_stack **a, t_stack **b);

#endif