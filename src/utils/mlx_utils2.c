/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:33:05 by rothiery          #+#    #+#             */
/*   Updated: 2024/09/04 13:33:07 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_p(t_game *game)
{
	mlx_destroy_image(game->aff.mlx, game->img.p);
	mlx_destroy_image(game->aff.mlx, game->img.pl);
	mlx_destroy_image(game->aff.mlx, game->img.pt);
	mlx_destroy_image(game->aff.mlx, game->img.pr);
	mlx_destroy_image(game->aff.mlx, game->img.ep);
	mlx_destroy_image(game->aff.mlx, game->img.epl);
	mlx_destroy_image(game->aff.mlx, game->img.ept);
	mlx_destroy_image(game->aff.mlx, game->img.epr);
}

int	game_end(t_game *game)
{
	destroy_p(game);
	mlx_destroy_image(game->aff.mlx, game->img.coin);
	mlx_destroy_image(game->aff.mlx, game->img.wall);
	mlx_destroy_image(game->aff.mlx, game->img.exit);
	mlx_destroy_image(game->aff.mlx, game->img.exit2);
	mlx_destroy_image(game->aff.mlx, game->img.floor);
	mlx_clear_window(game->aff.mlx, game->aff.mlx_win);
	mlx_destroy_window(game->aff.mlx, game->aff.mlx_win);
	if (game->str)
	{
		free(game->str);
		free(game->shdw);
	}
	if (game->ret == 0)
		write(1, "GAME CLOSE\n", 11);
	else
		write(1, "WIN !\n", 6);
	free_max(-1, game);
	exit (0);
}

void	put_imgs(t_game *game, int y, int x, char c)
{
	if (c == '1')
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.wall, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.coin, x, y);
	else if (c == '0')
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.floor, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.exit, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.p, x, y);
}

void	print_moves(t_game *game)
{
	game->str = ft_strjoin("MOVES = ", ft_itoa(game->moves));
	mlx_string_put(game->aff.mlx, game->aff.mlx_win, 11, 11, 0, game->str);
	game->shdw = ft_strjoin("MOVES = ", ft_itoa(game->moves));
	mlx_string_put(game->aff.mlx, game->aff.mlx_win, 10, 10, 0xFFFFFF,
		game->shdw);
}

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
	mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
		game->img.wall, 1 * PIXEL, 0);
	print_moves(game);
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
		game->ret = 1;
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
}

int	key_func(int keycode, t_game *game)
{
	if (keycode == ESC)
		game_end(game);
	else if (keycode == UP)
		moves(game->px, game->py - 1, game, 'T');
	else if (keycode == LEFT)
		moves(game->px - 1, game->py, game, 'L');
	else if (keycode == DOWN)
		moves(game->px, game->py + 1, game, 'D');
	else if (keycode == RIGHT)
		moves(game->px + 1, game->py, game, 'R');
	return (0);
}