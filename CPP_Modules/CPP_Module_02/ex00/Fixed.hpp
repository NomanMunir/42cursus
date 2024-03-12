/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:37:28 by nmunir            #+#    #+#             */
/*   Updated: 2024/02/20 17:41:44 by nmunir           ###   ########.fr       */
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
		Fixed(const Fixed& other);
		Fixed& operator=(Fixed const & rhs);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
