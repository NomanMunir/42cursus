/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:56:54 by nmunir            #+#    #+#             */
/*   Updated: 2024/03/17 16:29:51 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called!" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called!" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called!" << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& rhs)
{
	std::cout << "Brain assignment operator called!" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i]; 
	}
	return (*this);
}
