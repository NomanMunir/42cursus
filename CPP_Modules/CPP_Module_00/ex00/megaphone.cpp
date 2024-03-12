/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 09:47:55 by nmunir            #+#    #+#             */
/*   Updated: 2024/02/07 13:17:47 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void to_uper(char *str)
{
	if (!str)
		return;
	while (*str)
	{
		*str = toupper((int) *str);
		str++;
	}	
}

int	main(int ac, char **av)
{
	if (ac == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
	av++;
	if (av)
	{
		while (*av)
		{
			to_uper(*av);
			std::cout << *av;
			av++;
		}
		std::cout << std::endl;
	}
	return (0);
}
