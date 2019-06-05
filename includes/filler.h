#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
typedef struct	s_f
{
	char	**m;
	int		sm_x;
	int		sm_y;
	char	**p;
	int		sp_x;
	int		sp_y;
	t_vec2	pos;
	int		player;
	// char **
	// t_fvec2 y;
	// t_fvec2 z;
}				t_f;

t_f	read_fd(t_f *f);
t_f	first_read_fd(t_f *f);
t_f	init(t_f *f);
t_f	re_init(t_f *f, char* line);
#endif
