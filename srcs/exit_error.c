/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 23:53:55 by eahn              #+#    #+#             */
/*   Updated: 2024/06/20 15:03:13 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_error(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	exit(1);
}

int	clear_game(t_game *g)
{
	g->step++;
	ft_printf("Well done! You've taken %d steps.", g->step);
	exit(0);
}

int	exit_game(t_game *game)
{
	if (game->img.space)
		mlx_destroy_image(game->mlx, game->img.space);
	if (game->img.collec)
		mlx_destroy_image(game->mlx, game->img.collec);
	if (game->img.exit)
		mlx_destroy_image(game->mlx, game->img.exit);
	if (game->img.player)
		mlx_destroy_image(game->mlx, game->img.player);
	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->map.line)
		free(game->map.line);
	exit(0);
}
