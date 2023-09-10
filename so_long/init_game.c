/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:40:14 by abashir           #+#    #+#             */
/*   Updated: 2023/09/08 17:54:35 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	create_image_ptr(void *mlx, char *path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx, path, &img.h, &img.w);
	return (img);
}

void	create_images(t_game *img)
{
	img->s_img = create_image_ptr(img->mlx_ptr, S_PATH);
	img->c_img = create_image_ptr(img->mlx_ptr, C_PATH);
	img->e_img = create_image_ptr(img->mlx_ptr, E_PATH);
	img->w_img = create_image_ptr(img->mlx_ptr, W_PATH);
	img->p_img = create_image_ptr(img->mlx_ptr, P_PATH);
	if (!img->s_img.img || !img->c_img.img || !img->e_img.img || \
	!img->w_img.img || !img->p_img.img)
	{
		mlx_destroy_window(img->mlx_ptr, img->win_ptr);
		imgs_destroy(img);
		free(img->mlx_ptr);
		handle_error_free(10, img->map.plot);
	}
}

void	put_image(char c, int x, int y, t_game img)
{
	if (c == 'P')
		mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, \
		img.p_img.img, y * IMAGE_SIZE, x * IMAGE_SIZE);
	else if (c == 'C')
		mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, \
		img.c_img.img, y * IMAGE_SIZE, x * IMAGE_SIZE);
	else if (c == 'E')
		mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, \
		img.e_img.img, y * IMAGE_SIZE, x * IMAGE_SIZE);
	else if (c == '1')
		mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, \
		img.w_img.img, y * IMAGE_SIZE, x * IMAGE_SIZE);
	else if (c == '0')
		mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, \
		img.s_img.img, y * IMAGE_SIZE, x * IMAGE_SIZE);
}

void	draw_map(t_game *img)
{
	int	i;
	int	j;

	i = -1;
	mlx_clear_window(img->mlx_ptr, img->win_ptr);
	while (img->map.plot[++i])
	{
		j = -1;
		while (img->map.plot[i][++j])
		{
			mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, \
			img->s_img.img, j * IMAGE_SIZE, i * IMAGE_SIZE);
			put_image(img->map.plot[i][j], i, j, *img);
		}
	}
}

int	init_game(t_game *img)
{
	img->mlx_ptr = mlx_init();
	if (!img->mlx_ptr)
	{
		free(img->mlx_ptr);
		handle_error_free(0, img->map.plot);
	}
	img->win_ptr = mlx_new_window(img->mlx_ptr, img->map.size.y * IMAGE_SIZE, \
	img->map.size.x * IMAGE_SIZE, "Welcome to So Long!");
	if (!img->win_ptr)
	{
		free(img->win_ptr);
		handle_error_free(0, img->map.plot);
	}
	create_images(img);
	draw_map(img);
	return (0);
}
