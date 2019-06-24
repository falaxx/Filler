/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:54:46 by fmerding          #+#    #+#             */
/*   Updated: 2019/06/24 04:29:14 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_f	parse_map(t_f *f, char *line, int i)
{
	size_t	j;
	int		k;

	k = 0;
	j = 0;
	while (ft_isdigit(line[j]))
		j++;
	j++;
	while (k < f->sm_x)
	{
		f->m[i][k] = line[j];
		if (f->player == 1 && line[j] == 'O' && f->start.x == -1)
		{
			f->start.x = k;
			f->start.y = i;
		}
		if (f->player == 2 && line[j] == 'X' && f->start.x == -1)
		{
			f->start.x = k;
			f->start.y = i;
		}
		k++;
		j++;
	}
	return (*f);
}

t_f	read_fd_2(t_f *f, char *line, char *tmp)
{
	if (f->start.x == -2)
	{
		if (line[0] == '$' && f->sm_y == 0)
			if (ft_strstr(line, "p2"))
				f->player = 2;
		if (line[0] == 'P' && line[1] == 'l' && f->sm_y == 0)
		{
			f->sm_y = ft_getnbr_n(line, 8);
			tmp = ft_itoa(f->sm_y);
			f->sm_x = ft_getnbr_n(line, 9 + ft_strlen(tmp));
			free(tmp);
		}
		if (f->sm_y != 0)
			*f = init(f);
	}
	if (ft_strstr(line, "Piece"))
		*f = re_init(f, line);
	return (*f);
}

t_texture black(t_texture tex)
{
	t_vec2 pos;
	pos.x = 0;
	pos.y = 0;
	while(pos.x < 1000)
		{
			while (pos.y < 1000)
			{
				set_pixel(&tex,0x000000ff,pos);
				pos.y++;
			}
			pos.y = 0;
		pos.x ++;
		}
	return(tex);
}

t_texture red(t_texture tex, t_f *f, t_vec2 pos)
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
	while(pos.x < next.x)
	{
		while (pos.y < next.y)
		{
			set_pixel(&tex,0xff0000ff,pos);
			pos.y++;
		}
		pos.y = save.y;
		pos.x ++;
	}
	return(tex);
}

t_texture blue(t_texture tex, t_f *f, t_vec2 pos)
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
	while(pos.x < next.x)
	{
		while (pos.y < next.y)
		{
			set_pixel(&tex,0x0066ffff,pos);
			pos.y++;
		}
		pos.y = save.y;
		pos.x ++;
	}
	return(tex);
}

t_f render(t_f *f)
{
	int x = 0;
	int y = 0;
	t_vec2 pos;

	while ( y < f->sm_y)
	{
		while ( x < f->sm_x)
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

t_f	read_fd_3(t_f *f, int j)
{
	j = 0;
	f->pos.y = f->start.y;
	f->pos.x = f->start.x;
	f->pos = algo(f);
	ft_putnbr(f->pos.y);
	ft_putchar(' ');
	ft_putnbr(f->pos.x);
	ft_putchar('\n');
	f->done = 1;
	while (j < f->sp_y)
	{
		if (f->p[j] != NULL)
			ft_memdel((void **)&f->p[j]);
		j++;
	}
	ft_memdel((void **)&f->p);
	f->k = 0;
	f->j = 0;
	render(f);
	return (*f);
}

t_f	read_fd(t_f *f)
{
	char		*line;
	char		*tmp;

	tmp = NULL;
	line = NULL;
	initialize_sdl(f);
	*f->tex = black(*f->tex);
	while ((SDL_PollEvent(&(f->event))) != 0)
	{
		while (get_next_line(0, &line) > 0)
		{
			if (f->event.type == SDL_QUIT)
				ft_exit(0);
			if (f->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				ft_exit(0);
			*f = read_fd_2(f, line, tmp);
			if (ft_isdigit(line[0]))
			{
				*f = parse_map(f, line, f->j);
				f->j++;
			}
			if (line[0] == '.' || line[0] == '*')
			{
				ft_strcpy(f->p[f->k], line);
				f->k++;
				if (f->k == f->sp_y)
					f->done = 3;
			}
			if (f->done == 3)
				*f = read_fd_3(f, f->j);
			ft_memdel((void **)&line);
		}
	}
	return (*f);
}
