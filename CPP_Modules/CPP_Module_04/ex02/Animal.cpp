/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:17:57 by nmunir            #+#    #+#             */
/*   Updated: 2024/03/18 14:45:45 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("Animal")
{
	std::cout << "Animal default constructor called!" << std::endl;
}

Animal::Animal::Animal(const std::string &type) : _type(type)
{
	std::cout << "Animal type constructor called!" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called!" << std::endl;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal copy constructor called!" << std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal& rhs)
{
	std::cout << "Animal assignment operator called!" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "Some animal is crying!" << std::endl;
}

std::string Animal::getType() const
{
	return (this->_type);
}