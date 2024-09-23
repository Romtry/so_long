/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:37:47 by rothiery          #+#    #+#             */
/*   Updated: 2024/09/11 09:37:49 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	no_wall2(t_game *game, int i, int t)
{
	int	index;

	index = 1;
	if (i == 2)
	{
		while ((game->map[game->t_pos[t][0] + index][game->t_pos[t][1]] != '1'
			&& game->map[game->t_pos[t][0] + index][game->t_pos[t][1]] != 'P')
			&& index < 3)
			index++;
		if (game->map[game->t_pos[t][0] + index][game->t_pos[t][1]] == 'P')
			death(game, game->t_pos[t][0], game->t_pos[t][1], t);
	}
	else if (i == 3)
	{
		while ((game->map[game->t_pos[t][0]][game->t_pos[t][1] - index] != '1'
			&& game->map[game->t_pos[t][0]][game->t_pos[t][1] - index] != 'P')
			&& index < 3)
			index++;
		if (game->map[game->t_pos[t][0]][game->t_pos[t][1] - index] == 'P')
			death(game, game->t_pos[t][0], game->t_pos[t][1], t);
	}
}

void	no_wall(t_game *game, int i, int t)
{
	int	index;

	index = 1;
	if (i == 0)
	{
		while ((game->map[game->t_pos[t][0] - index][game->t_pos[t][1]] != '1'
			&& game->map[game->t_pos[t][0] - index][game->t_pos[t][1]] != 'P')
			&& index < 3)
			index++;
		if (game->map[game->t_pos[t][0] - index][game->t_pos[t][1]] == 'P')
			death(game, game->t_pos[t][0], game->t_pos[t][1], t);
	}
	else if (i == 1)
	{
		while ((game->map[game->t_pos[t][0]][game->t_pos[t][1] + index] != '1'
			&& game->map[game->t_pos[t][0]][game->t_pos[t][1] + index] != 'P')
			&& index < 3)
			index++;
		if (game->map[game->t_pos[t][0]][game->t_pos[t][1] + index] == 'P')
			death(game, game->t_pos[t][0], game->t_pos[t][1], t);
	}
	else
		no_wall2(game, i, t);
}

void	turret_shot(t_game *game)
{
	int	t;

	t = -1;
	while (++t < game->tc)
	{
		if (game->t_pos[t][3] == 1)
			no_wall(game, game->t_pos[t][2], t);
	}
}

void	aff_turret(t_game *game, int n)
{
	static int	i;
	int			t;

	t = -1;
	if (game->t_pos && (i != game->t_pos[game->tc][0] || n == 1))
	{
		while (++t < game->tc)
		{
			if (game->t_pos[t][2] != 5)
				turret_moves(game, t, game->t_pos[t][2]);
		}
		i = game->t_pos[game->tc][0];
	}
}

void	turret(t_game *game)
{
	static int		count;

	count++;
	if (count >= 5)
	{
		game->t_pos[game->tc][0] = game->t_pos[game->tc][0] + 1;
		count = 0;
	}
	aff_turret(game, 0);
	turret_shot(game);
}
