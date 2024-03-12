/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:08:09 by nmunir            #+#    #+#             */
/*   Updated: 2024/03/03 15:09:55 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void getInput(std::string msg, Contact &con)
{
	std::string input;
	int i = 0;
	while (1)
	{
		std::cout << msg;
		getline(std::cin, input);
		while (input[i] == ' ' || input[i] == '\t')
			i++;
		if (input[i] != '\0')
			break;
	}
	if (!msg.compare("First Name: "))
		con.setFName(input);
	else if (!msg.compare("Last Name: "))
		con.setLName(input);
	else if (!msg.compare("Nick Name: "))
		con.setNickName(input);
	else if (!msg.compare("Phone: "))
		con.setPhNb(input);
	else if (!msg.compare("Darkest Secret: "))
		con.setSecret(input);
}

void inputForm(PhoneBook &book)
{
	Contact con;

	getInput("First Name: ", con);
	getInput("Last Name: ", con);
	getInput("Nick Name: ", con);
	getInput("Phone: ", con);
	getInput("Darkest Secret: ", con);
	book.addContact(con);
}

void prompt()
{
	PhoneBook book;
	std::string input;
	while (1)
	{
		std::cout << "Please enter (ADD, SEARCH, EXIT)" << std::endl;
		getline(std::cin, input);
		if (std::cin.eof())
			continue;
		if (!input.compare("EXIT"))
			return;
		else if (!input.compare("ADD"))
			inputForm(book);
		else if (!input.compare("SEARCH"))
			book.showEntries();
	}
}

void print(std::string input)
{
	int len;
	int j;

	j = 0;
	len = input.length();
	if (len > 10)
	{
		while (j < 9)
			std::cout << input[j++];
		std::cout << ".";
	}
	else
	{
		std::cout << input;
		while (++len <= 10)
			std::cout << " ";
	}
}
