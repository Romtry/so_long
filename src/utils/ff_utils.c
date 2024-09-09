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
