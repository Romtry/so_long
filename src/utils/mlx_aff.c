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
	char	*m;
	int		i;

	i = 0;
	write(1, "MOVES = ", 9);
	m = ft_itoa(game->moves);
	while (i < (int)ft_strlen(m))
	{
		write(1, &m[i], 1);
		i++;
	}
	write(1, "\n", 1);
	free(m);
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
