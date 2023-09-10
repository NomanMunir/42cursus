/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:20:54 by nmunir            #+#    #+#             */
/*   Updated: 2023/09/10 13:12:09 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	imgs_destroy(t_game	*img)
{
	if (img->s_img.img)
		mlx_destroy_image(img->mlx_ptr, img->s_img.img);
	else if (img->c_img.img)
		mlx_destroy_image(img->mlx_ptr, img->c_img.img);
	else if (img->e_img.img)
		mlx_destroy_image(img->mlx_ptr, img->e_img.img);
	else if (img->w_img.img)
		mlx_destroy_image(img->mlx_ptr, img->w_img.img);
	else if (img->p_img.img)
		mlx_destroy_image(img->mlx_ptr, img->p_img.img);
}

int	on_destroy(t_game *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_free_arr(data->map.plot);
	imgs_destroy(data);
	free(data->mlx_ptr);
	ft_putstr_fd("Window closed!\n", 2);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_game *img)
{
	if (keycode == RIGHT)
		move(img, 1, 0);
	else if (keycode == LEFT)
		move(img, -1, 0);
	else if (keycode == UP)
		move(img, 0, -1);
	else if (keycode == DOWN)
		move(img, 0, 1);
	else if (keycode == ESC)
		on_destroy(img);
	return (0);
}

void	ft_event(t_game *img)
{
	img->steps = 0;
	mlx_hook(img->win_ptr, 2, 1L << 0, key_press, img);
	mlx_hook(img->win_ptr, 17, 0L, on_destroy, img);
	mlx_loop(img->mlx_ptr);
}
