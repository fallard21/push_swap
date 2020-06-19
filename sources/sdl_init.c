/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 22:30:50 by tima              #+#    #+#             */
/*   Updated: 2020/06/19 22:14:13 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_visu.h"

void	sdl_init(t_sdl *draw)
{
	int status;

	ft_memset(draw, 0, sizeof(t_sdl));
	status = SDL_Init(SDL_INIT_EVERYTHING);
	if (status)
	{
		ft_printf("Error initialising SDL2\n");
		exit(EXIT_FAILURE);
	}
	status = TTF_Init();
	if (status)
	{
		ft_printf("Error initialising TTF\n");
		exit(EXIT_FAILURE);
	}
	draw->window = SDL_CreateWindow("Push_swap visualizer", DIS_X, DIS_Y, DIS_W, DIS_H, SDL_WINDOW_SHOWN);
    if (!draw->window)
		ft_exit(draw, 5);
	draw->rend = SDL_CreateRenderer(draw->window, -1, SDL_RENDERER_ACCELERATED);
	if (!draw->rend)
		ft_exit(draw, 6);
}

void	sdl_init_cube(t_sdl *draw, t_ps *push)
{	
	if (push->size < 30)
		draw->cube_rect.w = 30;
	else
		draw->cube_rect.w = ((DIS_W - 100) / push->size) + 1;
	draw->diff_x = draw->cube_rect.w - 1;
	draw->gist_h = -500;
	draw->gist_x = (DIS_W - (draw->diff_x * push->size)) / 2;
	draw->cube_rect.h = draw->gist_h;
	draw->cube_rect.x = draw->gist_x;
	draw->cube_rect.y = DIS_H * 0.85;
}

void	sdl_background(t_sdl *draw)
{
	draw->background = IMG_LoadTexture(draw->rend, "sources/data/pic_1_(14).jpg");
	if (!draw->background)
		ft_exit(draw, 7);
	draw->back_rect.x = 0;
	draw->back_rect.y = 0;
	draw->back_rect.h = DIS_H;
	draw->back_rect.w = DIS_W;

	SDL_RenderCopy(draw->rend, draw->background, NULL, &draw->back_rect);
	SDL_RenderPresent(draw->rend);
}
