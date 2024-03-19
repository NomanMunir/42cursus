/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:03:24 by nmunir            #+#    #+#             */
/*   Updated: 2024/03/12 17:04:06 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("Nauman");
	ScavTrap b;
	b = a;
	b.attack("Hanan");
	a.takeDamage(10);
	a.beRepaired(11);
	a.guardGate();
	
	return (0);
}
