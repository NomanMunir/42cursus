/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:31:03 by nmunir            #+#    #+#             */
/*   Updated: 2024/03/18 15:25:31 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

int main()
{
	Dog basic;
	{
		Dog tmp  = basic;
	}
	
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Animal *array[4];
	for (int i = 0; i < 2; i++)
	{
		array[i] = new Cat();
		array[i]->makeSound();
	}
	for (int i = 2; i < 4; i++)
	{
		array[i] = new Dog();
		array[i]->makeSound();
	}
	for (int i = 0; i < 4; i++)
		delete array[i];
	delete j;
	delete i;
	return 0;
}
