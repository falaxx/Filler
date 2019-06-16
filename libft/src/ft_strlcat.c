/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:09:03 by fmerding          #+#    #+#             */
/*   Updated: 2018/11/22 18:46:34 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t j;
	size_t u;
	size_t res;

	i = ft_strlen(dest);
	j = ft_strlen(src);
	u = 0;
	res = i + j;
	if (n <= i)
		return (j + n);
	while (src[u] != '\0' && i < (n - 1))
	{
		dest[i++] = src[u++];
	}
	dest[i] = '\0';
	return (res);
}
