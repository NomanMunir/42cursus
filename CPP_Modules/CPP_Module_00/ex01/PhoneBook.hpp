/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:57:27 by nmunir            #+#    #+#             */
/*   Updated: 2024/02/06 10:44:41 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"
#include "utils.hpp"

class PhoneBook
{
	Contact contacts[8];
	public:
		static int index;
		PhoneBook();
		~PhoneBook();
		void addContact(Contact& con);
		void showEntries();
		void chooseIndex();
		void printContact(int n);
};

void print(std::string input);