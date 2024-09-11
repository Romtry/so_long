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
	mlx_string_put(game->aff.mlx, game->aff.mlx_win, 10, 10, 0xFFFFFF,
		"MOVES = 0");
}

void	mlx_aff(t_game *game)
{
	game->aff.mlx = mlx_init();
	if (!game->aff.mlx)
		exit(0);
	game->aff.mlx_win = mlx_new_window(game->aff.mlx, game->width * PIXEL,
			game->height * PIXEL, "So_long");
	init_imgs(game);
	game->ret = 0;
	game->str = NULL;
	game->shdw = NULL;
	game->moves = 0;
	mlx_draw(game);
	mlx_hook(game->aff.mlx_win, 2, 1L << 0, key_func, game);
	mlx_hook(game->aff.mlx_win, 17, 0L, game_end, game);
	mlx_loop(game->aff.mlx);
}
