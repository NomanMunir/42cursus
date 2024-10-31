/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:55:01 by nmunir            #+#    #+#             */
/*   Updated: 2024/05/15 10:43:28 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstdlib>

template <class T>

class Array
{
  private:
    unsigned long _size;
    T *data;
  public:
    Array();
    Array(unsigned long n);
    Array(const Array& copy);

    Array& operator=(const Array &rhs);

    // Destructor
    ~Array();
    
    unsigned long size() const;
    
    const T& operator[](unsigned int index) const;
    T& operator[](unsigned int index);
};

template <class T>
Array<T>::Array(): _size(0), data(NULL) {};

template <class T>
Array<T>::Array(unsigned long n): _size(n), data(new T[n]) { }

template <class T>
Array<T>::Array(const Array& copy) : _size(copy._size), data(new T[copy._size])
{
  try {
      for (unsigned long i = 0; i < _size; ++i)
          data[i] = copy.data[i];
  } catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
      if (data) delete[] data;
      throw;
  }
}

template <class T>
Array<T>::~Array()
{
  delete[] data; 
}

template <class T>
Array<T> &Array<T>::operator=(const Array &rhs) 
{
  if (this != &rhs)
  {
    if (data) delete[] data;
    try
    {
      data = new T[rhs._size];
      for (unsigned long i = 0; i < rhs.size(); i++)
        data[i] = rhs.data[i];
      _size =  rhs._size;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
      throw;
    }
  }
  return (*this);
}

template <class T>
unsigned long Array<T>::size() const
{
  return (_size);
}

template <class T>
T& Array<T>::operator[](unsigned int index)
{
  if (index >= _size)
    throw std::out_of_range("Index out of range!");
  return data[index];
}

template <class T>
const T& Array<T>::operator[](unsigned int index) const
{
  if (index >= _size)
      throw std::out_of_range("Index out of range!");
    return data[index];
}

#endif