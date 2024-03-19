/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:56:25 by nmunir            #+#    #+#             */
/*   Updated: 2024/03/18 15:51:41 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	// std::cout << "Cure default constructor called!" << std::endl;
}

Cure::Cure(const Cure& other): AMateria(other)
{
	// std::cout << "Cure copy constructor called!" << std::endl;
	*this = other;
}

Cure::~Cure()
{
	// std::cout << "Cure destructor called!" <<std::endl;
}

Cure& Cure::operator=(const Cure& rhs)
{
	// std::cout << "Cure assignment operator called!" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

Cure* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
