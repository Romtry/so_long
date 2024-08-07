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

#include "../../includes/so_long.h"

int	void_next(t_game *game)
{
	if (game->cpy[game->py][game->px + 1] != '1')
		game->px++;
	else if (game->cpy[game->py + 1][game->px] != '1')
		game->py++;
	else if (game->cpy[game->py][game->px - 1] != '1')
		game->px--;
	else if (game->cpy[game->py - 1][game->px] != '1')
		game->py--;
	else
		return (1);
	game->cpy[game->py][game->px] = 'X';
	return(0);
}

void	algo_ff(t_game *game)
{
	int	c;
	int	e;

	c = 0;
	e = 0;
	while (void_next(game) != 1)
	{
		if (game->cpy[game->py][game->px] == 'C')
			c++;
		if (game->cpy[game->py][game->px] == 'E')
			e++;
		
	}

}

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
