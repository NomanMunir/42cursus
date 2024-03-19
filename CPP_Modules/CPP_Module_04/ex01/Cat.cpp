/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:22:01 by nmunir            #+#    #+#             */
/*   Updated: 2024/03/18 15:18:48 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called!" << std::endl;
	_brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat destructor called!" << std::endl;
	delete _brain;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called!" << std::endl;
	_brain = new Brain();
	*this = other;
}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "Cat assignment operator called!" << std::endl;
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

void Cat::makeSound() const
{
	std::cout << _type << " is saying Meow Meow!" << std::endl;
}
