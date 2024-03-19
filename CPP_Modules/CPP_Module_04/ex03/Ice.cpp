/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 10:54:55 by nmunir            #+#    #+#             */
/*   Updated: 2024/03/18 15:50:51 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	// std::cout << "Ice default constructor called!" << std::endl;
}

Ice::Ice(const Ice& other): AMateria(other)
{
	// std::cout << "Ice copy constructor called!" << std::endl;
	*this = other;
}

Ice::~Ice()
{
	// std::cout << "Ice destructor called!" <<std::endl;
}

Ice& Ice::operator=(const Ice& rhs)
{
	// std::cout << "Ice assignment operator called!" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

Ice* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}