/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 22:36:54 by tima              #+#    #+#             */
/*   Updated: 2020/06/19 19:41:32 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_visu.h"

void	sdl_main_loop(t_sdl *d, t_ps *push, t_op *op)
{
	t_op	*tmp;

	tmp = op->next;
	while(!d->quit)
	{
		while(SDL_PollEvent(&d->event))
		{
			if (d->event.type == SDL_QUIT || d->keyboard[SDL_SCANCODE_ESCAPE])
				d->quit = 1;
			if (d->keyboard[SDL_SCANCODE_RIGHT] && d->flag == 1)
			{	
				if(!tmp)
				{
					sdl_result(d, push);
					continue ;
				}
				do_operations_1(tmp->op, push);
				sdl_draw_stacks(d, push);
				tmp = tmp->next;
				d->operations += 1;
			}
        }	
    }
}
