/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:58:28 by abashir           #+#    #+#             */
/*   Updated: 2023/11/28 12:24:00 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	skip_char_token(char **str, char *es, char c)
{
	while (*str < es && **str != c)
		(*str)++;
	if (**str != c)
		ft_put_error("syntax error", "unclosed quote", *str);
}

void	skip_spaces(char **s, char *es)
{
	while (*s < es && ft_strchr(" \t\r\n\v", **s))
		(*s)++;
}
