/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:00:46 by abashir           #+#    #+#             */
/*   Updated: 2024/01/29 16:24:34 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define WIDTH 1080
# define HEIGHT 720
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124
# define TILE_3D 64
# define SPEED 0.1
# define ROTATE 0.4
# define FOV 60
# define EAST 1
# define NORTH 2
# define WEST 3
# define SOUTH 4
# define MAP_KEY 46
# define MOUSE 11

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_img
{
	void		*ptr;
	char		*addr;
	int			bitsinpixel;
	int			line_bytes;
	int			endian;
	int			w;
	int			h;
}				t_img;

typedef struct s_texture
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
	int			floor[6];
	int			ceiling[6];
	t_img		no_img;
	t_img		so_img;
	t_img		we_img;
	t_img		ea_img;
}				t_texture;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir;
	char		dir_char;
	double		rotate;
	double		stepx;
	double		stepy;
}				t_player;

typedef struct s_map
{
	int			width;
	int			height;
	char		**split;
	char		**map;
	t_player	player;
}				t_map;

typedef struct s_ray
{
	double		x_h;
	double		y_h;
	double		x_v;
	double		y_v;
	double		ply_x;
	double		ply_y;
	double		angle;
	double		v_dist;
	double		h_dist;
	double		height;
	int			hit_vert;
	int			hit_horz;
	double		top_pix;
	double		bot_pix;
	int			is_inter;
}				t_ray;

typedef struct s_delta
{
	int			current_x;
	int			current_y;
	int			previous_x;
	int			previous_y;
}				t_delta;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*array;
	int			tile;
	bool		is_2d;
	bool		show_map;
	bool		enable_mouse;
	t_texture	*texture;
	t_img		img;
	t_player	ply;
	t_ray		*ray;
	t_map		*map;
	t_delta		mouse;
}				t_game;

#endif
