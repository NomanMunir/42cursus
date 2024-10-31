/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:31:30 by nmunir            #+#    #+#             */
/*   Updated: 2024/05/14 09:31:31 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <class T>
void swap(T & a, T & b)
{
  T tmp = a;
  a = b;
  b = tmp;
}

template <class T>
T max(T x, T y) { return (x > y ? x : y); }

template <class T>
T min(T x, T y) { return (x < y ? x : y); }

#endif