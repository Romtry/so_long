/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:19:10 by rothiery          #+#    #+#             */
/*   Updated: 2024/08/01 10:19:12 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	height(char *path)
{
	char	*temp;
	int		fd;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	while (1)
	{
		temp = get_next_line(fd);
		i++;
		if (temp == NULL)
			break ;
		free(temp);
	}
	free(temp);
	close(fd);
	return (i);
}

int	ft_strcmp(char *str, char *str2)
{
	int	i;

	i = -1;
	if (ft_strlen(str) < ft_strlen(str2))
		return (1);
	while (str[++i])
	{
		if (str[i] != str2[i] || str[i] == '\0')
			return (1);
	}
	return (0);
}

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
	// printf("%p\n", game->cpy[0]);
	if (game != NULL && game->cpy)
	{
		while (game->cpy[++i] != NULL)
			free(game->cpy[i]);
		free(game->cpy);
	}
	if (game)
		free(game);
}
