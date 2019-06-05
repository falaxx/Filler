/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:37:18 by fmerding          #+#    #+#             */
/*   Updated: 2018/11/21 12:11:02 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_findi(unsigned int m)
{
	unsigned int i;

	i = 1;
	while (m >= 10)
	{
		m = m / 10;
		i++;
	}
	return (i);
}

char				*ft_itoa(int n)
{
	int				neg;
	int				i;
	unsigned int	m;
	char			*str;

	neg = 0;
	if (n < 0)
		neg = 1;
	m = (n >= 0) ? n : -n;
	i = ft_findi(m) + neg;
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = m % 10 + 48;
		m = m / 10;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
