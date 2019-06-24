#include "filler.h"

int	check_inbounds(t_vec2 res, t_f f)
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

int	check_p2(t_vec2 res, t_f f, int x, int y)
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

int	check_p1(t_vec2 res, t_f f, int x, int y)
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

t_vec2	algo(t_f *f)
{
	t_vec2 res;
	t_vec2 save;

	save = f->minpos;
	res = f->minpos;
	f->enemy_old = 1000000000;
	if (f->player == 2)
	{
		while (res.y < f->sm_y)
		{
			if (check_p2(res, *f, 0, 0) == 0)
			{
				res.x++;
				if (res.x == f->sm_x - 1)
				{
					res.x = f->minpos.x;
					res.y++;
				}
			}
			else
			{
				f->test = -100;
				*f = find_all(res, *f);
				if (f->enemy < f->enemy_old)
				{
					f->enemy_old = f->enemy;
					save = res;
				}
				res.x++;
				if (res.x == f->sm_x - 1)
				{
					res.x = f->minpos.x;
					res.y++;
				}
			}
		}
	}
	if (f->player == 1)
	{
		while (res.y < f->sm_y)
		{
			if (check_p1(res, *f, 0, 0) == 0)
			{
				res.x++;
				if (res.x == f->sm_x - 1)
				{
					res.x = f->minpos.x;
					res.y++;
				}
			}
			else
			{
				*f = find_all(res, *f);
				if (f->enemy < f->enemy_old)
				{
					f->enemy_old = f->enemy;
					save = res;
				}
				res.x++;
				if (res.x == f->sm_x - 1)
				{
					res.x = f->minpos.x;
					res.y++;
				}
			}
		}
	}
	if (f->enemy_old == 1000000000)
		ft_exit(f);
	return (save);
}
