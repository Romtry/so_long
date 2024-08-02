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

#ifndef SO_LONG
# define SO_LONG

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

//parsing
int		check(int argc, char **argv);
void	print_error(int n);

//utils
int	ft_strcmp(char *str, char *str2);

//get_next_line
char	*get_next_line(int fd);
size_t	ft_lstlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoinfr(char *s1, char *s2);
char	*ft_strdup(char *str);

#endif
