/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:03:24 by nmunir            #+#    #+#             */
/*   Updated: 2024/03/12 16:57:30 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Nauman");
	ClapTrap b = a;
	b.attack("Hanan");
	a.takeDamage(10);
	a.beRepaired(11);
	return (0);
}
