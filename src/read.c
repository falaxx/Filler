#include "filler.h"

t_f	first_read_fd(t_f *f)
{
	char	*line;
	char	*tmp;

	int		i;
	int		j;
	i = 1;
	j = 1;

	while (i > 0)
	{
		line = NULL;
		i = get_next_line(0, &line);
		if (line[0] == '$'&& f->sm_y == 0)
			if(ft_strstr(line,"p2"))
				f->player = 2;
		if (line[0] == 'P' && line[1] == 'l' && f->sm_y == 0)
		{
			f->sm_y = ft_getnbr_n(line,8);
			tmp = ft_itoa(f->sm_y);
			f->sm_x = ft_getnbr_n(line,9 + ft_strlen(tmp));
			free(tmp);
		}
		ft_memdel((void **)&line);
		if (i == 0 || f->sm_y > 0)
			break;
	}

	return (*f);
}

t_f	parse_map(t_f *f, char* line, int i)
{
	size_t j;
	int k;

	k = 0;
	j = 0;
	while(ft_isdigit(line[j]))
		j++;
	j++;
	while(k < f->sm_x)
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
	return(*f);
}

t_f	read_fd(t_f *f)
{
	char		*line;
	int			j;
	int			i;
	int			k;
	char		*tmp;

	tmp = NULL;
	i = 0;
	j = 0;
	k = 0;
	line = NULL;

		while (get_next_line(0, &line) > 0)
		{
			if (f->start.x == -2)
			{
				if (line[0] == '$'&& f->sm_y == 0)
					if(ft_strstr(line,"p2"))
						f->player = 2;
				if (line[0] == 'P' && line[1] == 'l' && f->sm_y == 0)
				{
					f->sm_y = ft_getnbr_n(line,8);
					tmp = ft_itoa(f->sm_y);
					f->sm_x = ft_getnbr_n(line,9 + ft_strlen(tmp));
					free(tmp);
				}
				if (f->sm_y != 0)
					*f = init(f);
			}
			if (ft_isdigit(line[0]))
			{
				*f = parse_map(f, line, j);
				j++;
			}
			if (ft_strstr(line, "Piece"))
				*f = re_init(f, line);
			if (line[0] == '.' || line[0] == '*')
			{
				ft_strcpy(f->p[k], line);
				k++;
				if (k == f->sp_y)
					f->done = 3;
			}
			if (f->done == 3)
			{
				j = 0;
				k = 0;
				f->pos.y = f->start.y;
				f->pos.x = f->start.x;
				f->pos = algo(f);
				ft_putnbr(f->pos.y);
				ft_putchar(' ');
				ft_putnbr(f->pos.x);
				ft_putchar('\n');
				f->done = 1;
				// sleep(1);
				while (j < f->sp_y)
				{
					if (f->p[j] != NULL)
						ft_memdel((void **)&f->p[j]);
					j++;
				}
				ft_memdel((void **)&f->p);
				j = 0;
			}
			ft_memdel((void **)&line);
		}
	return(*f);
}
