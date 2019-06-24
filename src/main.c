/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:50:35 by fmerding          #+#    #+#             */
/*   Updated: 2019/06/24 04:24:13 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_exit2(t_f *f)
{
	if (f->window != NULL)
		ft_memdel((void **)f->window);
	if (f->renderer != NULL)
		ft_memdel((void **)f->renderer);
	if (f->tex != NULL)
		ft_memdel((void **)f->tex);
	exit(0);
}

void	ft_exit(t_f *f)
{
	int i;

	i = 0;
	if (f->m != NULL)
	{
		while (i < f->sm_y)
		{
			if (f->m[i] != NULL)
				ft_memdel((void **)&f->m[i]);
			i++;
		}
		ft_memdel((void **)&f->m);
	}
	i = 0;
	if (f->p != NULL)
	{
		while (i < f->sp_y)
		{
			if (f->p[i] != NULL)
				ft_memdel((void **)&f->p[i]);
			i++;
		}
		ft_memdel((void **)&f->p);
	}
	ft_exit2(f);
}

int		main(void)
{
	t_f f;

	f.width = 600;
	f.height = 800;
	f.sm_x = 0;
	f.sm_y = 0;
	f.i = 0;
	f.j = 0;
	f.k = 0;
	f.player = 1;
	f.start.x = -2;
	f.done = 0;
	f.m = NULL;
	f.p = NULL;
	f = read_fd(&f);
	return (0);
}
