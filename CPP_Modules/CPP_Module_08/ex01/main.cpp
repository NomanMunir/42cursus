/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:33:10 by ael-khni          #+#    #+#             */
/*   Updated: 2024/05/18 16:44:38 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main( void )
{
    std::cout << "---- TEST #1 -----\n" << std::endl;
  try
  {
    Span sp = Span( 5 );

    sp.addNumber( 1 );
    sp.addNumber( 3 );
    sp.addNumber( 9 );
    sp.addNumber( 17 );
    sp.addNumber( 11 );
    std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  
    std::cout << "\n---- TEST #2 -----\n" << std::endl;
  try
  {
    Span sp = Span( 5 );
    int arr[] = {10, 20, 30, 40, 50};
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
    sp.addNumber(vec.begin(), vec.end());

    std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  
    std::cout << "\n---- TEST #3 -----\n" << std::endl;
  try
  {
    Span sp = Span( 5 );
    int arr[] = {10, 20, 30, 40, 50, 60};
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
    sp.addNumber(vec.begin(), vec.end());

    std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
    std::cout << "\n---- TEST #4 -----\n" << std::endl;
  try
  {
    Span sp = Span( 1 );
    int arr[] = {10};
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
    sp.addNumber(vec.begin(), vec.end());

    std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  
    std::cout << "\n---- TEST #5 -----\n" << std::endl;

  try {
      std::vector<int>    l( 10000 );
      std::srand( time ( NULL ) );
      std::generate( l.begin(), l.end(), std::rand );

      Span span( l.size() );

      span.addNumber( l.begin(), l.end() );

      std::cout << "Longest span: " << span.longestSpan() << std::endl;
      std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
      
  } catch ( std::exception& e ) {
      std::cout << e.what() << std::endl; 
  }
  std::cout << "\n---- TEST #6 -----\n" << std::endl;
  try
  {
    Span spCopy = Span( 10 );
    int arr[] = {10, 12, 123, 124, 12, 123, 1};
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

    spCopy.addNumber(vec.begin(), vec.end());
    Span sp(spCopy);

    std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  return 1;
}
