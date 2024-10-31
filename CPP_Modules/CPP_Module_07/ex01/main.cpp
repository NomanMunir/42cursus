/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 08:44:42 by nmunir            #+#    #+#             */
/*   Updated: 2024/05/15 08:47:58 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main( void )
{
  int intArray[] = {1, 2, 3, 4, 5};
  char charArray[] = {'a', 'b', 'c', 'd', 'e'};
  double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  std::string stringArray[] = {"Hi", "there,", "42", "is", "Awesome!"};

    std::cout << "..............." << std::endl;
    std::cout << "Int array: ";
    iter(intArray, 5, print<int>);
    std::cout << std::endl;

    std::cout << "..............." << std::endl;
    std::cout << "Char array: ";
    iter(charArray, 5, print<char>);
    std::cout << std::endl;

    std::cout << "..............." << std::endl;

    std::cout << "Double array: ";
    iter(doubleArray, 5, print<double>);
    std::cout << std::endl;

    std::cout << "..............." << std::endl;
    std::cout << "String array: ";
    iter(stringArray, 5, print<std::string>);
    std::cout << std::endl;

  return 0;
}
