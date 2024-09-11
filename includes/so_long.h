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
# define WALL "./assets/bush.xpm"
# define COIN "./assets/gapp.xpm"
# define FLOOR "./assets/floor.xpm"
# define EXIT "./assets/trap.xpm"
# define EXIT2 "./assets/trappopened.xpm"
# define GO "./assets/go.xpm"
# define P "./assets/link.xpm"
# define PL "./assets/link_left.xpm"
# define PB "./assets/link_back.xpm"
# define PR "./assets/link_right.xpm"
# define EP "./assets/trap_link.xpm"
# define EPL "./assets/trap_link_left.xpm"
# define EPB "./assets/trap_link_back.xpm"
# define EPR "./assets/trap_link_right.xpm"
# define DP "./assets/tomb.xpm"
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
	void			*mlx;
	void			*mlx_win;
	void			*img;
	char			*addr;
	int				bpp;
	int				length;
	int				endian;
};

typedef struct s_game
{
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
	int				alive;
	size_t			height;
	size_t			width;
	char			*str;
	char			*shdw;
	char			**map;
	char			**cpy;
	struct s_aff	aff;
	struct s_img	img;
}	t_game;

//so_long.c
void	printus(char **arr);

//parsing
//parsing.c
int		check(int argc, char **argv, t_game *game);
void	flood_fill(t_game *game);

// checkcontent.c
void	check_content(t_game *game);

//print_error.c
void	print_error(int n, int fd, t_game *game);

//utils
//checkmap_utils.c
void	check_rectangle(t_game *game);

// ft_itoa
char	*ft_itoa(int n);

//so_long_utils.c
int		height(char *path);
void	free_max(int fd, t_game *game);
int		ft_strcmp(char *str, char *str2);
char	*ft_strjoin(char const *s1, char const *s2);

// ff_utils.c
int		void_next(t_game *game, int *count);
void	algo_ff(t_game *game);
void	map_cpy(t_game *game);

// ff_utils2.c
void		exit_pos(t_game *game, int i, int j);
void	player_pos(t_game *game);

// mlx_utils.c
void	mlx_aff(t_game *game);
void	mlx_draw(t_game *game);
int		game_end(t_game *game);
void	init_imgs(t_game *game);
void	put_imgs(t_game *game, int y, int x, char c);

//get_next_line
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoinfr(char *s1, char *s2);
char	*ft_strdup(char *str);

#endif
