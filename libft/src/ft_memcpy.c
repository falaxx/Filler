/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:10:58 by fmerding          #+#    #+#             */
/*   Updated: 2018/11/09 15:54:40 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char				*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	while (n > 0)
	{
		*(d++) = *(s++);
		n--;
	}
	return (dest);
}
