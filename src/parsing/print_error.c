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

void	print_error(int n)
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
		write(1, "less or more than 1 exit\n", 25);
	else if (n == 5)
		write(1, "less or more than 1 player\n", 27);
	exit(1);
}
