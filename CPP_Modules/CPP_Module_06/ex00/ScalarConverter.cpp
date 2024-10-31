/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:01:01 by nmunir            #+#    #+#             */
/*   Updated: 2024/05/13 17:10:44 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const  ScalarConverter& other) { (void) other; }
ScalarConverter& ScalarConverter::operator=(const  ScalarConverter& rhs) { (void) rhs; return (*this); }
ScalarConverter::~ScalarConverter() {}

static int countOccurrences(const std::string& str, char ch) {
    size_t count = 0;
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == ch)
            count++;
    }
    return count;
}

static int validate_input(std::string input)
{
	if ( input.find(' ') != std::string::npos ) { std::cout << "Space found!" << std::endl;  return (1); }
	if (countOccurrences(input, '.') > 1 || input[input.length() - 1] == '.') { std::cout << "Invalid input" << std::endl; return (1); };
	if ( input == "-inf" || input == "+inf" || input == "inf" \
		 || input == "-inff" || input == "+inff" || input == "inff" \
		 || input == "nan" || input == "nanf" || input == "-nan" || input == "-nanf")
		 	return (0);
	if ( input[0] == '-' || input[0] == '+')
		input.erase(0, 1);
	size_t length = input.length();
	if (input[length - 1] == 'f')
	{
		length--;
		if (input[length - 1] == '.') {	std::cout << "Invalid input" << std::endl; return (1); };
	}
	for (size_t i = 0; i < length; i++)
	{
		if (!isdigit(input[i]) && input[i] != '.')
		{
			std::cout << "Invalid input" << std::endl;
			return (1);
		}
	}
	return (0);
}

static void printChar(int c)
{
	if (isprint(c))
		std::cout << "char: '" << static_cast<char>(c) << "'" <<std::endl;
	else if (c > 255 || c < 0)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

static void printInt(std::string& input)
{
	try
	{
		int i = std::stoi(input);
		if (std::isnan(i) ||i > std::numeric_limits<char>::max() || i < std::numeric_limits<char>::min())
			std::cout << "char: impossible" << std::endl;
		else if (isprint(i))
			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "char:  Non displayable" << std::endl;
		if (i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << i << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
}

static void printFloat(std::string& input)
{
	try
	{
		float f = std::stof(input);
		if (std::isnan(f))
			std::cout << "float: nanf" << std::endl;
		else if (std::isinf(f))
			std::cout << "float: inff" << std::endl;
		else
		{
			std::cout << "float: " << f;
			if (f == static_cast<int>(f))
				std::cout << ".0";
			std::cout << "f" << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << "float: impossible" << std::endl;
	}
}

static void printDouble(std::string& input)
{
	try
	{
		double d = std::stod(input);
		if (std::isnan(d))
			std::cout << "double: nan" << std::endl;
		else if (std::isinf(d))
			std::cout << "double: inf" << std::endl;
		else
		{
			std::cout << "double: " << d;
			if (d == static_cast<int>(d))
				std::cout << ".0";
			std::cout << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << "double: impossible" << std::endl;
	}
}

void ScalarConverter::convert(std::string input)
{
	if (input.length() == 1 && isprint(input[0]) && !isdigit(input[0]))
	{
		printChar(input[0]);
		std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(input[0]) << ".0" <<std::endl;
		return ;
	}
	if (validate_input(input))
		return ;
	printInt(input);
	printFloat(input);
	printDouble(input);
}
