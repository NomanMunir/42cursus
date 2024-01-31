/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3d_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:07:42 by nmunir            #+#    #+#             */
/*   Updated: 2024/01/29 12:39:50 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	create_texture(t_game *game, t_texture *t)
{
	t->no_img.ptr = mlx_xpm_file_to_image(game->mlx_ptr, t->no, &t->no_img.w, \
		&t->no_img.h);
	t->so_img.ptr = mlx_xpm_file_to_image(game->mlx_ptr, t->so, &t->so_img.w, \
		&t->so_img.h);
	t->we_img.ptr = mlx_xpm_file_to_image(game->mlx_ptr, t->we, &t->we_img.w, \
		&t->we_img.h);
	t->ea_img.ptr = mlx_xpm_file_to_image(game->mlx_ptr, t->ea, &t->ea_img.w, \
		&t->ea_img.h);
	if (!t->no_img.ptr || !t->so_img.ptr || !t->we_img.ptr || !t->ea_img.ptr)
		return (destroy_texture(game, t));
	t->no_img.addr = mlx_get_data_addr(t->no_img.ptr, &t->no_img.bitsinpixel, \
		&t->no_img.line_bytes, &t->no_img.endian);
	t->so_img.addr = mlx_get_data_addr(t->so_img.ptr, &t->so_img.bitsinpixel, \
		&t->so_img.line_bytes, &t->so_img.endian);
	t->we_img.addr = mlx_get_data_addr(t->we_img.ptr, &t->we_img.bitsinpixel, \
		&t->we_img.line_bytes, &t->we_img.endian);
	t->ea_img.addr = mlx_get_data_addr(t->ea_img.ptr, &t->ea_img.bitsinpixel, \
		&t->ea_img.line_bytes, &t->ea_img.endian);
	return (0);
}

int	get_bitmap_offset(t_game *game, int i, t_img *txt_img)
{
	double	rm;
	int		offset;
	double	x;
	double	y;

	x = game->ray[i].x_h;
	y = game->ray[i].y_v;
	if (game->ray[i].hit_horz == NORTH || game->ray[i].hit_horz == SOUTH)
	{
		rm = x / game->tile - floor(x / game->tile);
		offset = txt_img->w * rm;
	}
	else
	{
		rm = y / game->tile - floor(y / game->tile);
		offset = txt_img->w * rm;
	}
	return (offset);
}

void	bitmap(t_game *game, int x, t_img *txt_img)
{
	double	step;
	double	tex_y;
	int		*img;
	int		*tex_img;
	int		arr[3];

	step = txt_img->h / game->ray[x].height;
	tex_y = (game->ray[x].top_pix - HEIGHT / 2 + game->ray[x].height / 2)
		* step;
	arr[0] = get_bitmap_offset(game, x, txt_img);
	arr[2] = 0;
	img = (int *)game->img.addr;
	tex_img = (int *)txt_img->addr;
	while (arr[2] < game->ray[x].height && arr[2] < HEIGHT)
	{
		arr[1] = (int)tex_y & (txt_img->h - 1);
		tex_y += step;
		img[((int)game->ray[x].top_pix * WIDTH) + (arr[2] * WIDTH)
			+ x] = tex_img[(arr[1] * txt_img->h) + arr[0]];
		arr[2]++;
	}
}

void	draw_walls_3d(t_game *game)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		if (game->ray[i].hit_horz == NORTH)
			bitmap(game, i, &game->texture->no_img);
		else if (game->ray[i].hit_horz == SOUTH)
			bitmap(game, i, &game->texture->so_img);
		else if (game->ray[i].hit_vert == EAST)
			bitmap(game, i, &game->texture->ea_img);
		else if (game->ray[i].hit_vert == WEST)
			bitmap(game, i, &game->texture->we_img);
		i++;
	}
}
