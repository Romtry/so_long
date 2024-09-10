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

int	game_end(t_game *game, int i)
{
	mlx_destroy_image(game->aff.mlx, game->img.p);
	mlx_destroy_image(game->aff.mlx, game->img.pl);
	mlx_destroy_image(game->aff.mlx, game->img.pt);
	mlx_destroy_image(game->aff.mlx, game->img.pr);
	mlx_destroy_image(game->aff.mlx, game->img.ep);
	mlx_destroy_image(game->aff.mlx, game->img.epl);
	mlx_destroy_image(game->aff.mlx, game->img.ept);
	mlx_destroy_image(game->aff.mlx, game->img.epr);
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
	free_max(-1, game);
	if (i == 0)
		write(1, "GAME CLOSE\n", 11);
	else
		write(1, "WIN !\n", 6);
	exit (0);
}

void	init_imgs(t_game *game)
{
	int	i;

	i = PIXEL;
	game->img.p = mlx_xpm_file_to_image(game->aff.mlx, P, &i, &i);
	game->img.pl = mlx_xpm_file_to_image(game->aff.mlx, PL, &i, &i);
	game->img.pt = mlx_xpm_file_to_image(game->aff.mlx, PB, &i, &i);
	game->img.pr = mlx_xpm_file_to_image(game->aff.mlx, PR, &i, &i);
	game->img.ep = mlx_xpm_file_to_image(game->aff.mlx, EP, &i, &i);
	game->img.epl = mlx_xpm_file_to_image(game->aff.mlx, EPL, &i, &i);
	game->img.ept = mlx_xpm_file_to_image(game->aff.mlx, EPB, &i, &i);
	game->img.epr = mlx_xpm_file_to_image(game->aff.mlx, EPR, &i, &i);
	game->img.coin = mlx_xpm_file_to_image(game->aff.mlx, COIN, &i, &i);
	game->img.floor = mlx_xpm_file_to_image(game->aff.mlx, FLOOR, &i, &i);
	game->img.exit2 = mlx_xpm_file_to_image(game->aff.mlx, EXIT2, &i, &i);
	game->img.exit = mlx_xpm_file_to_image(game->aff.mlx, EXIT, &i, &i);
	game->img.wall = mlx_xpm_file_to_image(game->aff.mlx, WALL, &i, &i);
}

void	put_imgs(t_game *game, int y, int x, char c)
{
	if (c == '1')
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win, game->img.wall, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win, game->img.coin, x, y);
	else if (c == '0')
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win, game->img.floor, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win, game->img.exit, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win, game->img.p, x, y);
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
			put_imgs(game, y * PIXEL, x * PIXEL, game->map[y][x]);
		x = -1;
	}
	mlx_string_put(game->aff.mlx, game->aff.mlx_win, 11, 11, 0, "MOVES = 0");
	mlx_string_put(game->aff.mlx, game->aff.mlx_win, 10, 10, 0xFFFFFF, "MOVES = 0");
}
