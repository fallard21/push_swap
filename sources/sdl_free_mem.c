/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_free_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 22:34:59 by tima              #+#    #+#             */
/*   Updated: 2020/06/19 22:32:16 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_visu.h"

int		ft_exit(t_sdl *draw, int status)
{
	if (status == 1)
		ft_printf("Error creating font\n");
	else if (status == 2)
		ft_printf("Error creating render text\n");
	else if (status == 3)
		ft_printf("Error creating TTF texture\n");
	else if (status == 4)
		ft_printf("Error while memory allocation\n");
	else if (status == 5)
		ft_printf("Error creating window\n");
	else if (status == 6)
		ft_printf("Error creating render\n");
	else if (status == 7)
		ft_printf("Error creating IMG texture\n");
	TTF_CloseFont(draw->font);
	SDL_DestroyTexture(draw->background);
	sdl_memdel(&draw->area, &draw->fontex);
	SDL_DestroyRenderer(draw->rend);
	SDL_DestroyWindow(draw->window);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	exit(EXIT_FAILURE);
}

void	vis_free_list(t_op **head)
{
	t_op	*next;

	while(*head)
	{
		next = (*head)->next;
		ft_memdel((void**)&(*head)->op);
		ft_memdel((void**)&(*head));
		*head = next;
	}
}

void	sdl_memdel(SDL_Surface **surf, SDL_Texture **text)
{
	SDL_FreeSurface(*surf);
	*surf = NULL;
	SDL_DestroyTexture(*text);
	*text = NULL;
}

void	sdl_quit(t_sdl *d, t_ps *push, t_op *op)
{
	SDL_DestroyTexture(d->background);
	SDL_DestroyRenderer(d->rend);
	SDL_DestroyWindow(d->window);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	vis_free_list(&op);
	correct_free(push);
}

int		sdl_limit(t_ps *push)
{
	ft_printf("{3}Number of elements too big for visualisation!{0}\n");
	correct_free(push);
	return (1);
}
