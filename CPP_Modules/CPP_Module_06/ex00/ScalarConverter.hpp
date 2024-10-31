/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:01:06 by nmunir            #+#    #+#             */
/*   Updated: 2024/04/04 11:34:31 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <limits>



class ScalarConverter
{	
	private:
		ScalarConverter();
		ScalarConverter(const  ScalarConverter& other);
		ScalarConverter& operator=(const  ScalarConverter& rhs);
		~ScalarConverter();
	public:
		static void convert( std::string input );
};
#endif // !SCALARCONVERTER_HPP
