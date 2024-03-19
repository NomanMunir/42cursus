/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:14:25 by nmunir            #+#    #+#             */
/*   Updated: 2024/03/18 15:34:23 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP


#include <iostream>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(const std::string &type);
		virtual ~Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& rhs);
		virtual void makeSound() const;
		std::string getType() const;
};

#endif