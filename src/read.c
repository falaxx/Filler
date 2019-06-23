/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:54:46 by fmerding          #+#    #+#             */
/*   Updated: 2019/06/23 19:31:05 by fmerding         ###   ########.fr       */
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
			initialize_sdl(f);
		}
		if (f->sm_y != 0)
			*f = init(f);
	}
	if (ft_strstr(line, "Piece"))
		*f = re_init(f, line);
	return (*f);
}

t_texture rose(t_texture tex, t_f *f)
{
	t_vec2 pos;
	pos.x = 0;
	pos.y = 0;
	while(pos.x < 400)
		{
			while (pos.y < 400)
			{
				set_pixel(&tex,0xb48ed7ff,pos,f);
				pos.y++;
			}
			pos.y = 0;
		pos.x ++;
		}
	return(tex);
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
	*f->tex = rose(*f->tex, f);
	update_image(f, f->tex);
	return (*f);
}

t_f	read_fd(t_f *f)
{
	char		*line;
	char		*tmp;

	tmp = NULL;
	line = NULL;
	initialize_sdl(f);
	while ((SDL_PollEvent(&(f->event))) != 0)
	{
		while (get_next_line(0, &line) > 0)
		{
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
