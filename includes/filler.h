#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# include <SDL.h>

# define WIDTH 1000
# define HEIGHT 1000

typedef struct		s_texture {
	Uint32			*content;
	SDL_Texture		*texture;
	Uint32			color_tmp;
}					t_texture;

typedef struct	s_f
{
	char			**m;  //map
	int				sm_x; //size map x
	int				sm_y; //size map y
	char			**p; //piece
	int				sp_x; //size piece x
	int				sp_y; //size piece y
	t_vec2			pos; //pos dans le parsing
	t_vec2			start; //player start
	t_vec2			minpos; // position negative min pour placer la piece.
	int				player; // 1 ou 2
	int				test; // pour putstr f->test
	int				done; // surveille lavancement dans la boucle 4 = fini
	int				enemy; // distance avec lennemi /
	int				enemy_old; // distance avec lennemi /
	int				i;//
	int				j;//
	int				k;//
	int				height;
	int				width;
	int				ppx;
	int				ppy;
	SDL_Window		*window;//
	SDL_Renderer	*renderer;//
	t_texture		*tex;
	SDL_Event		event;
}				t_f;

t_f		read_fd(t_f *f);
t_f		first_read_fd(t_f *f);
t_f		init(t_f *f);
t_f		re_init(t_f *f, char* line);
t_vec2	algo(t_f *f);
void	ft_exit(t_f *f);
void	initialize_sdl(t_f *f);
void	update_image(t_f *f, t_texture *tex);
void	set_pixel(t_texture *text, Uint32 color, t_vec2 coord);
#endif
