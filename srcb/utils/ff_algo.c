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

void	recu_next(t_game *game, int n, int *count)
{
	if (n == 0)
	{
		game->x++;
		void_next(game, count);
		game->x--;
	}
	else if (n == 1)
	{
		game->y++;
		void_next(game, count);
		game->y--;
	}
	else if (n == 2)
	{
		game->x--;
		void_next(game, count);
		game->x++;
	}
	else if (n == 3)
	{
		game->y--;
		void_next(game, count);
		game->y++;
	}
}

int	void_next(t_game *game, int *count)
{
	int	n;

	if (game->cpy[game->y][game->x] == 'C'
		|| game->cpy[game->y][game->x] == 'E')
		*count = *count + 1;
	game->cpy[game->y][game->x] = 'X';
	if (game->cpy[game->y][game->x + 1] != '1'
		&& game->cpy[game->y][game->x + 1] != 'X')
		n = 0;
	else if (game->cpy[game->y + 1][game->x] != '1'
		&& game->cpy[game->y + 1][game->x] != 'X')
		n = 1;
	else if (game->cpy[game->y][game->x - 1] != '1'
		&& game->cpy[game->y][game->x - 1] != 'X')
		n = 2;
	else if (game->cpy[game->y - 1][game->x] != '1'
		&& game->cpy[game->y - 1][game->x] != 'X')
		n = 3;
	else
		return (1);
	recu_next(game, n, count);
	void_next(game, count);
	return (0);
}

void	exit_pos(t_game *game, int i, int j)
{
	static int	count;

	count++;
	if (count > 1)
		print_error(6, -1, game);
	game->ex = j;
	game->ey = i;
	return ;
}

void	algo_ff(t_game *game)
{
	int	count;

	count = 0;
	game->x = game->px;
	game->y = game->py;
	game->cpy[game->y][game->x] = 'X';
	while (void_next(game, &count) != 1)
	{
		game->x = game->px;
		game->y = game->py;
	}
	if (count != game->coin + 1)
		print_error(10, -1, game);
}
