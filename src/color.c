/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 04:34:23 by fmerding          #+#    #+#             */
/*   Updated: 2019/06/24 06:04:17 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_texture	black(t_texture tex)
{
	t_vec2 pos;

	pos.x = 0;
	pos.y = 0;
	while (pos.x < 1000)
	{
		while (pos.y < 1000)
		{
			set_pixel(&tex, 0x000000ff, pos);
			pos.y++;
		}
		pos.y = 0;
		pos.x++;
	}
	return (tex);
}

t_texture	red(t_texture tex, t_f *f, t_vec2 pos)
{
	t_vec2 save;
	t_vec2 next;

	pos.x *= f->ppx;
	pos.y *= f->ppy;
	pos.x += 1;
	pos.y += 1;
	next.x = pos.x + f->ppx - 2;
	next.y = pos.y + f->ppy - 2;
	save = pos;
	while (pos.x < next.x)
	{
		while (pos.y < next.y)
		{
			set_pixel(&tex, 0xff0000ff, pos);
			pos.y++;
		}
		pos.y = save.y;
		pos.x++;
	}
	return (tex);
}

t_texture	blue(t_texture tex, t_f *f, t_vec2 pos)
{
	t_vec2 save;
	t_vec2 next;

	pos.x *= f->ppx;
	pos.y *= f->ppy;
	pos.x += 1;
	pos.y += 1;
	next.x = pos.x + f->ppx - 2;
	next.y = pos.y + f->ppy - 2;
	save = pos;
	while (pos.x < next.x)
	{
		while (pos.y < next.y)
		{
			set_pixel(&tex, 0x0066ffff, pos);
			pos.y++;
		}
		pos.y = save.y;
		pos.x++;
	}
	return (tex);
}

t_f			render(t_f *f)
{
	int		x;
	int		y;
	t_vec2	pos;

	x = 0;
	y = 0;
	while (y < f->sm_y)
	{
		while (x < f->sm_x)
		{
			pos.x = x;
			pos.y = y;
			if (f->m[y][x] == 'o' || f->m[y][x] == 'O')
				*f->tex = blue(*f->tex, f, pos);
			if (f->m[y][x] == 'x' || f->m[y][x] == 'X')
				*f->tex = red(*f->tex, f, pos);
			x++;
		}
		x = 0;
		y++;
	}
	update_image(f, f->tex);
	return (*f);
}
