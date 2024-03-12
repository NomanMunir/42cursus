/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:15:29 by nmunir            #+#    #+#             */
/*   Updated: 2024/02/20 17:15:47 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed d1, d2, d3;
    bool has_neg, has_pos;

    d1 = (point.getX() - b.getX()) * (a.getY() - b.getY()) - (a.getX() - b.getX()) * (point.getY() - b.getY());
    d2 = (point.getX() - c.getX()) * (b.getY() - c.getY()) - (b.getX() - c.getX()) * (point.getY() - c.getY());
    d3 = (point.getX() - a.getX()) * (c.getY() - a.getY()) - (c.getX() - a.getX()) * (point.getY() - a.getY());

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}
