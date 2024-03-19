/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:03:24 by nmunir            #+#    #+#             */
/*   Updated: 2024/03/12 17:08:10 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap a("Nauman");
	FragTrap b;
	b = a;
	b.attack("Hanan");
	a.takeDamage(10);
	a.beRepaired(11);
	a.highFivesGuys();
	return (0);
}
