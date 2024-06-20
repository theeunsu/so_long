/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:57:16 by eahn              #+#    #+#             */
/*   Updated: 2024/06/11 15:45:05 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// check if path can reach out to exit
// check if all items are collected
void	check_path(t_game *game)
{
	game->path.collec_cnt = game->collected;
	init_visited(game);
	search_path(game, game->path.player_x, game->path.player_y);
	free(game->path.visited);
	if (game->path.valid_path != 1 || game->path.collec_cnt != 0)
		print_error("Invalid path.\n");
}

// initialize all in visited array to '0' (unvisited)
void	init_visited(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(game->map.line);
	game->path.visited = (char *)malloc(len);
	if (!game->path.visited)
		print_error("Allocation failed.\n");
	while (i < len)
		game->path.visited[i++] = '0';
}

// mark current position as visited ('1')
// recursively explores all valid positions
void	search_path(t_game *game, int x, int y)
{
	const int	dx[4] = {1, 0, 0, -1};
	const int	dy[4] = {0, 1, -1, 0};
	int			nx;
	int			ny;
	int			i;

	game->path.visited[x + y * game->map.width] = '1';
	if (game->map.line[x + y * game->map.width] == 'C')
		game->path.collec_cnt--;
	if (game->map.line[x + y * game->map.width] == 'E')
	{
		game->path.valid_path = 1;
		return ;
	}
	i = -1;
	while (++i < 4)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if (game->map.line[nx + ny * game->map.width] != '1'
			&& game->path.visited[nx + ny * game->map.width] != '1' && (nx >= 0
				&& nx < game->map.width) && (ny >= 0 && ny < game->map.height))
			search_path(game, nx, ny);
	}
}
