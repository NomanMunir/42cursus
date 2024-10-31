/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:26:40 by nmunir            #+#    #+#             */
/*   Updated: 2024/05/15 08:47:30 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <class T>
void iter(T *arr, size_t size, void(*print)(T))
{
  for(size_t i = 0; i < size; i++)
    print(arr[i]);
  std::cout << std::endl;
}

template <class T>
void print(T c)
{
  std::cout << c << " ";
}

#endif