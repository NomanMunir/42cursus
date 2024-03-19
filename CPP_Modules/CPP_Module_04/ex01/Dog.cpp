/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:27:33 by nmunir            #+#    #+#             */
/*   Updated: 2024/03/18 15:11:54 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << "Dog default constructor called!" << std::endl;
	_brain = new Brain();

}

Dog::~Dog()
{
	std::cout << "Dog destructor called!" << std::endl;
	delete _brain;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called!" << std::endl;
	_brain = new Brain();
	*this = other;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog assignment operator called!" << std::endl;
	if (this != &rhs)
	{
		if (_brain)
		{
			delete _brain;
			_brain = NULL;
		}
		this->_type = rhs._type;
		_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << _type << " is saying WOOF WOOF!" << std::endl;
}
