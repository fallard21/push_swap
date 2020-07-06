/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:07:43 by tima              #+#    #+#             */
/*   Updated: 2020/07/06 19:09:59 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_visu.h"

void	sdl_init_index(t_ps *push, t_stack *a)
{
	t_stack	*tmp;
	t_stack	*min;
	int		min_elem;
	int		i;

	i = 0;
	while (i < push->size_a)
	{
		tmp = a;
		min_elem = INT_MAX;
		min = NULL;
		while (tmp)
		{
			if (tmp->elem < min_elem && tmp->index == 0)
			{
				min = tmp;
				min_elem = tmp->elem;
			}
			tmp = tmp->next;
		}
		min->index = i + 1;
		i++;
	}
}

void	do_draw(t_sdl *draw, t_ps *push, t_op *op)
{
	sdl_init(draw);
	sdl_background(draw);
	sdl_title(draw);
	sdl_init_cube(draw, push);
	sdl_init_index(push, push->stack_a->next);
	sdl_draw_stacks(draw, push);
	draw->quit = 0;
	draw->flag = 1;
	draw->keyboard = SDL_GetKeyboardState(NULL);
	sdl_main_loop(draw, push, op);
}

void	sdl_draw_stacks(t_sdl *d, t_ps *push)
{
	SDL_RenderClear(d->rend);
	SDL_RenderCopy(d->rend, d->background, NULL, &d->back_rect);
	SDL_RenderCopy(d->rend, d->fontex, NULL, &d->title_rect);
	d->cube_rect.x = d->gist_x;
	sdl_draw_a(d, push);
	sdl_draw_b(d, push);
	SDL_RenderPresent(d->rend);
}

void	sdl_draw_a(t_sdl *d, t_ps *push)
{
	t_stack *a;

	a = push->stack_a->next;
	while (a)
	{
		d->cube_rect.h = (a->index * d->gist_h) / push->size;
		SDL_SetRenderDrawColor(d->rend, 220, 170, 0, 1);
		SDL_RenderFillRect(d->rend, &d->cube_rect);
		SDL_SetRenderDrawColor(d->rend, 0, 0, 0, 1);
		SDL_RenderDrawRect(d->rend, &d->cube_rect);
		a = a->next;
		d->cube_rect.x += d->diff_x;
	}
}

void	sdl_draw_b(t_sdl *d, t_ps *push)
{
	t_stack *b;

	b = push->stack_b->next;
	while (b)
	{
		d->cube_rect.h = (b->index * d->gist_h) / push->size;
		SDL_SetRenderDrawColor(d->rend, 20, 90, 255, 1);
		SDL_RenderFillRect(d->rend, &d->cube_rect);
		SDL_SetRenderDrawColor(d->rend, 0, 0, 0, 1);
		SDL_RenderDrawRect(d->rend, &d->cube_rect);
		b = b->next;
		d->cube_rect.x += d->diff_x;
	}
}
