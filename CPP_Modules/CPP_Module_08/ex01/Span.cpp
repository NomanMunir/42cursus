/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:37:28 by nmunir            #+#    #+#             */
/*   Updated: 2024/05/18 16:40:11 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() { }

Span::Span(unsigned int n): _size(n) { }

Span::Span(const Span& other) :_size(other._size)
{
	for (unsigned int i = 0; i < other.data.size(); i++)
		this->data.push_back(other.data[i]);
}
Span& Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		this->_size = rhs._size;
		for (unsigned int i = 0; i < rhs.data.size(); i++)
			this->data.push_back(rhs.data[i]);
	}
	return (*this);
}

void Span::addNumber(unsigned int n)
{
	if (this->data.size() >= _size)
		throw std::out_of_range("Span is Full!");
	this->data.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	unsigned int dist = std::distance(begin, end);
	if (dist + data.size() > _size)
		throw std::out_of_range("Span is Full!");

	data.insert(data.end(), begin, end);
}

unsigned int Span::shortestSpan()
{
	if (data.size() <= 1)
		throw std::out_of_range("No Span found!");

	int min = std::numeric_limits<int>::max();
	for (unsigned int i = 0; i < data.size() - 1; ++i)
	{
	int span = std::abs(data[i + 1] - data[i]);
		if (span < min)
			min = span;
	}
	return (min);
}

unsigned int Span::longestSpan()
{
	if (data.size() <= 1)
		throw std::out_of_range("No Span found!");

	unsigned int min = *std::min_element(data.begin(), data.end());
	unsigned int max = *std::max_element(data.begin(), data.end());
	return (max - min);
}
