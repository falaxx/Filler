/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:11:01 by fmerding          #+#    #+#             */
/*   Updated: 2018/11/19 18:51:00 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (!n)
		return (dest);
	if (s < d)
	{
		s = s + n;
		d = d + n;
		while (n > 0)
		{
			*--d = *--s;
			n--;
		}
	}
	ft_memcpy(d, src, n);
	return (dest);
}
