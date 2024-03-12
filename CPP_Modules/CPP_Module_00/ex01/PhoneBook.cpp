/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:57:45 by nmunir            #+#    #+#             */
/*   Updated: 2024/02/06 10:44:38 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int PhoneBook::index = -1;

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::printContact(int n)
{
	std::cout << "Index: " << n << std::endl;
	std::cout << "First Name: " << this->contacts[n].getFName() << std::endl;
	std::cout << "Last Name: " << this->contacts[n].getLName() << std::endl;
	std::cout << "Nick Name: " << this->contacts[n].getNickName() << std::endl;
	std::cout << "Phone Number: " << this->contacts[n].getPhNb() << std::endl;
	std::cout << "Darkest Secret: " << this->contacts[n].getSecret() << std::endl;
}

void PhoneBook::chooseIndex()
{
	std::string input;
	int i;
	int n;
	while (1)
	{
		i = 0;
		std::cout << "Choose Index: ";
		getline(std::cin, input);
		while (input[i] == ' ' || input[i] == '\t')
			i++;
		if (input[i] == '\0')
			continue;
		if (isdigit(input[i]))
			i++;
		if (input[i] != '\0')
			continue;
		n = std::stoi(input);
		if (n >= 0 && n <= 7 && PhoneBook::index >= n)
			return (this->printContact(n));
		else
			std::cout << "Invalid index!" << std::endl;
	}
}

void PhoneBook::showEntries()
{
	int i = 0;
	if (PhoneBook::index == -1)
		std::cout << "No entry found!" << std::endl;
	std::cout << "Index     |"
			  << "First Name|"
			  << "Last Name |"
			  << "Nick Name " << std::endl;
	while (i <= PhoneBook::index)
	{
		std::cout << i;
		std::cout << "         |";
		print(this->contacts[i].getFName());
		std::cout << "|";
		print(this->contacts[i].getLName());
		std::cout << "|";
		print(this->contacts[i].getNickName());
		std::cout << std::endl;
		i++;
	}
	if (PhoneBook::index != -1)
		this->chooseIndex();
}

void PhoneBook::addContact(Contact &con)
{
	if (PhoneBook::index < 7)
		PhoneBook::index++;
	this->contacts[PhoneBook::index] = con;
}
