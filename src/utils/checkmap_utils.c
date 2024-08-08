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

void	check_content2(int e, int p, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	game->coin = 0;
	if (e != 1)
		print_error(6, -1, game);
	else if (p != 1)
		print_error(7, -1, game);
	while (game->map[++i])
	{
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'C')
				game->coin++;
		}
		j = -1;
	}
	if (game->coin <= 0)
		print_error(9, -1, game);
	flood_fill(game);
}

void	check_content(t_game *game)
{
	int	i;
	int	j;
	int	e;
	int	p;

	i = -1;
	j = -1;
	e = 0;
	p = 0;
	while (game->map[++i])
	{
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'E')
				e = exit_pos(game, e, i, j);
			else if (game->map[i][j] == 'P')
				p++;
			else if (game->map[i][j] != '0' && game->map[i][j] != '1'
				&& game->map[i][j] != 'C')
				print_error(8, -1, game);
		}
		j = -1;
	}
	check_content2(e, p, game);
}

void	check_walls(t_game *game)
{
	int	i;

	i = -1;
	while (game->map[0][++i])
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
			print_error(5, -1, game);
	}
	i = -1;
	while (game->map[++i + 1] != NULL)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			print_error(5, -1, game);
	}
	check_content(game);
}

void	check_rectangle(t_game *game)
{
	game->height = -1;
	game->width = 0;
	game->width = ft_strlen(game->map[0]);
	while (game->map[++game->height] != NULL)
	{
		if (game->width != ft_strlen(game->map[game->height]))
			print_error(4, -1, game);
	}
	check_walls(game);
}
