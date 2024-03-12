/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:11:20 by nmunir            #+#    #+#             */
/*   Updated: 2024/02/08 18:09:09 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **arg)
{
	if (ac != 2)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return (1);
	}
	Harl h;
	h.complain(arg[1]);
	return (0);
}
