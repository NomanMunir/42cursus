/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:02:53 by nmunir            #+#    #+#             */
/*   Updated: 2024/02/08 13:46:37 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_wp = nullptr;
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
	if (this->_wp != nullptr)
	{
		std::cout << this->_name << " attacks with their " << this->_wp->getType();
		std::cout << std::endl;
	}
	else
	{
		std::cout << this->_name << " No weapon to attack found.";
		std::cout << std::endl;
	}
}

void HumanB::setWeapon(Weapon& wp)
{
	this->_wp = &wp;
}

