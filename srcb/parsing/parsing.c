/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:43:03 by rothiery          #+#    #+#             */
/*   Updated: 2024/08/01 09:43:05 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	safe_dist(t_game *game, int y, int x)
{
	int	i;
	int	j;
	int	jmin;

	i = y - 4;
	if (i < 1)
		i = 1;
	jmin = x - 4;
	if (jmin < 1)
		jmin = 1;
	j = jmin;
	while (++i < y + 4 && i < (int)game->height)
	{
		while (++j < x + 4 && j < (int)game->width)
		{
			if ((game->map[i][j] == 'T' || game->map[i][j] == 'P')
				&& (i != y || j != x))
				print_error(12, -1, game);
		}
		j = jmin;
	}
}

int	check(int argc, char **argv, t_game *game)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (argc == 1)
		print_error(0, fd, NULL);
	else if (argc > 2)
		print_error(1, fd, NULL);
	else if (ft_strcmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber") == 1)
		print_error(2, fd, NULL);
	else if (fd == -1)
		print_error(3, fd, NULL);
	else
		game->map = check_map(fd, argv[1], game);
	return (fd);
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
	if (game->width > 41)
		print_error(11, -1, game);
	while (game->map[++game->height] != NULL)
	{
		if (game->width != ft_strlen(game->map[game->height]))
			print_error(4, -1, game);
	}
	if (game->height > 22)
		print_error(11, -1, game);
	check_walls(game);
}

char	**check_map(int fd, char *path, t_game *game)
{
	char	*temp;
	char	**map;
	int		i;

	i = height(path);
	map = (char **)malloc(sizeof(char *) * i);
	i = 0;
	while (1)
	{
		temp = get_next_line(fd);
		map[i] = temp;
		if (temp == NULL)
			break ;
		i++;
	}
	free(temp);
	map[i] = NULL;
	game->map = map;
	check_rectangle(game);
	close(fd);
	return (map);
}
