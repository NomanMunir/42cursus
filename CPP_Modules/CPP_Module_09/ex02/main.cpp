/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:24:37 by nmunir            #+#    #+#             */
/*   Updated: 2024/06/02 16:08:28 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, const char **av)
{
	if (ac < 2)
	{
		std::cout << "No Input\nUsage: ./PmergeMe < numbers >" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe a = PmergeMe(av);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	return (0);
}