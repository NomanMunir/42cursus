/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:37:28 by nmunir            #+#    #+#             */
/*   Updated: 2024/02/19 10:31:22 by nmunir           ###   ########.fr       */
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
		Fixed& operator=(Fixed const & rhs);
		~Fixed();
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream & operator <<(std::ostream & o, Fixed const & rhs);