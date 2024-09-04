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

#include "../../includes/so_long.h"

int	game_end(t_game *game)
{
	mlx_destroy_image(game->aff.mlx, game->img.img);
	mlx_clear_window(game->aff.mlx, game->aff.mlx_win);
	mlx_destroy_window(game->aff.mlx, game->aff.mlx_win);
	free_max(-1, game);
	exit (0);
}

int	set_color(char c)
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
		return (0x707070);
	else
		return (0x000000);
}

void	put_pixel2(t_game *game, int y, int x, char c)
{
	int	i;

	(void)c;
	i = PIXEL;
	if (c == '1')
		game->img.img = mlx_xpm_file_to_image(game->aff.mlx, WALL, &i, &i);
	else if (c == 'C')
		game->img.img = mlx_xpm_file_to_image(game->aff.mlx, COIN, &i, &i);
	else if (c == '0')
		game->img.img = mlx_xpm_file_to_image(game->aff.mlx, ROOF, &i, &i);
	else if (c == 'E')
		game->img.img = mlx_xpm_file_to_image(game->aff.mlx, EXIT, &i, &i);
	if (!(game->img.img || game->img.img))
		exit(1);
	mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win, game->img.img, x, y);
}

void	put_pixel(t_game *game, int y, int x, char c)
{
	int		i;
	int		j;

	i = x + PIXEL;
	j = y + PIXEL;
	if (c == 'P')
	{
		while (y < j)
		{
			while (x < i)
			{
				mlx_pixel_put(game->aff.mlx, game->aff.mlx_win, x, y, set_color(c));
				x++;
			}
			x = i - PIXEL;
			y++;
		}
	}
	else
		put_pixel2(game, y, x, c);
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
			put_pixel(game, y * PIXEL, x * PIXEL, game->map[y][x]);
		x = -1;
	}
}
