/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:36:56 by nmunir            #+#    #+#             */
/*   Updated: 2024/02/08 19:25:44 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int i;

	i = -1;
	int hordeSize;

	hordeSize = 5;
	Zombie *z = zombieHorde(hordeSize, "442");
	while (++i < hordeSize)
		z[i].announce();
	delete[] z;
	return (0);
}
