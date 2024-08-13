/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:51:37 by rothiery          #+#    #+#             */
/*   Updated: 2024/06/18 14:47:23 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			return (s + i);
		}
		i++;
	}
	if (c == s[i])
	{
		return (s + i);
	}
	return (NULL);
}

char	*ft_strjoinfr(char *s1, char *s2)
{
	char	*dest;
	size_t	i;
	size_t	s1l;

	s1l = ft_strlen(s1);
	i = 0;
	dest = malloc(sizeof(char) * (s1l + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	while (i < s1l)
	{
		dest[i] = s1[i];
		i++;
	}
	while (i < (s1l + ft_strlen(s2)))
	{
		dest[i] = s2[i - s1l];
		i++;
	}
	dest[i] = '\0';
	return (free((char *)s1), dest);
}

char	*ft_strdup(char *str)
{
	unsigned int	i;
	char			*dup;

	i = 0;
	dup = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (dup == NULL)
	{
		return (NULL);
	}
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
