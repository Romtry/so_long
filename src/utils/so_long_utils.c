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

int	ft_strcmp(char *str, char *str2)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != str2[i])
			return (1);
		i++;
	}
	return (0);
}

void	free_max(int fd, t_game *game)
{
	int	i;

	i = 0;
	if (fd != -1)
		close(fd);
	while (game->map[i])
	{
		free((void *)game->map[i]);
		i++;
	}
	free(game->map);
	free(game);
}
