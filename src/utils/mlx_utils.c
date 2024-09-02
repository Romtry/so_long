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
	char	*dst;
	int		i;
	int		j;

	i = x + 20;
	j = y + 20;
	while (y < j)
	{
		while (x < i)
		{
			dst = game->aff.addr + (y * game->aff.length + x * (game->aff.bpp / 8));
			*(unsigned int*)dst = set_color(c);
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
// void	game_end(int n, t_game *game)
// {
// }

void	moves(int x, int y, t_game *game)
{
	static int	on_ex;

	if (game->map[y][x] == '0')
		game->map[y][x] = 'P';
	// if (game->map[y][x] == 'E')
	// {
	// 	on_ex = 1;
	// 	game->map[y][x] = 'P';
	// 	if (game->coin == 0)
	// 	{
	// 		mlx_destroy_window(game->mlx, game->mlx_win);
	// 		free_max(-1, game);
	// 		exit (0);
	// 	}
	// if (game->map[y][x] == 'C')
	// 	game->coin--;
	// else if (game->map[y][x] == '')
	else
		return ;
	if (on_ex == 1)
	{
		game->map[game->py][game->px] = 'E';
		on_ex = 0;
	}
	else
		game->map[game->py][game->px] = '0';
	game->px = x;
	game->py = y;
	printus(game->map);
	mlx_clear_window(game->aff.mlx, game->aff.mlx_win);
	mlx_draw(game);
}

int	key_func(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(game->aff.mlx, game->aff.mlx_win);
		free_max(-1, game);
		exit (0);
	}
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
	game->aff.mlx_win = mlx_new_window(game->aff.mlx, 800, 500, "So_long");
	game->aff.img = mlx_new_image(game->aff.mlx, 800, 500);
	game->aff.addr = mlx_get_data_addr(game->aff.img, &game->aff.bpp, &game->aff.length,
							&game->aff.endian);
	mlx_draw(game);
	mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win, game->aff.img, 0, 0);
	mlx_hook(game->aff.mlx_win, 2, 1L<<0, key_func, game);
	mlx_loop(game->aff.mlx);
}
