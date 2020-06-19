/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:07:43 by tima              #+#    #+#             */
/*   Updated: 2020/06/19 21:08:43 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_visu.h"

void	sdl_init_index(t_ps *push, t_stack *A)
{
	t_stack	*tmp;
	t_stack	*min;
	int		min_elem;
	int		i;

	i = 0;
	while (i < push->size_A)
	{
		tmp = A;
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
	sdl_init_index(push, push->stack_A->next);
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
	sdl_draw_A(d, push);
	sdl_draw_B(d, push);
	SDL_RenderPresent(d->rend);
}

void	sdl_draw_A(t_sdl *d, t_ps *push)
{
	t_stack *A;

	A = push->stack_A->next;
	while (A)
	{
		d->cube_rect.h = (A->index * d->gist_h) / push->size;
		SDL_SetRenderDrawColor(d->rend, 220, 170, 0, 1);
		SDL_RenderFillRect(d->rend, &d->cube_rect);
		SDL_SetRenderDrawColor(d->rend, 0, 0, 0, 1);
		SDL_RenderDrawRect(d->rend, &d->cube_rect);
		A = A->next;
		d->cube_rect.x += d->diff_x;
	}
}

void	sdl_draw_B(t_sdl *d, t_ps *push)
{
	t_stack *B;

	B = push->stack_B->next;
	while (B)
	{
		d->cube_rect.h = (B->index * d->gist_h) / push->size;
		SDL_SetRenderDrawColor(d->rend, 20, 90, 255, 1);
		SDL_RenderFillRect(d->rend, &d->cube_rect);
		SDL_SetRenderDrawColor(d->rend, 0, 0, 0, 1);
		SDL_RenderDrawRect(d->rend, &d->cube_rect);
		B = B->next;
		d->cube_rect.x += d->diff_x;
	}
}
