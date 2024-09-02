/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:43:56 by rothiery          #+#    #+#             */
/*   Updated: 2024/08/01 09:47:33 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include ".mlx/mlx.h"

# define ESC 65307
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363



struct t_aff
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
};

typedef struct s_game
{
	int		ex;
	int		ey;
	int		x;
	int		y;
	int		px;
	int		py;
	int		coin;
	size_t	height;
	size_t	width;
	char	**map;
	char	**cpy;
	struct t_aff aff;
}	t_game;

//so_long.c
void	printus(char **arr);

//parsing
//parsing.c
int		check(int argc, char **argv, t_game *game);
void	flood_fill(t_game *game);

//print_error.c
void	print_error(int n, int fd, t_game *game);

//utils
//checkmap_utils.c
void	check_rectangle(t_game *game);

//so_long_utils.c
int		height(char *path);
void	free_max(int fd, t_game *game);
int		ft_strcmp(char *str, char *str2);

// ff_utils.c
int		void_next(t_game *game, int *count);
void	algo_ff(t_game *game);
void	map_cpy(t_game *game);

// ff_utils2.c
int		exit_pos(t_game *game, int e, int i, int j);
void	player_pos(t_game *game);

// mlx_utils.c
void	mlx_aff(t_game *game);

//get_next_line
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoinfr(char *s1, char *s2);
char	*ft_strdup(char *str);

#endif
