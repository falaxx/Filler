/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:58:48 by fmerding          #+#    #+#             */
/*   Updated: 2018/11/16 19:42:49 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

static char	ft_isc(int c)
{
	static char delimiter;

	if (-128 <= c && c <= 127)
	{
		delimiter = c;
	}
	return (delimiter);
}

static int	ft_countword(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] == ft_isc(1000))
		i++;
	while (str[i] != '\0')
	{
		if ((str[i] != ft_isc(1000)) && (str[i + 1] == ft_isc(1000) ||
		str[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

static char	*ft_strcpy(char *dest, char *src, int b, int len)
{
	int count;
	int sum;

	sum = b + len;
	count = 0;
	while (b < sum)
	{
		dest[count] = src[b];
		count++;
		b++;
	}
	dest[count] = '\0';
	return (dest);
}

static void	ft_blen(int *i, int *b, char *str, int *len)
{
	*len = 0;
	while (str[*i] == ft_isc(1000))
		(*i)++;
	*b = *i;
	while (str[*i] != ft_isc(1000) && str[*i] != '\0')
	{
		(*i)++;
		(*len)++;
	}
}

char		**ft_strsplit(const char *str, char c)
{
	int		i;
	int		len;
	char	**str2;
	int		b;
	int		l;

	i = 0;
	l = 0;
	ft_isc((int)c);
	if (!str || !(str2 = malloc(sizeof(char*) *
	(ft_countword((char*)str) + 1))))
		return (NULL);
	while (str[i] != '\0')
	{
		ft_blen(&i, &b, (char*)str, &len);
		if (len > 0)
		{
			if (!(str2[l] = malloc(sizeof(char) * (len + 1))))
				return (0);
			str2[l] = ft_strcpy(str2[l], (char*)str, b, len);
			l++;
		}
	}
	str2[l] = 0;
	return (str2);
}
