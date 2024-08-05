/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:17:37 by rothiery          #+#    #+#             */
/*   Updated: 2024/08/05 09:17:38 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1' || game->map[game->height][i] != '1')
			print_error(5, -1, game);
		i++;
	}
	i = 0;
	while (game->map[i] != NULL)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width] != '1')
			print_error(5, -1, game);
		i++;
	}
}

void	check_rectangle(t_game *game)
{
	game->height = 0;
	game->width = 0;
	game->width = ft_strlen(game->map[0]);
	while (game->map[game->height] != NULL)
	{
		if (game->width != ft_strlen(game->map[game->height]))
			print_error(4, -1, game);
		game->height++;
	}
	game->height--;
	game->width--;
	check_walls(game);
}
