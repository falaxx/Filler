/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 20:09:13 by fmerding          #+#    #+#             */
/*   Updated: 2018/11/14 15:08:04 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int x;

	x = 0;
	while (s1[x] == s2[x])
	{
		if ((s1[x] == '\0') && (s2[x] == '\0'))
			return (0);
		else
			++x;
	}
	if (s1[x] != s2[x])
		return ((unsigned char)s1[x] - (unsigned char)s2[x]);
	return (0);
}
