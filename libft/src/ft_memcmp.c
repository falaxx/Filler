/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:10:55 by fmerding          #+#    #+#             */
/*   Updated: 2018/11/14 14:18:42 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *i;
	unsigned char *j;

	if (n == 0)
		return (0);
	i = (unsigned char *)(s1);
	j = (unsigned char *)(s2);
	while (*(i) == *(j) && --n > 0)
	{
		i++;
		j++;
	}
	return (*(i) - *(j));
}
