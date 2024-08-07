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

typedef struct s_game
{
	int		px;
	int		py;
	int		coin;
	size_t	height;
	size_t	width;
	char	**map;
	char	**cpy;
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
void	free_max(int fd, t_game *game, int n);
int		ft_strcmp(char *str, char *str2);

// flood_fill_utils.c
void	map_cpy(t_game *game);
void	player_pos(t_game *game);

//get_next_line
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoinfr(char *s1, char *s2);
char	*ft_strdup(char *str);

#endif
