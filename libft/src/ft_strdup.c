/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:16:28 by fmerding          #+#    #+#             */
/*   Updated: 2018/11/19 19:44:39 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *dest;

	dest = (char*)malloc(sizeof(*dest) * (ft_strlen(src) + 1));
	if (!dest)
		return (NULL);
	return (ft_strcpy(dest, src));
}
