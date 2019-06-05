/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:24:46 by fmerding          #+#    #+#             */
/*   Updated: 2018/11/21 12:11:38 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_display_file(char *str)
{
	int		fd;
	int		i;
	char	c[1];

	i = 1;
	fd = open(str, O_RDONLY);
	while (i == 1)
	{
		i = read(fd, c, 1);
		if (i == 1)
			write(1, &c, 1);
	}
	close(fd);
}
