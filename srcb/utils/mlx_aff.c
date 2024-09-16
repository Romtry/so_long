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

void	death(t_game *game, int y, int x, int t)
{
	game->ret = 1;
	mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
		game->img.dp, game->px * PIXEL, game->py * PIXEL);
	if (game->t_pos[t][2] == 0)
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.te, x * PIXEL, y * PIXEL);
	else if (game->t_pos[t][2] == 1)
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.ter, x * PIXEL, y * PIXEL);
	else if (game->t_pos[t][2] == 2)
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.ted, x * PIXEL, y * PIXEL);
	else if (game->t_pos[t][2] == 3)
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.tel, x * PIXEL, y * PIXEL);
	mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
		game->img.go, game->width / 2 * PIXEL, game->height / 2 * PIXEL);
}

void	put_turret(t_game *game, int y, int x)
{
	int	t;

	t = 0;
	mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
		game->img.te, x * PIXEL, y * PIXEL);
	while (game->t_pos[t][0] != y || game->t_pos[t][1] != x)
	{
		t++;
		if (t == game->tc)
		{
			write(1, "error\n", 5);
			exit(1);
		}
	}
	game->t_pos[t][2] = 4;
}

void	put_imgs(t_game *game, int y, int x, char c)
{
	if (c == '1')
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.wall, x * PIXEL, y * PIXEL);
	else if (c == 'C')
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.coin, x * PIXEL, y * PIXEL);
	else if (c == '0')
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.floor, x * PIXEL, y * PIXEL);
	else if (c == 'E')
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.exit, x * PIXEL, y * PIXEL);
	else if (c == 'P')
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.p, x * PIXEL, y * PIXEL);
	else if (c == 'T' && game->t_pos[game->tc][0] == 0)
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.t, x * PIXEL, y * PIXEL);
	else
		put_turret(game, y, x);
}

void	print_moves(t_game *game)
{
	game->str = ft_strjoin("MOVES = ", ft_itoa(game->moves));
	mlx_string_put(game->aff.mlx, game->aff.mlx_win, 11, 11, 0, game->str);
	game->shdw = ft_strjoin("MOVES = ", ft_itoa(game->moves));
	mlx_string_put(game->aff.mlx, game->aff.mlx_win, 10, 10, 0xFFFFFF,
		game->shdw);
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
	game->moves = 0;
	mlx_draw(game);
	mlx_hook(game->aff.mlx_win, 2, 1L << 0, key_func, game);
	mlx_hook(game->aff.mlx_win, 17, 0L, game_end, game);
	mlx_loop(game->aff.mlx);
}
