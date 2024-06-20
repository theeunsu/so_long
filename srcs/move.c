/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 23:01:04 by eahn              #+#    #+#             */
/*   Updated: 2024/06/11 15:45:02 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// delta x, delta y: movement amount
void	move(t_game *g, int dx, int dy)
{
	int	i;
	int	new_pos;

	i = 0;
	while (i < ft_strlen(g->map.line))
	{
		if (g->map.line[i] == 'P')
		{
			new_pos = i + dx + dy * g->map.width;
			if (g->map.line[new_pos] == 'C')
				g->collec++;
			if (g->map.line[new_pos] == 'E' && g->collected == g->collec)
				clear_game(g);
			else if (g->map.line[new_pos] != '1' && g->map.line[new_pos] != 'E')
			{
				g->map.line[i] = '0';
				g->map.line[new_pos] = 'P';
				g->step++;
				ft_printf("%d\n", g->step);
				set_img(g);
			}
			break ;
		}
		i++;
	}
}

// move up
void	move_w(t_game *game)
{
	move(game, 0, -1);
}

// move left
void	move_a(t_game *game)
{
	move(game, -1, 0);
}

// move down
void	move_s(t_game *game)
{
	move(game, 0, 1);
}

// move right
void	move_d(t_game *game)
{
	move(game, 1, 0);
}
