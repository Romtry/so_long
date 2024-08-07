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

#include "../../includes/so_long.h"

void	flood_fill(t_game *game)
{
	map_cpy(game);
	player_pos(game);
	algo_ff(game);
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
