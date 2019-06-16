#include "filler.h"

void ft_exit(t_f *f)
{
	int i;
	i = 0;

	if (f->m != NULL)
	{
		while ( i < f->sm_y)
		{
			if (f->m[i] != NULL)
				ft_memdel((void **)&f->m[i]);
			i++;
		}
		ft_memdel((void **)&f->m);
	}
	i = 0;
	if (f->p != NULL)
	{
		while ( i < f->sp_y)
		{
			if (f->p[i] != NULL)
				ft_memdel((void **)&f->p[i]);
			i++;
		}
		ft_memdel((void **)&f->p);
	}
	exit(0);
}
int	main(void)
{
	t_f f;

	f.sm_x = 0;
	f.sm_y = 0;
	f.player = 1;
	f.start.x = -2;
	f.done = 0;
	f.touched = 0;
	f.enemy_old = 1000000000;
	f = read_fd(&f);
	FILE* file = NULL;
	file = fopen("read.txt", "w");
	FILE* file2 = NULL;
	file2 = fopen("first.txt", "a");
	int i = 0;
	if (file2 != NULL)
	{
	fprintf(file2,"player = %d\n sm x = %d y = %d\n",f.player,f.sm_x,f.sm_y);
	fclose(file2);
	}
	printf("caca boudain");
	if (file != NULL)
	{
		while (i < f.sm_y)
		{
		fprintf(file,"%zu : %s \n",ft_strlen(f.m[i]),f.m[i]);
		i++;
		}
		i = 0;
		while (i < f.sp_y)
		{
		fprintf(file,"%zu : %s \n",ft_strlen(f.p[i]),f.p[i]);
		i++;
		}
		fclose(file);
	}
	return (0);
}
