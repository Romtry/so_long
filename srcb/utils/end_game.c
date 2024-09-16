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

void	path_error(int n)
{
	if (n == 0)
		write(1, "no path given\n", 14);
	else if (n == 1)
		write(1, "more than 1 map given\n", 22);
	else if (n == 2)
		write(1, "wrong file\n", 11);
	else if (n == 3)
		write(1, "file not found\n", 15);
}

void	print_error(int n, int fd, t_game *game)
{
	if (n == 4)
		write(1, "map is not a rectangle\n", 23);
	else if (n == 5)
		write(1, "wrong walls\n", 12);
	else if (n == 6)
		write(1, "less or more than 1 exit\n", 25);
	else if (n == 7)
		write(1, "less or more than 1 player\n", 27);
	else if (n == 8)
		write(1, "unexpected character in map\n", 28);
	else if (n == 9)
		write(1, "no coins\n", 9);
	else if (n == 10)
		write(1, "player can't find coins or exit\n", 32);
	else if (n == 11)
		write(1, "map too big\n", 12);
	else if (n == 12)
		write(1, "turrets must be 3 away from player and other turret\n", 52);
	else
		path_error(n);
	free_max(fd, game);
	exit(1);
}

void	destroy_p(t_game *game)
{
	mlx_destroy_image(game->aff.mlx, game->img.dp);
	mlx_destroy_image(game->aff.mlx, game->img.p);
	mlx_destroy_image(game->aff.mlx, game->img.pl);
	mlx_destroy_image(game->aff.mlx, game->img.pt);
	mlx_destroy_image(game->aff.mlx, game->img.pr);
	mlx_destroy_image(game->aff.mlx, game->img.ep);
	mlx_destroy_image(game->aff.mlx, game->img.epl);
	mlx_destroy_image(game->aff.mlx, game->img.ept);
	mlx_destroy_image(game->aff.mlx, game->img.epr);
}

void	destroy_t(t_game *game)
{
	mlx_destroy_image(game->aff.mlx, game->img.t);
	mlx_destroy_image(game->aff.mlx, game->img.tl);
	mlx_destroy_image(game->aff.mlx, game->img.td);
	mlx_destroy_image(game->aff.mlx, game->img.tr);
	mlx_destroy_image(game->aff.mlx, game->img.te);
	mlx_destroy_image(game->aff.mlx, game->img.tel);
	mlx_destroy_image(game->aff.mlx, game->img.ted);
	mlx_destroy_image(game->aff.mlx, game->img.ter);
}

int	game_end(t_game *game)
{
	destroy_p(game);
	destroy_t(game);
	mlx_destroy_image(game->aff.mlx, game->img.coin);
	mlx_destroy_image(game->aff.mlx, game->img.wall);
	mlx_destroy_image(game->aff.mlx, game->img.exit);
	mlx_destroy_image(game->aff.mlx, game->img.exit2);
	mlx_destroy_image(game->aff.mlx, game->img.floor);
	mlx_destroy_image(game->aff.mlx, game->img.go);
	mlx_clear_window(game->aff.mlx, game->aff.mlx_win);
	mlx_destroy_window(game->aff.mlx, game->aff.mlx_win);
	if (game->ret == 0)
		write(1, "GAME CLOSE\n", 11);
	else if (game->ret == 1)
		write(1, "GAME OVER !\n", 12);
	else
		write(1, "WIN !\n", 6);
	free_max(-1, game);
	exit (0);
}
