/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:10:04 by abashir           #+#    #+#             */
/*   Updated: 2024/01/29 17:50:40 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libs/libft/libft.h"
# include "../libs/minilibx/mlx.h"
# include "structs.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int			panic(char *str);
int			check_input(int ac, char **av);
t_texture	*init_texture(char **split);
void		ft_skip_spaces(char *str, int *i);
int			init_map(char **split, t_map *map);
char		*ft_joinfree(char *s1, char *buf);
int			open_file(char *path);
void		free_array(char **array);
int			destroy_texture(t_game *game, t_texture *t);
bool		my_strchr(char *str, char c);
int			my_atoi(const char *str);
int			find_ptr(char **split);
char		*read_file(char *av);
t_map		*create_map(char *array, t_game *game);
void		ft_free_game(t_game *game);
int			map_checker(t_map *map);
char		*read_file(char *av);
int			check_lines(char **split);
void		flood_fill(char **tab, t_point size, t_point cur, char to_fill);
int			check_around(char **b_map);
char		**add_border(t_map *map);
int			init_game(t_game *game);
int			draw_map(t_game *game);
void		mlx_free(t_game *game);
double		drad(double deg);
int			in_range(double angle, double start, double end);
int			key_press(int keycode, t_game *game);
void		init_hooks(t_game *game);
int			on_destroy(t_game *game);
int			create_trgb(int t, int r, int g, int b);
double		find_distance(t_ray *ray, int flag);
void		set_boundary(t_game *game, t_ray *ray);
void		set_range(t_game *game, t_ray *ray);
int			in_boundry(t_game *game, double x, double y);
void		find_h_intersection(t_game *game, t_ray *ray);
void		find_v_intersection(t_game *game, t_ray *ray);
int			in_range(double angle, double start, double end);
void		find_first(t_game *game, t_ray *ray);
int			draw_3d(t_game *game);
void		set_color(t_img *data, int x, int y, int color);
double		norm_angle(double angle);
int			create_texture(t_game *game, t_texture *t);
int			destroy_texture(t_game *game, t_texture *t);
void		hook(t_game *game, int key, int mouse);
void		move_ply(t_game *game, double move_x, double move_y);
void		set_rotation(t_game *game, int key, int mouse);
void		set_move(t_game *game, int key, double *move_x, double *move_y);
void		draw_walls_3d(t_game *game);
void		init_rays_3d(t_game *game);

#endif