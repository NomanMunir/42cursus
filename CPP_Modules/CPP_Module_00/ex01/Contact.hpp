/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:50:44 by nmunir            #+#    #+#             */
/*   Updated: 2024/02/06 10:13:42 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Contact
{
	private:
		std::string fName;
		std::string lName;
		std::string nickName;
		std::string phNb;
		std::string secret;
	public:
		Contact();
		~Contact();
		std::string getFName(void) const;
		std::string getLName(void) const;
		std::string getNickName(void) const;
		std::string getPhNb(void) const;
		std::string getSecret(void) const;
		void setFName(std::string input);
		void setLName(std::string input);
		void setNickName(std::string input);
		void setPhNb(std::string input);
		void setSecret(std::string input);
};
