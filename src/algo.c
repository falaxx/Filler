/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 05:33:08 by fmerding          #+#    #+#             */
/*   Updated: 2019/06/24 06:09:09 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_vec2	res_plus(t_f *f, t_vec2 res)
{
	res.x++;
	if (res.x == f->sm_x - 1)
	{
		res.x = f->minpos.x;
		res.y++;
	}
	return (res);
}

int		check_p2(t_vec2 res, t_f f, int x, int y)
{
	int nb;

	nb = 0;
	if (check_inbounds(res, f) == 0)
		return (0);
	while (y < f.sp_y)
	{
		while (x < f.sp_x)
		{
			if (f.p[y][x] == '*' && (f.m[res.y + y][res.x + x] == 'X'
			|| f.m[res.y + y][res.x + x] == 'x'))
				nb++;
			if (f.p[y][x] == '*' && (f.m[res.y + y][res.x + x] == 'o'
			|| f.m[res.y + y][res.x + x] == 'O'))
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	if (nb != 1)
		return (0);
	return (1);
}

t_vec2	algo2(t_f *f)
{
	t_vec2 res;
	t_vec2 save;

	save = f->minpos;
	res = f->minpos;
	f->enemy_old = 1000000000;
	while (res.y < f->sm_y)
	{
		if (check_p2(res, *f, 0, 0) == 0)
			res = res_plus(f, res);
		else
		{
			*f = find_all(res, *f);
			if (f->enemy < f->enemy_old)
			{
				f->enemy_old = f->enemy;
				save = res;
			}
			res = res_plus(f, res);
		}
	}
	if (f->enemy_old == 1000000000)
		ft_exit(f);
	return (save);
}

int		check_p1(t_vec2 res, t_f f, int x, int y)
{
	int nb;

	nb = 0;
	if (check_inbounds(res, f) == 0)
		return (0);
	while (y < f.sp_y)
	{
		while (x < f.sp_x)
		{
			if (f.p[y][x] == '*' && (f.m[res.y + y][res.x + x] == 'O'
			|| f.m[res.y + y][res.x + x] == 'o'))
				nb++;
			if (f.p[y][x] == '*' && (f.m[res.y + y][res.x + x] == 'x'
			|| f.m[res.y + y][res.x + x] == 'X'))
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	if (nb != 1)
		return (0);
	return (1);
}

t_vec2	algo1(t_f *f)
{
	t_vec2 res;
	t_vec2 save;

	save = f->minpos;
	res = f->minpos;
	f->enemy_old = 1000000000;
	while (res.y < f->sm_y)
	{
		if (check_p1(res, *f, 0, 0) == 0)
			res = res_plus(f, res);
		else
		{
			*f = find_all(res, *f);
			if (f->enemy < f->enemy_old)
			{
				f->enemy_old = f->enemy;
				save = res;
			}
			res = res_plus(f, res);
		}
	}
	if (f->enemy_old == 1000000000)
		ft_exit(f);
	return (save);
}
