/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:16:34 by nmunir            #+#    #+#             */
/*   Updated: 2024/02/21 18:15:17 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	Point a(0, 1);
	Point b = a;
	std::cout << b.getY().toFloat() << std::endl;
	
	if (bsp(Point(0, 0), Point(0, 2), Point(2, 0), Point(1, 1)))
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	return (0);
}
