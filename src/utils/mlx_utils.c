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

int	set_color(char	c)
{
	if (c == 'E')
		return (0x1A00FF);
	else if (c == 'P')
		return (0xFF0000);
	else if (c == 'C')
		return (0xFFEF00);
	else if (c == '0')
		return (0xFFFFFF);
	else if (c == '1')
		return (0x6B6B6B);
	else
		return (0x000000);
}

void	put_pixel(t_game *game, int y, int x, char c)
{
	int		i;
	int		j;

	i = x + 20;
	j = y + 20;
	while (y < j)
	{
		while (x < i)
		{
			mlx_pixel_put(game->aff.mlx, game->aff.mlx_win, x, y, set_color(c));
			x++;
		}
		x = i - 20;
		y++;
	}
}

void	mlx_draw(t_game *game)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	while (game->map[++y] != NULL)
	{
		while (game->map[y][++x])
			put_pixel(game, y * 20, x * 20, game->map[y][x]);
		x = -1;
	}
}
int	game_end(t_game *game)
{
	mlx_clear_window(game->aff.mlx, game->aff.mlx_win);
	mlx_destroy_window(game->aff.mlx, game->aff.mlx_win);
	free_max(-1, game);
	exit (0);
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
	if (game->map[y][x] == '0' || game->map[y][x] == 'C' || game->map[y][x] == 'E')
		game->map[y][x] = 'P';
	game->px = x;
	game->py = y;
	mlx_draw(game);
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
	game->aff.mlx_win = mlx_new_window(game->aff.mlx, game->width * 20, game->height * 20, "So_long");
	mlx_draw(game);
	mlx_hook(game->aff.mlx_win, 2, 1L<<0, key_func, game);
	mlx_hook(game->aff.mlx_win, 17, 0L, game_end, game);
	mlx_loop(game->aff.mlx);
}
