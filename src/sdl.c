/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 18:15:41 by fmerding          #+#    #+#             */
/*   Updated: 2019/06/24 04:27:24 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		set_pixel(t_texture *text, Uint32 color, t_vec2 coord)
{
	if (coord.x >= 0 && coord.x < WIDTH && coord.y >= 0
		&& coord.y < HEIGHT)
	{
		text->content[coord.x + coord.y * WIDTH] = color;
	}
}

void		update_image(t_f *f, t_texture *tex)
{
	SDL_SetRenderTarget(f->renderer, tex->texture);
	SDL_UpdateTexture(tex->texture, NULL, tex->content, WIDTH
		* sizeof(Uint32));
	SDL_SetRenderTarget(f->renderer, NULL);
	SDL_RenderCopy(f->renderer, tex->texture, NULL, NULL);
	SDL_RenderPresent(f->renderer);
}

t_texture	*initialize_texture(t_f *f, int width, int height)
{
	t_texture	*text;

	if (!(text = (t_texture *)malloc(sizeof(t_texture))))
		return (NULL);
	if (!(text->content = (Uint32 *)malloc(width * height * sizeof(Uint32))))
		return (NULL);
	if (!(text->texture = SDL_CreateTexture(f->renderer,
			SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height)))
		return (NULL);
	text->color_tmp = 0xFFFFFFFF;
	return (text);
}

void		initialize_sdl(t_f *f)
{
	f->window = NULL;
	f->renderer = NULL;
	f->tex = NULL;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
		ft_putstr("Échec de l'initialisation de la SDL");
		ft_exit(f);
	}
	if (!(f->window = SDL_CreateWindow("Filler", 200,
	200, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)))
	{
		ft_putstr("Échec de creation de la fenetre");
		ft_exit(f);
	}
	if (!(f->renderer = SDL_CreateRenderer(f->window, -1, 0)))
	{
		ft_putstr("Échec de chargement du renderer");
		ft_exit(f);
	}
	if (!(f->tex = initialize_texture(f, WIDTH, HEIGHT)))
	{
		ft_putstr("Échec d'initialisation des textures");
		ft_exit(f);
	}
}
