/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:48:00 by nmunir            #+#    #+#             */
/*   Updated: 2024/02/20 17:39:08 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& other);
		Point & operator=(const Point& rhs);
		Fixed getX() const;
		Fixed getY() const;
		~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);