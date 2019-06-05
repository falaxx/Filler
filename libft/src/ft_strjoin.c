/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:33:13 by fmerding          #+#    #+#             */
/*   Updated: 2018/11/16 19:38:04 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		len;
	int		len2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = 0;
	len2 = 0;
	if (!s1 || !s2)
		return (NULL);
	if (s1[i] != '\0')
		len = ft_strlen(s1);
	if (s2[i] != '\0')
		len2 = ft_strlen(s2);
	if (!(dest = (char*)malloc(sizeof(char) * (len2 + 1 + len))))
		return (NULL);
	while (len-- > 0)
		dest[i++] = s1[j++];
	j = 0;
	while (len2-- > 0)
		dest[i++] = s2[j++];
	dest[i++] = '\0';
	return (dest);
}
