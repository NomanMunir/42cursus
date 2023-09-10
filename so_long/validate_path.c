/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:42:08 by nmunir            #+#    #+#             */
/*   Updated: 2023/09/10 19:20:52 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y >= size.y || cur.x >= size.x || \
	(tab[cur.x][cur.y] != to_fill && tab[cur.x][cur.y] != 'C'))
		return ;
	tab[cur.x][cur.y] = 'F';
	flood_fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	flood_fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	flood_fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	flood_fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

#include <stdio.h>
void ft_print(char **tab)
{
	int i, j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 34)
		{
			printf("%c", tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	check_path(t_map m, char *av)
{
	int		i;
	t_point	pt;
	char	**f;
	t_map	game;

	f = create_map(av, &game);
	if (!f)
		handle_error_free(0, m.plot);
	i = 0;
	f[m.s.x][m.s.y] = '0';
	flood_fill(f, m.size, m.s, '0');
	if (f[m.e.x - 1][m.e.y] != 'F' && f[m.e.x + 1][m.e.y] != 'F' && \
	f[m.e.x][m.e.y + 1] != 'F' && f[m.e.x][m.e.y - 1] != 'F')
		handle_error_free(9, m.plot);
	while (i < m.c)
	{
		pt = m.c_ar[i];
		if (f[pt.x - 1][pt.y] != 'F' && f[pt.x + 1][pt.y] != 'F' && \
		f[pt.x][pt.y + 1] != 'F' && f[pt.x][pt.y - 1] != 'F')
			handle_error_free(9, m.plot);
		i++;
	}
	ft_print(f);
	ft_free_arr(f);
	free (m.c_ar);
}

void	find_collects(t_map *game, int c)
{
	int			i;
	int			j;
	int			k;
	t_point		*collect;

	i = 0;
	k = 0;
	collect = malloc(sizeof(t_point) * c);
	if (!collect)
		handle_error_free(0, game->plot);
	while (i < game->size.x)
	{
		j = 0;
		while (j < game->size.y)
		{
			if (game->plot[i][j] == 'C')
				collect[k++] = (t_point){i, j};
			j++;
		}
		i++;
	}
	game->c_ar = collect;
}
