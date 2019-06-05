/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:02:51 by fmerding          #+#    #+#             */
/*   Updated: 2018/11/16 19:44:45 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int a;

	if (!s1 || !s2)
		return (0);
	a = ft_strcmp((char *)s1, (char *)s2);
	if (a == 0)
		return (1);
	return (0);
}
