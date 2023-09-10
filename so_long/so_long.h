/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:12:52 by abashir           #+#    #+#             */
/*   Updated: 2023/09/10 13:24:57 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "libft/libft.h"
# include <unistd.h>
# include "minilibx/mlx.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>

# define IMAGE_SIZE 42
# define P_PATH "./assets/player.xpm"
# define W_PATH "./assets/wall.xpm"
# define C_PATH "./assets/collectable.xpm"
# define E_PATH "./assets/exit.xpm"
# define S_PATH "./assets/background.xpm"
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_img
{
	void			*img;
	int				w;
	int				h;
}				t_img;				

typedef struct s_map
{
	t_point			size;
	t_point			s;
	t_point			e;
	int				c;
	t_point			*c_ar;
	char			**plot;
}				t_map;

typedef struct s_game {
	void			*mlx_ptr;
	void			*win_ptr;
	int				steps;
	t_img			s_img;
	t_img			e_img;
	t_img			w_img;
	t_img			p_img;
	t_img			c_img;
	struct s_map	map;
}				t_game;

void	flood_fill(char **tab, t_point size, t_point cur, char to_fill);
void	is_map_rect(t_map map);
void	is_map_closed(t_map map);
int		counter(t_map *game, char ch);
void	count(t_map *game);
void	check_map(t_map *game, char *av);
int		ft_strspn(const char *s, char c);
void	find_collects(t_map *game, int c);
void	check_path(t_map m, char *av);
char	**create_map(char *argv, t_map *game);
void	handle_error(int error);
void	contain_invalid(t_map *game);
void	is_file_valid(int argc, char **argv);
int		key_press(int keycode, t_game *img);
void	ft_event(t_game *img);
int		on_destroy(t_game *data);
void	draw_map(t_game *img);
void	put_image(char c, int x, int y, t_game img);
void	move(t_game *img, int x, int y);
void	ft_free_arr(char **p);
void	create_images(t_game *img);
t_img	create_image_ptr(void *mlx, char *path);
int		init_game(t_game *img);
void	handle_error_free(int error, char **map);
void	imgs_destroy(t_game	*img);
int		ft_strc(const char *s, int c);

#endif
