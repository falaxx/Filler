/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:11:35 by fmerding          #+#    #+#             */
/*   Updated: 2018/11/14 14:41:11 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)(haystack));
	while (haystack[i] != '\0')
	{
		while (haystack[j] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)(haystack));
		}
		j = 0;
		haystack++;
	}
	return (NULL);
}
