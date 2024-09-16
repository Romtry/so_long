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

#include "so_long.h"

int	height(char *path)
{
	char	*temp;
	int		fd;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	while (1)
	{
		temp = get_next_line(fd);
		i++;
		if (temp == NULL)
			break ;
		free(temp);
	}
	free(temp);
	close(fd);
	return (i);
}

int	ft_strcmp(char *str, char *str2)
{
	int	i;

	i = -1;
	if (ft_strlen(str) < ft_strlen(str2))
		return (1);
	while (str[++i])
	{
		if (str[i] != str2[i] || str[i] == '\0')
			return (1);
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	s1l;

	s1l = ft_strlen((char *)s1);
	i = 0;
	dest = malloc(sizeof(char) * (s1l + ft_strlen((char *)s2) + 1));
	if (dest == NULL)
		return (NULL);
	while (i < s1l)
	{
		dest[i] = s1[i];
		i++;
	}
	while (i < (s1l + ft_strlen((char *)s2)))
	{
		dest[i] = s2[i - s1l];
		i++;
	}
	dest[i] = '\0';
	free((char *)s2);
	return (dest);
}
