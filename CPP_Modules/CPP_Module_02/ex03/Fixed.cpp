/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:42:53 by nmunir            #+#    #+#             */
/*   Updated: 2024/02/20 16:27:14 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	_value = static_cast <int>(roundf(intValue * (1 << fractInt)));;
}

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	_value = static_cast <int>(roundf(floatValue * (1 << fractInt)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_value = rhs._value;
	return (*this);
}

Fixed::Fixed(const Fixed & other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

float Fixed::toFloat( void ) const
{
	return (( _value / static_cast<float>(1 << fractInt)));
}

int Fixed::toInt( void ) const
{
	return (roundf(this->toFloat()));
}

bool Fixed::operator>(Fixed const & rhs) const
{
	return (this->_value > rhs._value);
}

bool Fixed::operator<(Fixed const & rhs) const
{
	return (this->_value < rhs._value);
}

bool Fixed::operator>=(Fixed const & rhs) const
{
	return (this->_value >= rhs._value);
}

bool Fixed::operator<=(Fixed const & rhs) const
{
	return (this->_value <= rhs._value);
}

bool Fixed::operator==(Fixed const & rhs) const
{
	return (this->_value == rhs._value);
}

bool Fixed::operator!=(Fixed const & rhs) const
{
	return (this->_value != rhs._value);
}

Fixed Fixed::operator*(Fixed const & rhs)
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator-(Fixed const & rhs)
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator+(Fixed const & rhs)
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator/(Fixed const & rhs)
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    if (a < b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    if (a > b)
		return (a);
	return (b);
}

Fixed& Fixed:: operator++( void )
{
	this->_value++;
	return (*this);
}

Fixed Fixed:: operator++(int)
{
	Fixed tmp = *this;
	this->_value++;
	return (tmp);
}

Fixed& Fixed:: operator--( void )
{
	this->_value--;
	return (*this);
}

Fixed Fixed:: operator--(int)
{
	Fixed tmp = *this;
	this->_value--;
	return (tmp);
}

std::ostream & operator << (std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}
