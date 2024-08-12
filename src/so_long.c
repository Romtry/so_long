/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:54:50 by rothiery          #+#    #+#             */
/*   Updated: 2024/08/12 14:27:26 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	mlx_pp(t_aff *aff, int x, int y, char c)
{
	char	*dst;
	int		i;
	int		j;

	i = x + 20;
	j = y + 20;
	while (y < j)
	{
		while (x < i)
		{
			dst = aff->addr + (y * aff->length + x * (aff->bpp / 8));
			if (c == 'E')
				*(unsigned int*)dst = 0x1A00FF;
			else if (c == 'P')
				*(unsigned int*)dst = 0xFF0000;
			else if (c == 'C')
				*(unsigned int*)dst = 0xFFEF00;
			else if (c == '0')
				*(unsigned int*)dst = 0xFFFFFF;
			else if (c == '1')
				*(unsigned int*)dst = 0x6B6B6B;
			x++;
		}
		x = i - 20;
		y++;
	}
}

// EXIT bleu
// Player rouge
// Coin jaune
// vide blanc
// wall gris

void	mlx_aff(t_game *game)
{
	void	*mlx;
	void	*mlx_test;
	t_aff	img;
	int		x;
	int		y;

	(void)game;
	// dst = NULL;
	x = -1;
	y = -1;
	mlx = mlx_init();
	mlx_test = mlx_new_window(mlx, 800, 500, "So_long");
	img.img = mlx_new_image(mlx, 800, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.length,
							&img.endian);
	while (game->map[++y] != NULL)
	{
		while (game->map[y][++x])
			mlx_pp(&img, x * 20, y * 20, game->map[y][x]);
		x = -1;
	}
	mlx_put_image_to_window(mlx, mlx_test, img.img, 0, 0);
	mlx_loop(mlx);
	// free(img);
	// free(mlx);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->cpy = NULL;
	fd = check(argc, argv, game);
	mlx_aff(game);
	free_max(fd, game);
	return (0);
}

void	printus(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		printf("%s\n", arr[i]);
	write(1, "\n", 1);
}
