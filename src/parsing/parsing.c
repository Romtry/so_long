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

void	check_p_e(int fd)
{
	int		p;
	int		e;
	char	*str;
	char	*tmp;

	p = 0;
	e = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			breack(0);
		tmp = str;
		while (ft_strchr(tmp, 'P') != NULL)
		{
			tmp = ft_strchr(tmp, 'P');
			p++;
		}
		tmp = str;
		while (ft_strchr(tmp, 'E') != NULL)
		{
			tmp = ft_strchr(tmp, 'E');
			e++;
		}
	}
	if (p != 1)
		print_error(4);
	if (e != 1)
		print_error(5);
}

void	check_map(int fd)
{
	
}

int	check(int argc, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (argc == 1)
		print_error(0);
	else if (argc > 2)
		print_error(1);
	else if (ft_strcmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber") == 1)
		print_error(2);
	else if (fd == -1)
	{
		close(fd);
		print_error(3);
	}
	else
		check_map(fd);
	return (fd);
}
