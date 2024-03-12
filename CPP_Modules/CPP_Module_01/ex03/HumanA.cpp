/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:57:34 by nmunir            #+#    #+#             */
/*   Updated: 2024/02/08 13:40:12 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& wp) : _name(name), _wp(wp)
{
	
}

HumanA::~HumanA()
{
	
}

void HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_wp.getType();
	std::cout << std::endl;
}
