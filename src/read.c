/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:54:46 by fmerding          #+#    #+#             */
/*   Updated: 2019/06/24 05:21:57 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_f		parse_map(t_f *f, char *line, int i)
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

t_f		read_fd_2(t_f *f, char *line, char *tmp)
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

t_f		read_fd_3(t_f *f, int j)
{
	j = 0;
	f->pos.y = f->start.y;
	f->pos.x = f->start.x;
	if (f->player == 1)
		f->pos = algo1(f);
	else
		f->pos = algo2(f);
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

char	*read_norm(t_f *f, char *line)
{
	ft_strcpy(f->p[f->k], line);
	f->k++;
	if (f->k == f->sp_y)
		f->done = 3;
	return (line);
}

t_f		read_fd(t_f *f)
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
			*f = read_fd_2(f, line, tmp);
			if (ft_isdigit(line[0]))
			{
				*f = parse_map(f, line, f->j);
				f->j++;
			}
			if (line[0] == '.' || line[0] == '*')
				line = read_norm(f, line);
			if (f->done == 3)
				*f = read_fd_3(f, f->j);
			ft_memdel((void **)&line);
		}
	}
	return (*f);
}
