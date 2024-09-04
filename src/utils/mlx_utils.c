/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:03:59 by rothiery          #+#    #+#             */
/*   Updated: 2024/08/12 11:04:00 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Exit bleu
// Player rouge
// Coin jaune
// Void blanc
// Wall gris

void	after_move(t_game *game, int y, int x)
{
	put_pixel(game, y * PIXEL, x * PIXEL, game->map[y][x]);
	put_pixel(game, game->py * PIXEL, game->px * PIXEL,
		game->map[game->py][game->px]);
	game->px = x;
	game->py = y;
}

void	moves(int x, int y, t_game *game)
{
	static int	on_ex;

	if (game->map[y][x] == '1')
		return ;
	if (on_ex == 1)
	{
		game->map[game->py][game->px] = 'E';
		on_ex = 0;
	}
	else
		game->map[game->py][game->px] = '0';
	if (game->map[y][x] == 'C')
		game->coin--;
	else if (game->map[y][x] == 'E')
	{
		on_ex = 1;
		if (game->coin == 0)
			game_end(game);
	}
	if (game->map[y][x] == '0' || game->map[y][x] == 'C'
		|| game->map[y][x] == 'E')
		game->map[y][x] = 'P';
	after_move(game, y, x);
}

int	key_func(int keycode, t_game *game)
{
	if (keycode == ESC)
		game_end(game);
	else if (keycode == UP)
		moves(game->px, game->py - 1, game);
	else if (keycode == LEFT)
		moves(game->px - 1, game->py, game);
	else if (keycode == DOWN)
		moves(game->px, game->py + 1, game);
	else if (keycode == RIGHT)
		moves(game->px + 1, game->py, game);
	return (0);
}

void	mlx_aff(t_game *game)
{
	game->aff.mlx = mlx_init();
	game->aff.mlx_win = mlx_new_window(game->aff.mlx, game->width * PIXEL,
			game->height * PIXEL, "So_long");
	mlx_draw(game);
	mlx_hook(game->aff.mlx_win, 2, 1L << 0, key_func, game);
	mlx_hook(game->aff.mlx_win, 17, 0L, game_end, game);
	mlx_loop(game->aff.mlx);
}
