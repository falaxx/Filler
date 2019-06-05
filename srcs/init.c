#include "filler.h"

t_f	init(t_f *f)
{
	int i;

	i = 0;
	f->sp_x = 0;
	f->sp_y = 0;
	f->p = 0;
	f->pos.x = 0;
	f->pos.y = 0;
	if (!(f->m = (char **)malloc(sizeof(char*) * f->sm_y)))
		exit(0); //ft_exit
	while(i < f->sm_y)
	{
		if (!(f->m[i] = (char *)malloc(sizeof(char) * f->sm_x + 1)))
			exit(0); //ft_exit
		f->m[i][f->sm_x] = '\0';
		i++;
	}
	return (*f);
}

t_f	re_init(t_f *f, char* line)
{
	int		i;
	char	*tmp;

	i = 0;
	f->sp_y = ft_getnbr_n(line, 6);
	tmp = ft_itoa(f->sm_y);
	f->sp_x = ft_getnbr_n(line, 7 + ft_strlen(tmp));
	free(tmp);
	if (!(f->p = (char **)malloc(sizeof(char*) * f->sp_y)))
		exit(0); //ft_exit
	while(i < f->sp_y)
	{
		if (!(f->p[i] = (char *)malloc(sizeof(char) * f->sp_x + 1)))
			exit(0); //ft_exit
		f->p[i][f->sp_x] = '\0';
		i++;
	}
	return (*f);
}
