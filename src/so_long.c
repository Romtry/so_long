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
	game->cpy = NULL;
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
