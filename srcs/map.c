/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 23:13:28 by eahn              #+#    #+#             */
/*   Updated: 2024/06/11 15:44:58 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// check if file extension is .ber
void	check_file_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (filename[len - 4] != '.' || filename[len - 3] != 'b' || filename[len
			- 2] != 'e' || filename[len - 1] != 'r')
		print_error("Invalid file extension.\n");
}

// determine width of map based on first line
// by reading map line by line, increment height
// append each line to game->map.line with strjoin
void	read_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error("Failed to open file.\n");
	check_file_extension(filename);
	line = get_next_line(fd);
	if (!line)
		print_error("File is empty.\n");
	game->map.width = ft_strlen(line) - 1;
	game->map.height = 0;
	game->map.line = sl_strdup(line);
	free(line);
	while (line)
	{
		game->map.height++;
		line = get_next_line(fd);
		if (line)
			game->map.line = sl_strjoin(game->map.line, line);
	}
	close(fd);
}

// i < width: first row | i >= len - width: last row
// i % width == 0: leftmost column
// i % width == width - 1: rightmost column
void	check_map_grid(t_game *game)
{
	int	i;
	int	len;
	int	width;
	int	total;

	i = 0;
	len = ft_strlen(game->map.line);
	width = game->map.width;
	total = game->map.height * game->map.width;
	if (total != len)
		print_error("Map must be rectangular.\n");
	while (i < len)
	{
		if (i < width || i >= len - width || i % width == 0 || i
			% width == width - 1)
		{
			if (game->map.line[i] != '1')
				print_error("Map must be surrounded by walls.");
		}
		i++;
	}
}

// check number of components for "E, C, P" is valid
// check any unknown characters other than "E, C, P, 1, 0"
void	check_map_components(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(game->map.line) - 1)
	{
		if (game->map.line[i] == 'E')
			game->exit++;
		else if (game->map.line[i] == 'P')
			game->player++;
		else if (game->map.line[i] == 'C')
			game->collected++;
		if (game->map.line[i] != 'E' && game->map.line[i] != 'P'
			&& game->map.line[i] != 'C' && game->map.line[i] != '1'
			&& game->map.line[i] != '0')
			print_error("Invalid character(s).\n");
	}
	if (game->exit != 1 || game->player != 1 || game->collected == 0)
		print_error("Invalid number of components.\n");
}
