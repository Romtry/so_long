/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:54:50 by rothiery          #+#    #+#             */
/*   Updated: 2024/08/12 14:27:26 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->t_pos = NULL;
	game->str = NULL;
	game->shdw = NULL;
	game->cpy = NULL;
	game->pc = 0;
	game->tc = 0;
	game->coin = 0;
	fd = check(argc, argv, game);
	mlx_aff(game);
	free_max(fd, game);
	return (0);
}

void	printus(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		printf("%s\n", arr[i]);
	write(1, "\n", 1);
}

void	turret_stat(t_game *game)
{
	int	i;

	i = -1;
	printf("%d\n", game->tc);
	while (++i < game->tc)
	{
		printf("turret %d : y %d x %d dir %d\n", i, game->t_pos[i][0], game->t_pos[i][1], game->t_pos[i][2]);
	}
	printf("%d", game->t_pos[game->tc][0]);
}