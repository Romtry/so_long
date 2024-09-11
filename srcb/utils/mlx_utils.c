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

#include "so_long.h"

// Exit bleu
// Player rouge
// Coin jaune
// Void blanc
// Wall gris

void	after_move(t_game *game, int y, int x, char m)
{
	if (m == 'L')
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.pl, x * PIXEL, y * PIXEL);
	else if (m == 'T')
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.pt, x * PIXEL, y * PIXEL);
	else if (m == 'D')
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.p, x * PIXEL, y * PIXEL);
	else if (m == 'R')
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.pr, x * PIXEL, y * PIXEL);
	put_imgs(game, game->py * PIXEL, game->px * PIXEL,
		game->map[game->py][game->px]);
	game->px = x;
	game->py = y;
	game->moves++;
	if (game->str)
	{
		free(game->str);
		free(game->shdw);
	}
	mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win, game->img.wall, 1 * PIXEL, 0);
	game->str = ft_strjoin("MOVES = ", ft_itoa(game->moves));
	mlx_string_put(game->aff.mlx, game->aff.mlx_win, 11, 11, 0, game->str);
	game->shdw = ft_strjoin("MOVES = ", ft_itoa(game->moves));
	mlx_string_put(game->aff.mlx, game->aff.mlx_win, 10, 10, 0xFFFFFF, game->shdw);
}

void	coin_func(t_game *game)
{
	game->coin--;
	if (game->coin == 0)
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.exit2, game->ex * PIXEL, game->ey * PIXEL);
}

void	on_ex_f(t_game *game, int y, int x, char m)
{
	if (game->coin == 0)
	{
		game->ret = 2;
		game_end(game);
	}
	put_imgs(game, game->py * PIXEL, game->px * PIXEL,
		game->map[game->py][game->px]);
	if (m == 'L')
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.epl, x * PIXEL, y * PIXEL);
	else if (m == 'T')
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.ept, x * PIXEL, y * PIXEL);
	else if (m == 'D')
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.ep, x * PIXEL, y * PIXEL);
	else if (m == 'R')
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.epr, x * PIXEL, y * PIXEL);
	game->px = x;
	game->py = y;
}

// void	enemies(t_game *game)
// {
	
// }

void	moves(int x, int y, t_game *game, char m)
{
	static char	p_on;

	if (game->map[y][x] == '1')
		return ;
	if (p_on == 0 || p_on == 'C')
		game->map[game->py][game->px] = '0';
	else
		game->map[game->py][game->px] = p_on;
	if (game->map[y][x] == 'E')
		on_ex_f(game, y, x, m);
	else if (game->map[y][x] == 'C')
		coin_func(game);
	p_on = game->map[y][x];
	if (game->map[y][x] != 'E')
		after_move(game, y, x, m);
	enemies(game);
}

int	key_func(int keycode, t_game *game)
{
	if (keycode == ESC)
		game_end(game);
	if (game->alive == 0)
	{
		if (keycode == UP)
			moves(game->px, game->py - 1, game, 'T');
		else if (keycode == LEFT)
			moves(game->px - 1, game->py, game, 'L');
		else if (keycode == DOWN)
			moves(game->px, game->py + 1, game, 'D');
		else if (keycode == RIGHT)
			moves(game->px + 1, game->py, game, 'R');
	}
	return (0);
}

void	mlx_aff(t_game *game)
{
	game->aff.mlx = mlx_init();
	if (!game->aff.mlx)
		exit(0);
	game->aff.mlx_win = mlx_new_window(game->aff.mlx, game->width * PIXEL,
			game->height * PIXEL, "So_long");
	init_imgs(game);
	game->alive = 0;
	game->str = NULL;
	game->shdw = NULL;
	game->moves = 0;
	mlx_draw(game);
	mlx_hook(game->aff.mlx_win, 2, 1L << 0, key_func, game);
	mlx_hook(game->aff.mlx_win, 17, 0L, game_end, game);
	mlx_loop(game->aff.mlx);
}
