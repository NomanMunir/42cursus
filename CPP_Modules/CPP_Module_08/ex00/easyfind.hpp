/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 09:55:44 by nmunir            #+#    #+#             */
/*   Updated: 2024/05/18 10:31:54 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>

template <class T>
int easyfind(T& search, int find)
{
  typename T::iterator it = std::find(search.begin(), search.end(), find);
  if (it != search.end())
  {
    std::cout << "Value: " << find << " Found!" << std::endl;
    return (std::distance(search.begin(), it));
  }
  else
  {
    std::cout<< "Value: " << find << " Not Found!" << std::endl;
    throw std::runtime_error("Value not found in container");
  }
}

#endif