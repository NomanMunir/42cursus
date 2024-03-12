/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:39:48 by nmunir            #+#    #+#             */
/*   Updated: 2024/02/08 10:37:02 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "Destroyed : " << this->name << std::endl;
}

Zombie *newZombie(std::string name)
{
	Zombie *zom = new Zombie(name);
	return (zom);
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void randomChump(std::string name)
{
	Zombie zob = Zombie(name);
	zob.announce();
}
