/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:00:13 by rothiery          #+#    #+#             */
/*   Updated: 2024/08/08 11:00:17 by rothiery         ###   ########.fr       */
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

int	exit_pos(t_game *game, int e, int i, int j)
{
	e++;
	game->ex = j;
	game->ey = i;
	return (e);
}
