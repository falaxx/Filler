/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:00:36 by fmerding          #+#    #+#             */
/*   Updated: 2018/11/16 19:33:27 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int a;

	if (!s1)
		return (0);
	if (!s2)
		return (0);
	a = ft_strncmp(s1, s2, n);
	if (a == 0)
		return (1);
	return (0);
}
