/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:16:36 by fmerding          #+#    #+#             */
/*   Updated: 2018/11/16 19:34:31 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*dest;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	j = 0;
	while (*(s) == ' ' || *(s) == '\n' || *(s) == '\t')
		s++;
	i = ft_strlen(s);
	if (i > 0)
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\0')
			i--;
		i++;
	}
	if (!(dest = (char*)malloc(sizeof(*dest) * i + 1)))
		return (NULL);
	while (j < i)
	{
		dest[j] = s[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
