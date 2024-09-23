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

void	init_p(t_game *game, int i)
{
	game->img.dp = mlx_xpm_file_to_image(game->aff.mlx, DP, &i, &i);
	game->img.p = mlx_xpm_file_to_image(game->aff.mlx, P, &i, &i);
	game->img.pl = mlx_xpm_file_to_image(game->aff.mlx, PL, &i, &i);
	game->img.pt = mlx_xpm_file_to_image(game->aff.mlx, PB, &i, &i);
	game->img.pr = mlx_xpm_file_to_image(game->aff.mlx, PR, &i, &i);
	game->img.ep = mlx_xpm_file_to_image(game->aff.mlx, EP, &i, &i);
	game->img.epl = mlx_xpm_file_to_image(game->aff.mlx, EPL, &i, &i);
	game->img.ept = mlx_xpm_file_to_image(game->aff.mlx, EPB, &i, &i);
	game->img.epr = mlx_xpm_file_to_image(game->aff.mlx, EPR, &i, &i);
}

void	init_t(t_game *game, int i)
{
	game->img.t = mlx_xpm_file_to_image(game->aff.mlx, T, &i, &i);
	game->img.tl = mlx_xpm_file_to_image(game->aff.mlx, TL, &i, &i);
	game->img.td = mlx_xpm_file_to_image(game->aff.mlx, TD, &i, &i);
	game->img.tr = mlx_xpm_file_to_image(game->aff.mlx, TR, &i, &i);
	game->img.te = mlx_xpm_file_to_image(game->aff.mlx, TE, &i, &i);
	game->img.tel = mlx_xpm_file_to_image(game->aff.mlx, TEL, &i, &i);
	game->img.ted = mlx_xpm_file_to_image(game->aff.mlx, TED, &i, &i);
	game->img.ter = mlx_xpm_file_to_image(game->aff.mlx, TER, &i, &i);
}

void	init_imgs(t_game *game)
{
	int	i;

	i = PIXEL;
	init_p(game, i);
	init_t(game, i);
	game->img.coin = mlx_xpm_file_to_image(game->aff.mlx, COIN, &i, &i);
	game->img.floor = mlx_xpm_file_to_image(game->aff.mlx, FLOOR, &i, &i);
	game->img.exit2 = mlx_xpm_file_to_image(game->aff.mlx, EXIT2, &i, &i);
	game->img.exit = mlx_xpm_file_to_image(game->aff.mlx, EXIT, &i, &i);
	game->img.wall = mlx_xpm_file_to_image(game->aff.mlx, WALL, &i, &i);
	game->img.go = mlx_xpm_file_to_image(game->aff.mlx, GO, &i, &i);
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
			put_imgs(game, y, x, game->map[y][x]);
		x = -1;
	}
	aff_turret(game, 1);
	aff_turret(game, 1);
	mlx_string_put(game->aff.mlx, game->aff.mlx_win, 11, 11, 0, "MOVES = 0");
	mlx_string_put(game->aff.mlx, game->aff.mlx_win, 10, 10, 0xFFFFFF,
		"MOVES = 0");
}
