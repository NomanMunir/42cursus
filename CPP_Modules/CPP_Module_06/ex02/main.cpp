/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:01:10 by nmunir            #+#    #+#             */
/*   Updated: 2024/05/13 10:50:56 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"


Base * generate(void)
{
	srand(time(NULL));
	int RandIndex = rand() % 3;
	if (RandIndex == 0)
    	return new A();
	else if (RandIndex == 1)
		return new B();
	else if (RandIndex == 2)
    	return new C();

	return (NULL);
}
void identify(Base* p)
{
	if (dynamic_cast<A *> (p))
		std::cout << "I am A" << std::endl;
	else if (dynamic_cast<B *> (p))
		std::cout << "I am B" << std::endl;
	else if (dynamic_cast<C *> (p))
		std::cout << "I am C" << std::endl;
}
void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A &> (p);
		(void)a;
		std::cout << "I am A" << std::endl;
	}
	catch(const std::exception& e) { }
	try
	{
		B & b = dynamic_cast<B &> (p);
		(void)b;
		std::cout << "I am B" << std::endl;
	}
	catch(const std::exception& e) { }
	try
	{
		C & c = dynamic_cast<C &> (p);
		(void)c;
		std::cout << "I am C" << std::endl;
	}
	catch(const std::exception& e) {	}
}

int main (void)
{
	Base *gen = generate();
	if (gen == NULL) {
		std::cerr << "Failed to generate object." << std::endl;
		return 1;
	}
	identify(gen);
	identify(*gen);
	if (gen) delete gen;
	return (0);
}
