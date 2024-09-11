/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:02:58 by rothiery          #+#    #+#             */
/*   Updated: 2024/05/04 20:27:41 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	lenint(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	dixpl(int l)
{
	int	i;

	i = 1;
	while (l > 1)
	{
		i = i * 10;
		l--;
	}
	return (i);
}

static int	isneg(char *str, int n)
{
	str[0] = '-';
	return (n = n * -1);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		l;
	int		i;

	i = 0;
	l = lenint(n);
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	str = malloc(sizeof(char) * l + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		n = isneg(str, n);
		i++;
		l--;
	}
	while (l > 0)
	{
		str[i] = ((n / dixpl(l)) % 10) + 48;
		l--;
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*int	main(void)
{
	char	*dest = ft_itoa(42);

	if (dest == NULL)
		printf("null");
	else
		printf("itoa(%d) returned \"%s\" and allocated %d bytes\n", 42, dest, 0);
	free(dest);
	return (0);
}*/
