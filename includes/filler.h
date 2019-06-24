/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 05:33:35 by fmerding          #+#    #+#             */
/*   Updated: 2019/06/24 05:44:38 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include <SDL.h>

# define WIDTH 1000
# define HEIGHT 1000

typedef struct		s_texture {
	Uint32			*content;
	SDL_Texture		*texture;
	Uint32			color_tmp;
}					t_texture;

typedef struct		s_f
{
	char			**m;
	int				sm_x;
	int				sm_y;
	char			**p;
	int				sp_x;
	int				sp_y;
	t_vec2			pos;
	t_vec2			start;
	t_vec2			minpos;
	int				player;
	int				done;
	int				enemy;
	int				enemy_old;
	int				i;
	int				j;
	int				k;
	int				ppx;
	int				ppy;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	t_texture		*tex;
	SDL_Event		event;
}					t_f;

t_f					read_fd(t_f *f);
t_f					first_read_fd(t_f *f);
t_f					init(t_f *f);
t_f					re_init(t_f *f, char *line);
t_vec2				algo1(t_f *f);
t_vec2				algo2(t_f *f);
void				ft_exit(t_f *f);
void				initialize_sdl(t_f *f);
void				update_image(t_f *f, t_texture *tex);
void				set_pixel(t_texture *text, Uint32 color, t_vec2 coord);
t_texture			black(t_texture tex);
t_f					render(t_f *f);
t_f					find_all(t_vec2 res, t_f f);
int					check_inbounds(t_vec2 res, t_f f);
#endif
