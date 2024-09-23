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

# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include ".mlx/mlx.h"

# define PIXEL 48
# define ESC 65307
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363
# define W 119
# define D 100
# define S 115
# define A 97
# define WALL "./assets/bush.xpm"
# define COIN "./assets/gapp.xpm"
# define FLOOR "./assets/floor.xpm"
# define EXIT "./assets/trap.xpm"
# define EXIT2 "./assets/trappopened.xpm"
# define GO "./assets/go.xpm"
# define DP "./assets/tomb.xpm"
# define P "./assets/link.xpm"
# define PL "./assets/link_left.xpm"
# define PB "./assets/link_back.xpm"
# define PR "./assets/link_right.xpm"
# define EP "./assets/trap_link.xpm"
# define EPL "./assets/trap_link_left.xpm"
# define EPB "./assets/trap_link_back.xpm"
# define EPR "./assets/trap_link_right.xpm"
# define T "./assets/bow_wa.xpm"
# define TL "./assets/bow_wa_l.xpm"
# define TR "./assets/bow_wa_r.xpm"
# define TD "./assets/bow_wa_d.xpm"
# define TE "./assets/bow_empty.xpm"
# define TEL "./assets/bow_empty_l.xpm"
# define TER "./assets/bow_empty_r.xpm"
# define TED "./assets/bow_empty_d.xpm"

struct s_img
{
	void	*p;
	void	*pl;
	void	*pt;
	void	*pr;
	void	*ep;
	void	*epl;
	void	*ept;
	void	*epr;
	void	*dp;
	void	*go;
	void	*wall;
	void	*floor;
	void	*exit;
	void	*exit2;
	void	*coin;
	void	*t;
	void	*tl;
	void	*td;
	void	*tr;
	void	*te;
	void	*tel;
	void	*ted;
	void	*ter;
};

struct s_aff
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
	int				**t_pos;
	int				pc;
	int				tc;
	int				bc;
	int				ex;
	int				ey;
	int				x;
	int				y;
	int				px;
	int				py;
	int				coin;
	int				moves;
	int				ret;
	size_t			height;
	size_t			width;
	char			*str;
	char			*shdw;
	char			**map;
	char			**cpy;
	struct s_aff	aff;
	struct s_img	img;
}	t_game;

// so_long.c
void	actu_p(t_game *game, int y, int x);
void	printus(char **arr);
void	turret_stat(t_game *game);

// parsing
//  checkcontent.c
void	check_content(t_game *game);
char	**check_map(int fd, char *path, t_game *game);
void	check_walls(t_game *game);
void	flood_fill(t_game *game);
// parsing.c
void	safe_dist(t_game *game, int y, int x);
int		check(int argc, char **argv, t_game *game);

// utils
//  get_next_line
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoinfr(char *s1, char *s2);
char	*ft_strdup(char *str);
// end_game.c
void	free_max(int fd, t_game *game);
void	print_error(int n, int fd, t_game *game);
int		game_end(t_game *game);
// ff_algo.c
int		void_next(t_game *game, int *count);
void	exit_pos(t_game *game, int i, int j);
void	algo_ff(t_game *game);
// ff_utils.c
void	player_pos(t_game *game);
void	map_cpy(t_game *game);
// frees.c
void	free_max(int fd, t_game *game);
// ft_itoa
char	*ft_itoa(int n);
// mlx_aff.c
void	put_turret(t_game *game, int y, int x);
void	put_imgs(t_game *game, int y, int x, char c);
void	print_moves(t_game *game);
void	mlx_aff(t_game *game);
// mlx_init.c
void	init_imgs(t_game *game);
void	mlx_draw(t_game *game);
// mlx_key.c
int		key_func(int keycode, t_game *game);
// turret.c
void	death(t_game *game, int y, int x, int t);
void	turret(t_game *game);
// turret_m.c
void	aff_turret(t_game *game, int n);
void	turret_moves(t_game *game, int t, int i);
// so_long_utils.c
int		height(char *path);
int		ft_strcmp(char *str, char *str2);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
