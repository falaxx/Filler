/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:10:51 by fmerding          #+#    #+#             */
/*   Updated: 2018/11/19 17:56:31 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*i;
	size_t				j;
	unsigned char		w;

	w = (unsigned char)c;
	j = 0;
	i = s;
	while (++j < n)
	{
		if (*(i) == w)
			return ((void *)i);
		if (*(++i) == w)
			return ((void *)i);
	}
	return (0);
}
