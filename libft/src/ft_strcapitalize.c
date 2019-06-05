/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:09:12 by fmerding          #+#    #+#             */
/*   Updated: 2018/11/20 15:37:11 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;
	int y;

	y = 0;
	i = 1;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	while (str[y] != '\0')
	{
		if (str[y] >= 'a' && str[y] <= 'z')
		{
			str[y] = str[y] - 32;
		}
		++y;
	}
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') && ((str[i - 1] >= 'A' &&
		str[i - 1] <= 'Z') || (str[i - 1] >= '0' && str[i - 1] <= '9')
		|| (str[i - 1] >= 'a' && str[i - 1] <= 'z')))
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
