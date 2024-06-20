/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 23:13:31 by eahn              #+#    #+#             */
/*   Updated: 2024/06/11 15:44:55 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img	img_init(void *mlx)
{
	t_img	img;
	int		w;
	int		h;

	img.space = mlx_xpm_file_to_image(mlx, "./images/space.xpm", &w, &h);
	img.wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &w, &h);
	img.player = mlx_xpm_file_to_image(mlx, "./images/player.xpm", &w, &h);
	img.collec = mlx_xpm_file_to_image(mlx, "./images/collec.xpm", &w, &h);
	img.exit = mlx_xpm_file_to_image(mlx, "./images/exit.xpm", &w, &h);
	return (img);
}

void	put_img(t_game *g, int w, int h)
{
	if (g->map.line[h * g->map.width + w] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img.wall, w * 64, h * 64);
	else if (g->map.line[h * g->map.width + w] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->img.collec, w * 64, h * 64);
	else if (g->map.line[h * g->map.width + w] == 'P')
	{
		g->path.player_x = w;
		g->path.player_y = h;
		g->path.player_loc = w + h * g->map.width;
		mlx_put_image_to_window(g->mlx, g->win, g->img.player, w * 64, h * 64);
	}
	else if (g->map.line[h * g->map.width + w] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->img.exit, w * 64, h * 64);
	else
		mlx_put_image_to_window(g->mlx, g->win, g->img.space, w * 64, h * 64);
}

void	set_img(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	while (h < game->map.height)
	{
		w = 0;
		while (w < game->map.width)
		{
			put_img(game, w, h);
			w++;
		}
		h++;
	}
}
