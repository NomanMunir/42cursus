/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:39:51 by nmunir            #+#    #+#             */
/*   Updated: 2024/03/18 16:07:50 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{

		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
		return 0;



	// MateriaSource *src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	// ICharacter * me = new Character("Nauman");
	// ICharacter * alaa = new Character("Alaa");
	// std::cout << me->getName() << std::endl;
	// AMateria *tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// me->unequip(0);
	// me->use(1, *alaa);
	
	// delete me;
	// delete alaa;
	// delete src;
	// IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	// ICharacter* me = new Character("me");
	// AMateria* tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// me->unequip(0);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// me->unequip(0);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// me->unequip(0);
	
	// // ICharacter* bob = new Character("bob");
	// // me->use(0, *bob);
	// // me->use(1, *bob);
	// // delete bob;
	// delete me;
	// delete src;
}
