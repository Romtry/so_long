/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:59:21 by rothiery          #+#    #+#             */
/*   Updated: 2024/08/01 09:59:22 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	print_error(int n, int fd, t_game *game)
{
	if (n == 0)
		write(1, "no path given\n", 14);
	else if (n == 1)
		write(1, "more than 1 map given\n", 22);
	else if (n == 2)
		write(1, "wrong file\n", 11);
	else if (n == 3)
		write(1, "file not found", 14);
	else if (n == 4)
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
	if (n <= 9)
		free_max(fd, game, 1);
	else
		free_max(fd, game, 3);
	exit(1);
}
