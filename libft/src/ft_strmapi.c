/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:41:33 by fmerding          #+#    #+#             */
/*   Updated: 2018/11/16 19:34:24 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	j;
	int				i;
	char			*s2;

	if (!s)
		return (NULL);
	j = 0;
	if (!(s2 = (char*)malloc(sizeof(*s2) * (ft_strlen(s) + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		s2[i] = f(j++, s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
