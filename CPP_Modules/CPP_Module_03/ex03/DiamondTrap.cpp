/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:25:40 by nmunir            #+#    #+#             */
/*   Updated: 2024/03/14 10:34:28 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap() 
{
	std::cout << "DiamondTrap default constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string inputName) :  FragTrap(inputName), ScavTrap(inputName), name(inputName)
{
	std::cout << "DiamondTrap name constructor called!" << std::endl;
	ClapTrap::_name = inputName + "_clap_name";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor is called!" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{	
	std::cout << "DiamondTrap copy constructor is called!" << std::endl;
	*this = other;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
	std::cout << "DiamondTrap copy constructor is called!" << std::endl;
	if (this != &rhs)
	{
		this->_hitPoints = rhs._hitPoints;
		this->_attackDamage = rhs._attackDamage;
		this->_energyPoints = rhs._energyPoints;
		this->name = rhs.name;
	}
	return (*this);
}
void DiamondTrap::whoAmI()
{
	std::cout << "My name is " << this->name << " my ClapTrap name is " << ClapTrap::_name << "." << std::endl;
}
