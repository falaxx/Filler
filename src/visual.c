#include "filler.h"

void	ft_exit(t_f *f)
{
	int i;

	i = 0;
	if (f->m != NULL)
	{
		while (i < f->sm_y)
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
		while (i < f->sp_y)
		{
			if (f->p[i] != NULL)
				ft_memdel((void **)&f->p[i]);
			i++;
		}
		ft_memdel((void **)&f->p);
	}
	if (f->window != NULL)
		ft_memdel((void **)&f->window);
	if (f->renderer != NULL)
		ft_memdel((void **)&f->renderer);
	if (f->event != NULL)
		ft_memdel((void **)&f->event);
	exit(0);
}

int		main(void)
{
	t_f f;

	f.sm_x = 0;
	f.sm_y = 0;
	f.i = 0;
	f.j = 0;
	f.k = 0;
	f.player = 1;
	f.start.x = -2;
	f.done = 0;
	f = initialize_sdl(&f);
	f = read_fd(&f);
	return (0);
}
