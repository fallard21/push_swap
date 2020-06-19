/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_visu.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 21:38:22 by tima              #+#    #+#             */
/*   Updated: 2020/06/19 22:34:02 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_VISU_H
# define PS_VISU_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>
# include "libft.h"
# include "push_swap.h"

# define DIS_W 1600
# define DIS_H 800
# define DIS_X 40
# define DIS_Y 40

typedef struct s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*rend;
	SDL_Texture		*background;
	SDL_Rect		back_rect;
	SDL_Rect		cube_rect;
	TTF_Font		*font;
	SDL_Surface		*area;
	SDL_Texture		*fontex;
	SDL_Color		color;
	SDL_Rect		font_rect;
	SDL_Rect		title_rect;
	SDL_Event		event;
	const Uint8		*keyboard;
	int				quit;
	int				flag;
    int             gist_x;
	int             gist_h;
	int             diff_x;
    int             operations;
}					t_sdl;

typedef	struct s_op
{
	struct s_op		*next;
	const char		*op;
}					t_op;

/*
** >-------------------------< CREATING STACKS >-------------------------<
*/
int					sdl_read_options(t_op *op);
t_op				*sdl_new_list(const char *line);

/*
** >-----------------------------< INIT SDL >----------------------------<
*/
void				sdl_init(t_sdl *draw);
void				sdl_init_cube(t_sdl *draw, t_ps *push);
void				sdl_background(t_sdl *draw);
void				sdl_title(t_sdl *d);

/*
** >-----------------------------< DRAWING >-----------------------------<
*/
void				sdl_init_index(t_ps *push, t_stack *A);
void				do_draw(t_sdl *d, t_ps *push, t_op *op);
void				sdl_main_loop(t_sdl *d, t_ps *push, t_op *op);
void				sdl_draw_stacks(t_sdl *d, t_ps *push);
void				sdl_draw_A(t_sdl *d, t_ps *push);
void				sdl_draw_B(t_sdl *d, t_ps *push);

/*
** >---------------------------< PUT RESULTS >---------------------------<
*/
void				sdl_result(t_sdl *d, t_ps *push);
void				sdl_put_op(t_sdl *d);

/*
** >------------------------< MEMORY MANAGEMENT >------------------------<
*/
void				sdl_memdel(SDL_Surface **surf, SDL_Texture **text);
void				sdl_quit(t_sdl *d, t_ps *push, t_op *op);
int					sdl_limit(t_ps *push);
void				vis_free_list(t_op **head);
int					ft_exit(t_sdl *draw, int status);

#endif
