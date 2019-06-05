/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:09:47 by fmerding          #+#    #+#             */
/*   Updated: 2018/11/13 18:08:30 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *tab;
	char *res;

	if (!(tab = (char*)malloc(sizeof(*tab) * ++size)))
		return (NULL);
	res = tab;
	while (size-- > 0)
		*(tab++) = '\0';
	return (res);
}
