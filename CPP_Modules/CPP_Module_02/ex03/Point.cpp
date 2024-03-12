/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:47:56 by nmunir            #+#    #+#             */
/*   Updated: 2024/02/20 18:06:54 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const float float_x, const float float_y) : x(float_x), y(float_y)
{
}
Point::Point(const Point &other)
{
	*this = other;
}

Point& Point::operator=(const Point &rhs)
{
	if (this != &rhs)
	{
		 (Fixed&) (this->x) = rhs.x;
		(Fixed&) (this->y) = rhs.y;
		// const_cast< Fixed& >(this->y) = rhs.y;
	}
	return (*this);
}

Fixed Point::getX() const
{
	return (x);
}

Fixed Point::getY() const
{
	return (y);
}

Point::~Point()
{
}