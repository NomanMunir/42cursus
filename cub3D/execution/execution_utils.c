/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:05:07 by nmunir            #+#    #+#             */
/*   Updated: 2024/01/28 16:37:58 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

double	drad(double deg)
{
	return (deg * M_PI / 180);
}

void	set_color(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_bytes + x * (data->bitsinpixel / 8));
	*(unsigned int *)dst = color;
}

int	in_range(double angle, double start, double end)
{
	if (angle >= drad(start) && angle <= drad(end))
		return (1);
	return (0);
}
