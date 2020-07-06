/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 21:37:33 by tima              #+#    #+#             */
/*   Updated: 2020/07/06 18:55:28 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_visu.h"

void	do_operations_1(const char *line, t_ps *push)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = push->stack_a;
	stack_b = push->stack_b;
	if (ft_strcmp("sa", line) == 0 || ft_strcmp("ss", line) == 0)
		do_sa_sb(stack_a, push->size_a);
	if (ft_strcmp("sb", line) == 0 || ft_strcmp("ss", line) == 0)
		do_sa_sb(stack_b, push->size_b);
	if (ft_strcmp("pa", line) == 0)
		do_pa(push, stack_a, stack_b);
	if (ft_strcmp("pb", line) == 0)
		do_pb(push, stack_b, stack_a);
	if (ft_strcmp("ra", line) == 0 || ft_strcmp("rr", line) == 0)
		do_ra_rb(stack_a, push->size_a);
	if (ft_strcmp("rb", line) == 0 || ft_strcmp("rr", line) == 0)
		do_ra_rb(stack_b, push->size_b);
	if (ft_strcmp("rra", line) == 0 || ft_strcmp("rrr", line) == 0)
		do_rra_rrb(stack_a, push->size_a);
	if (ft_strcmp("rrb", line) == 0 || ft_strcmp("rrr", line) == 0)
		do_rra_rrb(stack_b, push->size_b);
}

int		validate_options(const char *str)
{
	if (!str)
		return (1);
	if (ft_strcmp(str, "sa") && ft_strcmp(str, "sb") &&
		ft_strcmp(str, "ss") && ft_strcmp(str, "pa") &&
		ft_strcmp(str, "pb") && ft_strcmp(str, "ra") &&
		ft_strcmp(str, "rb") && ft_strcmp(str, "rr") &&
		ft_strcmp(str, "rra") && ft_strcmp(str, "rrb") &&
		ft_strcmp(str, "rrr"))
		return (1);
	return (0);
}

int		sdl_read_options(t_op *op)
{
	char	*line;
	int		ret;

	line = NULL;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (ret < 0 || validate_options(line) == 1)
		{
			ft_memdel((void**)&line);
			return (1);
		}
		if (!(op->next = sdl_new_list(line)))
			return (1);
		op = op->next;
	}
	return (0);
}

t_op	*sdl_new_list(const char *line)
{
	t_op	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_op))))
		return (NULL);
	tmp->op = line;
	return (tmp);
}

int		main(int argc, char **argv)
{
	t_sdl	d;
	t_ps	push;
	t_op	*op;

	if (argc > 1)
	{
		if (create_stacks(&push, argc, argv) == 1)
			return (error_free(&push));
		if (duplicate_found(push.stack_a->next) == 1)
			return (error_free(&push));
		if (push.size > 500)
			return (sdl_limit(&push));
		if (!(op = ft_memalloc(sizeof(t_op))))
			return (error_free(&push));
		if (sdl_read_options(op) == 1)
		{
			vis_free_list(&op);
			return (error_free(&push));
		}
		do_draw(&d, &push, op);
		sdl_quit(&d, &push, op);
	}
	return (0);
}
