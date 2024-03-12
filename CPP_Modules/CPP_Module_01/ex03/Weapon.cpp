/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:41:55 by nmunir            #+#    #+#             */
/*   Updated: 2024/02/08 13:25:10 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string newType)
{
	this->type = newType;
}

Weapon::~Weapon()
{

}

const std::string& Weapon::getType()
{
	return (this->type);
}

void Weapon::setType(std::string newType)
{
	this->type = newType;
}
