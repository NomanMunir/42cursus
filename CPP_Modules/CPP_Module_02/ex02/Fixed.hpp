/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:37:28 by nmunir            #+#    #+#             */
/*   Updated: 2024/02/20 16:17:02 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
	private:
		int _value;
		const static int fractInt = 8;
	public:
		Fixed();
		Fixed(const int intValue);
		Fixed(const float floatValue);
		Fixed(const Fixed& other);
		~Fixed();
		float toFloat( void ) const;
		int toInt( void ) const;
		Fixed& operator=(Fixed const & rhs);
		Fixed operator*(Fixed const & rhs);
		Fixed operator-(Fixed const & rhs);
		Fixed operator+(Fixed const & rhs);
		Fixed operator/(Fixed const & rhs);
		Fixed& operator++( void );
		Fixed operator++( int );
		Fixed& operator--( void );
		Fixed operator--( int );
		bool operator>(Fixed const & rhs) const;
		bool operator<(Fixed const & rhs) const;
		bool operator>=(Fixed const & rhs) const;
		bool operator<=(Fixed const & rhs) const;
		bool operator==(Fixed const & rhs) const;
		bool operator!=(Fixed const & rhs) const;
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
};

std::ostream & operator <<(std::ostream & o, Fixed const & rhs);