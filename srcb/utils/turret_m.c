/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:37:47 by rothiery          #+#    #+#             */
/*   Updated: 2024/09/11 09:37:49 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_turret(t_game *game, int t, int dir)
{
	if (dir == 0)
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.t, game->t_pos[t][1] * PIXEL, game->t_pos[t][0] * PIXEL);
	else if (dir == 1)
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.tr, game->t_pos[t][1] * PIXEL, game->t_pos[t][0] * PIXEL);
	else if (dir == 2)
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.td, game->t_pos[t][1] * PIXEL, game->t_pos[t][0] * PIXEL);
	else if (dir == 3)
		mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
			game->img.tl, game->t_pos[t][1] * PIXEL, game->t_pos[t][0] * PIXEL);
	game->t_pos[t][2] = dir;
}

void	turret_movesl(t_game *game, int t, int dir)
{
	if (dir == 3)
	{
		if (game->map[game->t_pos[t][0] - 1][game->t_pos[t][1]] != '1')
			print_turret(game, t, 0);
		else if (game->map[game->t_pos[t][0]][game->t_pos[t][1] + 1] != '1')
			print_turret(game, t, 1);
		else if (game->map[game->t_pos[t][0] + 1][game->t_pos[t][1]] != '1')
			print_turret(game, t, 2);
		else if (game->t_pos[game->tc][0] % 2 == 0)
		{
			game->t_pos[t][3] = 1;
			mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
				game->img.tel, game->t_pos[t][1] * PIXEL,
				game->t_pos[t][0] * PIXEL);
		}
		else
		{
			game->t_pos[t][3] = 0;
			mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
				game->img.tl, game->t_pos[t][1] * PIXEL,
				game->t_pos[t][0] * PIXEL);
		}
	}
}

void	turret_movesd(t_game *game, int t, int dir)
{
	if (dir == 2)
	{
		if (game->map[game->t_pos[t][0]][game->t_pos[t][1] - 1] != '1')
			print_turret(game, t, 3);
		else if (game->map[game->t_pos[t][0] - 1][game->t_pos[t][1]] != '1')
			print_turret(game, t, 0);
		else if (game->map[game->t_pos[t][0]][game->t_pos[t][1] + 1] != '1')
			print_turret(game, t, 1);
		else if (game->t_pos[game->tc][0] % 2 == 0)
		{
			game->t_pos[t][3] = 1;
			mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
				game->img.ted, game->t_pos[t][1] * PIXEL,
				game->t_pos[t][0] * PIXEL);
		}
		else
		{
			game->t_pos[t][3] = 0;
			mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
				game->img.td, game->t_pos[t][1] * PIXEL,
				game->t_pos[t][0] * PIXEL);
		}
	}
	else
		turret_movesl(game, t, dir);
}

void	turret_movesr(t_game *game, int t, int dir)
{
	if (dir == 1)
	{
		if (game->map[game->t_pos[t][0] + 1][game->t_pos[t][1]] != '1')
			print_turret(game, t, 2);
		else if (game->map[game->t_pos[t][0]][game->t_pos[t][1] - 1] != '1')
			print_turret(game, t, 3);
		else if (game->map[game->t_pos[t][0] - 1][game->t_pos[t][1]] != '1')
			print_turret(game, t, 0);
		else if (game->t_pos[game->tc][0] % 2 == 0)
		{
			game->t_pos[t][3] = 1;
			mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
				game->img.ter, game->t_pos[t][1] * PIXEL,
				game->t_pos[t][0] * PIXEL);
		}
		else
		{
			game->t_pos[t][3] = 0;
			mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
				game->img.tr, game->t_pos[t][1] * PIXEL,
				game->t_pos[t][0] * PIXEL);
		}
	}
	else
		turret_movesd(game, t, dir);
}

void	turret_moves(t_game *game, int t, int dir)
{
	if (dir == 0)
	{
		if (game->map[game->t_pos[t][0]][game->t_pos[t][1] + 1] != '1')
			print_turret(game, t, 1);
		else if (game->map[game->t_pos[t][0] + 1][game->t_pos[t][1]] != '1')
			print_turret(game, t, 2);
		else if (game->map[game->t_pos[t][0]][game->t_pos[t][1] - 1] != '1')
			print_turret(game, t, 3);
		else if (game->t_pos[game->tc][0] % 2 == 0)
		{
			game->t_pos[t][3] = 1;
			mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
				game->img.te, game->t_pos[t][1] * PIXEL,
				game->t_pos[t][0] * PIXEL);
		}
		else
		{
			game->t_pos[t][3] = 0;
			mlx_put_image_to_window(game->aff.mlx, game->aff.mlx_win,
				game->img.t, game->t_pos[t][1] * PIXEL,
				game->t_pos[t][0] * PIXEL);
		}
	}
	else
		turret_movesr(game, t, dir);
}
