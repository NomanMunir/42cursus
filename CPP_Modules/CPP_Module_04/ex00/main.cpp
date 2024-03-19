/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:31:03 by nmunir            #+#    #+#             */
/*   Updated: 2024/03/18 14:56:10 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal *meta = new Animal();
	meta->makeSound();
	delete meta;
	std::cout << std::endl;
	
	const Animal* i = new Cat();
	std::cout << i->getType() << std::endl;
	i->makeSound();
	delete i;
	std::cout << std::endl;
	
	const Animal* j = new Dog();
	std::cout << j->getType() << std::endl;
	j->makeSound();
	delete j;
	std::cout << std::endl;

    const WrongAnimal *wrong = new WrongAnimal();
    std::cout << "Wrong Type: " << wrong->getType() << std::endl;
    wrong->makeSound();
    delete  wrong;
	std::cout << std::endl;

    const WrongAnimal *wrongCat = new WrongCat();
    std::cout << "WrongCat Type: " << wrongCat->getType() << std::endl;
    wrongCat->makeSound();
    delete  wrongCat;
	std::cout << std::endl;

}
