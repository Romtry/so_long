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

void	check_count(t_game *game)
{
	if (game->pc != 1)
		print_error(7, -1, game);
	else if (game->coin <= 0)
		print_error(9, -1, game);
	flood_fill(game);
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
		game->tc++;
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
				|| game->map[y][x] == 'C')
				content_count(game, game->map[y][x], y, x);
			else if (game->map[y][x] != '0' && game->map[y][x] != '1')
				print_error(8, -1, game);
		}
		x = -1;
	}
	check_count(game);
}
