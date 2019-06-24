/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 05:24:26 by fmerding          #+#    #+#             */
/*   Updated: 2019/06/24 05:32:43 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_inbounds(t_vec2 res, t_f f)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < f.sp_y)
	{
		while (x < f.sp_x)
		{
			if ((f.p[y][x] == '*') && (res.y + y < 0 || res.x + x < 0
				|| res.y + y > f.sm_y - 1 || res.x + x > f.sm_x - 1))
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

int		find_enemy(t_vec2 pos, t_f *f)
{
	int x;
	int y;
	int res;
	int dis;

	x = 0;
	y = 0;
	res = 1000000000;
	while (y < f->sm_y)
	{
		while (x < f->sm_x)
		{
			if (((f->m[y][x] == 'O' || f->m[y][x] == 'o') && f->player == 2)
			|| ((f->m[y][x] == 'X' || f->m[y][x] == 'x') && f->player == 1))
			{
				dis = abs(pos.x - x) + abs(pos.y - y);
				if (dis < res)
					res = dis;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (res);
}

t_f		find_all(t_vec2 res, t_f f)
{
	int		x;
	int		y;
	t_vec2	pos;

	f.enemy = 0;
	x = 0;
	y = 0;
	while (y < f.sp_y)
	{
		while (x < f.sp_x)
		{
			if (f.p[y][x] == '*')
			{
				pos.x = x + res.x;
				pos.y = y + res.y;
				f.enemy += find_enemy(pos, &f);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (f);
}
