/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:13:24 by rothiery          #+#    #+#             */
/*   Updated: 2024/08/06 12:13:26 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_pos(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (game->map[++i])
	{
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
			{
				game->px = j;
				game->py = i;
			}
		}
		j = -1;
	}
}

void	map_cpy(t_game *game)
{
	int		i;
	int		j;

	j = -1;
	i = -1;
	game->cpy = malloc(sizeof(char *) * ((int)game->height + 1));
	while (++i < (int)game->height)
	{
		game->cpy[i] = malloc(sizeof(char) * (int)game->width + 1);
		while (++j < (int)game->width)
		{
			game->cpy[i][j] = game->map[i][j];
		}
		game->cpy[i][j] = '\0';
		j = -1;
	}
	game->cpy[i] = NULL;
}
