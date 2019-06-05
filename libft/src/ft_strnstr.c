/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:11:28 by fmerding          #+#    #+#             */
/*   Updated: 2018/11/16 19:29:38 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;
	size_t	k;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)(haystack));
	if (haystack[0] == '\0')
		return (NULL);
	while (haystack[0] != '\0' && i++ <= len)
	{
		k = i;
		while (haystack[j] == needle[j] && k++ <= len)
		{
			if ((haystack[j + 1] == '\0') && (needle[j + 1] == '\0'))
				return ((char *)haystack);
			j++;
			if (needle[j] == '\0')
				return ((char *)(haystack));
		}
		j = 0;
		haystack++;
	}
	return (NULL);
}
