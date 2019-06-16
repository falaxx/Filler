/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:07:19 by fmerding          #+#    #+#             */
/*   Updated: 2018/11/16 18:11:26 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!(dest = (char*)malloc(size)))
		return (NULL);
	while (i < size)
	{
		dest[i] = 0;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
