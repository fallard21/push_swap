/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_put_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 17:51:16 by tima              #+#    #+#             */
/*   Updated: 2020/06/19 22:14:31 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_visu.h"

void	sdl_title(t_sdl *d)
{
	int len;

	if (!(d->font = TTF_OpenFont("sources/data/15154.ttf", 200)))
		ft_exit(d, 1);
	d->color = (SDL_Color){110, 110, 250, 1};
	if (!(d->area = TTF_RenderText_Blended(d->font, "Push_swap visualizer", d->color)))
		ft_exit(d, 2);
	if (!(d->fontex = SDL_CreateTextureFromSurface(d->rend, d->area)))
		ft_exit(d, 3);
	len = 20;
	d->title_rect.w = len * 35;
	d->title_rect.h = 90;
	d->title_rect.x = (DIS_W / 2) - (d->title_rect.w / 2);
	d->title_rect.y = DIS_H * 0.02;
	SDL_RenderCopy(d->rend, d->fontex, NULL, &d->title_rect);
}

void	sdl_result(t_sdl *d, t_ps *push)
{
	const char	*res;

	d->flag = 0;
	sdl_memdel(&d->area, &d->fontex);
	res = (is_sort(push->stack_A->next) || push->size_B) ? "KO" : "OK";
	if (!ft_strcmp("OK", res))
		d->color = (SDL_Color){0, 255, 0, 1};
	else
		d->color = (SDL_Color){255, 0, 0, 1};
	if (!(d->area = TTF_RenderText_Blended(d->font, res, d->color)))
		ft_exit(d, 2);
	if (!(d->fontex = SDL_CreateTextureFromSurface(d->rend, d->area)))
		ft_exit(d, 3);
	d->title_rect.w = 120;
	d->title_rect.h = 90;
	d->title_rect.x = (DIS_W / 2) - (d->title_rect.w / 2);
	d->title_rect.y = DIS_H - 100;
	SDL_RenderCopy(d->rend, d->fontex, NULL, &d->title_rect);
	sdl_memdel(&d->area, &d->fontex);
	TTF_CloseFont(d->font);
	d->font = NULL;
	sdl_put_op(d);
	SDL_RenderPresent(d->rend);
}

void	sdl_put_op(t_sdl *d)
{
	int		len;
	char	*str;

	str = ft_itoa(d->operations);
	if (!(str = ft_strjoin_free("Operations: ", str)))
		ft_exit(d, 4);
	if (!(d->font = TTF_OpenFont("sources/data/19440.ttf", 200)))
		ft_exit(d, 1);
	d->color = (SDL_Color){230, 20, 230, 1};
	if (!(d->area = TTF_RenderText_Blended(d->font, str, d->color)))
		ft_exit(d, 2);
	if (!(d->fontex = SDL_CreateTextureFromSurface(d->rend, d->area)))
		ft_exit(d, 3);
	len = ft_strlen(str);
	d->font_rect.w = len * 25;
	d->font_rect.h = 70;
	d->font_rect.x = DIS_W * 0.1;
	d->font_rect.y = DIS_H * 0.3;
	SDL_RenderCopy(d->rend, d->fontex, NULL, &d->font_rect);
	sdl_memdel(&d->area, &d->fontex);
	TTF_CloseFont(d->font);
	d->font = NULL;
}
