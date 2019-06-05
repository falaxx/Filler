#include "filler.h"

t_f	first_read_fd(t_f *f)
{
	char	*line;
	char	*tmp;
	FILE* file = NULL;
	int		i;
	int		j;
	i = 1;
	j = 1;
	file = fopen("first.txt", "w");
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
	if (file != NULL)
	{
	fprintf(file,"player = %d\n sm x = %d y = %d\n",f->player,f->sm_x,f->sm_y);
	fclose(file);
	}
	return (*f);
}

t_f	parse_map(t_f *f, char* line)
{
	size_t j;
	j = 0;
	while(ft_isdigit(line[j]))
		j++;
	j++;
	while(j < ft_strlen(line))
	{
		f->m[f->pos.y][f->pos.x] = line[j];
		f->pos.x++;
		j++;
	}
	j = 0;
	f->pos.y++;
	f->pos.x = 0;
	return(*f);
}

t_f	parse_piece(t_f *f, char* line)
{
	int		i;
	int		j;

	j = 0;
	i = 1;
	if (ft_strstr(line, "Piece"))
		*f = re_init(f, line);
	while (i > 0)
	{
		i = get_next_line(0, &line);
		if (i < 1)
			break;
		ft_strcpy(f->p[j], line);
		ft_memdel((void **)&line);
		j++;
	}
	return(*f);
}

t_f	read_fd(t_f *f)
{
	char		*line;
	int			i;
	FILE* file = NULL;

	file = fopen("read.txt", "w");
	i = 1;
	while (i > 0)
	{
		line = NULL;
		i = get_next_line(0, &line);
		if (i < 1)
			break;
		if (ft_isdigit(line[0]))
			parse_map(f, line);
		if (line[0] == '.' || line[0] == '*' || (ft_strstr(line, "Piece")))
			*f = parse_piece(f, line);
		ft_memdel((void **)&line);
	}
	i = 0;
	if (file != NULL)
	{
		while (i < f->pos.y)
		{
		fprintf(file,"%zu : %s \n",ft_strlen(f->m[i]),f->m[i]);
		i++;
		}
		i = 0;
		while (i < f->sp_y)
		{
		fprintf(file,"%zu : %s \n",ft_strlen(f->p[i]),f->p[i]);
		i++;
		}
		fclose(file);

	}
	return(*f);
}
