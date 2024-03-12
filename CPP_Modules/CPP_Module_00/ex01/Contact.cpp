/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:49:23 by nmunir            #+#    #+#             */
/*   Updated: 2024/02/06 10:15:15 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	this->fName = "";
	this->lName = "";
	this->nickName = "";
	this->phNb = "";
	this->secret = "";
}

Contact::~Contact()
{
	
}

std::string Contact::getFName(void) const
{
	return (this->fName);
}

std::string Contact::getLName(void) const
{
	return (this->lName);
}

std::string Contact::getNickName(void) const
{
	return (this->nickName);
}

std::string Contact::getPhNb(void) const
{
	return (this->phNb);
}

std::string Contact::getSecret(void) const
{
	return (this->secret);
}

void Contact::setFName(std::string input)
{
	this->fName = input;
}

void Contact::setLName(std::string input)
{
	this->lName = input;
}

void Contact::setNickName(std::string input)
{
	this->nickName= input;
}

void Contact::setPhNb(std::string input)
{
	this->phNb= input;
}

void Contact::setSecret(std::string input)
{
	this->secret= input;
}
