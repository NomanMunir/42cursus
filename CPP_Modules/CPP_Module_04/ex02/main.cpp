/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:31:03 by nmunir            #+#    #+#             */
/*   Updated: 2024/03/18 15:30:17 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

int	main(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;
	
	Animal* array[4];
	for (int i = 0; i < 2; i++)
	{
		array[i] = new Cat();
	}
	for (int i = 2; i < 4; i++)
		array[i] = new Dog();
	for (int i = 0; i < 4; i++)
		delete array[i];
}
