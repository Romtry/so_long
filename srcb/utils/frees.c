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

void	free_count_m(t_game *game)
{
	free(game->str);
	free(game->shdw);
}

void	free_map(t_game *game)
{
	int	i;

	i = -1;
	while (game->map[++i])
		free(game->map[i]);
	free(game->map);
}

void	free_cpy(t_game *game)
{
	int	i;

	i = -1;
	while (game->cpy[++i])
		free(game->cpy[i]);
	free(game->cpy);
}

void	free_t_pos(t_game *game)
{
	int	i;

	i = -1;
	while (game->t_pos[++i])
		free(game->t_pos[i]);
	free(game->t_pos[i]);
	free(game->t_pos);
}

void	free_max(int fd, t_game *game)
{
	if (game)
	{
		if (game->str)
			free_count_m(game);
		if (fd != -1)
			close(fd);
		if (game->map)
			free_map(game);
		if (game->cpy)
			free_cpy(game);
		if (game->t_pos)
			free_t_pos(game);
		free(game);
	}
}
