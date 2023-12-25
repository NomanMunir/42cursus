/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:33:57 by nmunir            #+#    #+#             */
/*   Updated: 2023/11/26 18:46:45 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_strjoin_3(char const *s1, char const *s2, char const *s3)
{
	int		i;
	int		j;
	char	*new;

	j = -1;
	if (s1 == NULL || s2 == NULL || s3 == NULL)
		return (NULL);
	new = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3)
				+ 1));
	if (new == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		new[i] = s1[i];
	while (s2[++j] != '\0')
		new[i++] = s2[j];
	j = -1;
	while (s3[++j] != '\0')
		new[i++] = s3[j];
	new[i] = '\0';
	return (new);
}

static int	is_digit(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

long long	my_atoll(const char *str, int *error)
{
	long long	result;
	int			nagetive;

	result = 0;
	nagetive = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (ft_strncmp(str, "-9223372036854775808", 21) == 0)
		return (-9223372036854775807 - 1);
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			nagetive = -1;
	if (!is_digit(str))
	{
		*error = 1;
		return (0);
	}
	while (*str)
		result = result * 10 + (*str++ - '0');
	if (result < 0)
		*error = 1;
	return (result * nagetive);
}

int	ft_lstsize(t_env *env)
{
	int	i;

	i = 0;
	while (env)
	{
		i++;
		env = env->next;
	}
	return (i);
}
