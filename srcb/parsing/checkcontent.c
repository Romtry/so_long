/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:17:37 by rothiery          #+#    #+#             */
/*   Updated: 2024/08/05 09:17:38 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	t_pos(t_game *game, int i)
{
	game->t_pos[++i] = malloc(sizeof(int));
	game->t_pos[i][0] = 0;
	game->t_pos[++i] = NULL;
}

void	turret_pos(t_game *game)
{
	int	y;
	int	x;
	int	i;

	i = -1;
	y = -1;
	x = -1;
	while (game->map[++y])
	{
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'T')
			{
				game->t_pos[++i] = malloc(sizeof(int) * 4);
				game->t_pos[i][0] = y;
				game->t_pos[i][1] = x;
				game->t_pos[i][2] = 0;
				game->t_pos[i][3] = 1;
			}
		}
		x = -1;
	}
	if (game->t_pos)
		t_pos(game, i);
}

void	check_count(t_game *game)
{
	if (game->pc != 1)
		print_error(7, -1, game);
	else if (game->coin <= 0)
		print_error(9, -1, game);
	if (game->tc != 0)
		game->t_pos = malloc(sizeof(char *) * (game->tc + 2));
	turret_pos(game);
	map_cpy(game);
	player_pos(game);
	algo_ff(game);
}

void	content_count(t_game *game, char c, int y, int x)
{
	if (c == 'E')
		exit_pos(game, y, x);
	else if (c == 'C')
		game->coin++;
	else if (c == 'P')
		game->pc++;
	else if (c == 'T')
	{
		safe_dist(game, y, x);
		game->tc++;
	}
}

void	check_content(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (game->map[++y])
	{
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'E' || game->map[y][x] == 'P'
				|| game->map[y][x] == 'C' || game->map[y][x] == 'T')
				content_count(game, game->map[y][x], y, x);
			else if (game->map[y][x] != '0' && game->map[y][x] != '1')
				print_error(8, -1, game);
		}
		x = -1;
	}
	check_count(game);
}
