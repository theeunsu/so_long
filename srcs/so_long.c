/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 22:45:56 by eahn              #+#    #+#             */
/*   Updated: 2024/06/20 15:00:31 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	press_key(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move_w(game);
	else if (keycode == KEY_S)
		move_s(game);
	else if (keycode == KEY_A)
		move_a(game);
	else if (keycode == KEY_D)
		move_d(game);
	else if (keycode == KEY_ESC)
		exit_game(game);
	return (0);
}

void	init_struct(t_game *game)
{
	game->collected = 0;
	game->collec = 0;
	game->exit = 0;
	game->player = 0;
	game->step = 0;
	game->path.visited = 0;
	game->path.valid_path = 0;
	game->path.player_x = 0;
	game->path.player_y = 0;
	game->path.player_loc = 0;
	game->path.collec_cnt = 0;
}

void	game_init(t_game *game, char *map)
{
	read_map(map, game);
	check_map_grid(game);
	check_map_components(game);
	game->mlx = mlx_init();
	game->img = img_init(game->mlx);
	game->win = mlx_new_window(game->mlx, game->map.width * 64, game->map.height
			* 64, "so_long");
	set_img(game);
	check_path(game);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		print_error("Map is missing.\n");
	game = malloc(sizeof(t_game));
	init_struct(game);
	game_init(game, av[1]);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &press_key, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}
