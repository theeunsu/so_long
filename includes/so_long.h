/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 00:38:37 by eahn              #+#    #+#             */
/*   Updated: 2024/06/11 15:45:42 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"

/* malloc, free, exit */
# include <stdlib.h>

/* open */
# include <fcntl.h>

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_img
{
	void	*space;
	void	*collec;
	void	*exit;
	void	*player;
	void	*wall;
}			t_img;

typedef struct s_map
{
	char	*line;
	int		width;
	int		height;
}			t_map;

typedef struct s_path
{
	char	*visited;
	int		valid_path;
	int		player_x;
	int		player_y;
	int		player_loc;
	int		collec_cnt;
}			t_path;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	map;
	t_path	path;
	int		collected;
	int		collec;
	int		exit;
	int		player;
	int		step;
}			t_game;

/* image.c */
t_img		img_init(void *mlx);
void		put_img(t_game *g, int w, int h);
void		set_img(t_game *game);

/* map.c */
void		check_file_extension(char *filename);
void		read_map(char *filename, t_game *game);
void		check_map_grid(t_game *game);
void		check_map_components(t_game *game);

/* exit_error.c */
void		print_error(char *message);
int			clear_game(t_game *g);
int			exit_game(t_game *game);

/* move.c */
void		move(t_game *g, int dx, int dy);
void		move_w(t_game *game);
void		move_a(t_game *game);
void		move_s(t_game *game);
void		move_d(t_game *game);

/* path.c */
void		check_path(t_game *game);
void		init_visited(t_game *game);
void		search_path(t_game *game, int x, int y);

/* utils.c */
void		print_error(char *message);
int			ft_strlen(char *str);
char		*sl_strdup(char *str);
char		*sl_strjoin(char *s1, char *s2);

#endif
