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

void	free_max(int fd, t_game *game)
{
	int	i;

	i = -1;
	if (fd != -1)
		close(fd);
	if (game && game->map != NULL )
	{
		while (game->map[++i] != NULL)
			free(game->map[i]);
		free(game->map);
	}
	i = -1;
	if (game != NULL && game->cpy)
	{
		while (game->cpy[++i] != NULL)
			free(game->cpy[i]);
		free(game->cpy);
	}
	if (game)
		free(game);
}

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
	else
		path_error(n);
	free_max(fd, game);
	exit(1);
}

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
