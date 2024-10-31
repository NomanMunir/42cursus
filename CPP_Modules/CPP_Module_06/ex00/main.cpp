/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:01:10 by nmunir            #+#    #+#             */
/*   Updated: 2024/04/04 11:58:21 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int ac, char **av)
{
	if (ac == 2)
		ScalarConverter::convert(av[1]);
	else
		std::cout << "./cast <input>" << std::endl;
	return (0);
}
