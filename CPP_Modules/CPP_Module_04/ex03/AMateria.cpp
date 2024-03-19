/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 10:42:49 by nmunir            #+#    #+#             */
/*   Updated: 2024/03/18 15:31:02 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"

AMateria::AMateria() : _type("unknown")
{
	// std::cout << "AMateria default constructor called!" << std::endl;	
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	// std::cout << "AMateria type constructor called!" << std::endl;
}

AMateria::~AMateria()
{
	// std::cout << "AMateria Destructor called!" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
	// std::cout << "AMateria copy constructor called!" << std::endl;
	*this = other;
}

AMateria& AMateria::operator=(const AMateria& rhs)
{
	// std::cout << "AMateria assignment operator called!" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* " << target.getName() << "'s used some item *" << std::endl;
	
}