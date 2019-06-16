#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
typedef struct	s_f
{
	char	**m;  //map
	int		sm_x; //size map x
	int		sm_y; //size map y
	char	**p; //piece
	int		sp_x; //size piece x
	int		sp_y; //size piece y
	t_vec2	pos; //pos dans le parsing
	t_vec2	start; //player start
	t_vec2	minpos; // position negative min pour placer la piece.
	int		player; // 1 ou 2
	int		test; // pour putstr f->test
	int		done; // surveille lavancement dans la boucle 4 = fini
	int		empty; // places autour de la piece
	int		empty_old; // places autour de la piece
	int		enemy; // distance avec lennemi /
	int		enemy_old; // distance avec lennemi /
	int		touched;
}				t_f;

t_f		read_fd(t_f *f);
t_f		first_read_fd(t_f *f);
t_f		init(t_f *f);
t_f		re_init(t_f *f, char* line);
t_vec2	algo(t_f *f);
void	ft_exit(t_f *f);
#endif
