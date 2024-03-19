/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:38:30 by nmunir            #+#    #+#             */
/*   Updated: 2024/03/18 16:06:47 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	// std::cout << "MateriaSource default constructor called!" << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		this->templates[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	// std::cout << "MateriaSource destructor is called!" << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		if (this->templates[i]) delete this->templates[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	// std::cout << "MateriaSource copy constructor called!" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		templates[i] = NULL;
		if (other.templates[i])
			templates[i] = other.templates[i]->clone();
	}
}


MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
	// std::cout << "MateriaSource assignment operator called!" << std::endl;
	if (this != &rhs)
    {
		for (size_t i = 0; i < 4; i++)
		{	
            if (templates[i])
            {
                delete templates[i];
                templates[i] = NULL;
            }
		}
        for (int i = 0; i < 4; i++)
        {
            if (rhs.templates[i])
                templates[i] = rhs.templates[i]->clone();
        }
    }
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
		{
			if (templates[i] == m)
			{
				std::cout << "You have already stored this materia!" << std::endl;
				return;
			}
		}
	for (size_t i = 0; i < 4; i++)
	{
		if (!templates[i])
		{
			templates[i] = m;
			// std::cout << "MateriaSource learned " << m->getType() << std::endl;
			return ;
		}
	}
	// std::cout << "MateriaSource can't learn " << m->getType() << std::endl;	
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for ( int i = 0; i < 4; i++ )
        if (this->templates[i] && this->templates[i]->getType() == type)
            return (this->templates[i]->clone());
    return NULL;
}
