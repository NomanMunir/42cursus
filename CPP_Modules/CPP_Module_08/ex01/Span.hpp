/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:37:27 by nmunir            #+#    #+#             */
/*   Updated: 2024/05/18 16:35:35 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>
#include <climits>
#include <limits>

class Span{
	private:
		unsigned int _size;
		std::vector<int> data;
		Span();
	public:
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& rhs);
		void addNumber(unsigned int n);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned int shortestSpan();
		unsigned int longestSpan();
};

#endif // SPAN_HPP