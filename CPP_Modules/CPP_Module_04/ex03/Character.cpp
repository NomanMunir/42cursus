/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:12:01 by nmunir            #+#    #+#             */
/*   Updated: 2024/03/18 16:26:22 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : _name("Unknown")
{
	// std::cout << "Character default constructor called!" << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
		_unequipInventroy[i] = NULL;
	}
}

Character::Character(std::string name) : _name(name)
{
	// std::cout << "Character name constructor called!" << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
		_unequipInventroy[i] = NULL;
	}
}

Character::~Character()
{
	// std::cout << "Character destructor is called!" << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_inventory[i]) delete this->_inventory[i];
		if (this->_unequipInventroy[i]) delete this->_unequipInventroy[i];
	}
}

Character::Character(const Character& other)
{
	// std::cout << "Character copy constructor called!" << std::endl;
	_name = other._name;
	for (int i = 0; i < 4; i++)
    {
		_inventory[i] = NULL;
        _unequipInventroy[i] = NULL;
    }
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		if (other._unequipInventroy[i])
            _unequipInventroy[i] = other._unequipInventroy[i]->clone();
	}
}


Character& Character::operator=(const Character& rhs)
{
	// std::cout << "Character assignment operator called!" << std::endl;
	if (this != &rhs)
    {
        this->_name = rhs._name;
        for (int i = 0; i < 4; i++)
	    {
		    if (_inventory[i])
		    {
			    delete _inventory[i];
			    _inventory[i] = NULL;
		    }
            if (_unequipInventroy[i])
		    {
			    delete _unequipInventroy[i];
			    _unequipInventroy[i] = NULL;
		    }
	    }
        for (int i = 0; i < 4; i++)
        {
            if (rhs._inventory[i])
                _inventory[i] = rhs._inventory[i]->clone();
            if (rhs._unequipInventroy[i])
                _unequipInventroy[i] = rhs._unequipInventroy[i]->clone();           
        }
    }
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (m != NULL)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i] == m)
			{
				std::cout << "You have already stored this materia!" << std::endl;
				return;
			}
		}
		for (size_t i = 0; i < 4; i++)
		{
			if (!_inventory[i])
			{
				// std::cout << this->_name << " equiped " << m->getType() << std::endl;
				this->_inventory[i] = m;
				return ;
			}
		}
		std::cout << "No slot to equip item. Unequip something to equip this item!" << std::endl;
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || !this->_inventory[idx])
	{
		std::cout << "Invalid Index" << std::endl;
		return ;
	}
	for (size_t i = 0; i < 4; i++)
	{
		if (_unequipInventroy[i] == NULL)
		{
			_unequipInventroy[i] = _inventory[idx];
			_inventory[idx] = NULL;
			// std::cout << _name << " Unequipped " << _unequipInventroy[i]->getType() << "!" << std::endl;
			return ;
		}
	}
	delete _unequipInventroy[0];
	for (size_t i = 1; i < 4; i++)
	{
		_unequipInventroy[i - 1] = _unequipInventroy[i];
	}
	_unequipInventroy[3] = _inventory[idx];
	_inventory[idx] = NULL;
	// std::cout << "Unequipped " << _inventory[idx]->getType() << "!" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || !this->_inventory[idx])
	{
		std::cout << "Invalid Index" << std::endl;
	}
	else
		this->_inventory[idx]->use(target);
}
