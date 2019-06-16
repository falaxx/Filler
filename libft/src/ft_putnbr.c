/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:34:13 by fmerding          #+#    #+#             */
/*   Updated: 2018/11/19 18:24:31 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n == INT_MIN)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			n = -n;
			ft_putchar('-');
		}
		if (n >= 10)
		{
			ft_putnbr(n / 10);
			ft_putchar(n % 10 + '0');
		}
		else
			ft_putchar(n + '0');
	}
}
