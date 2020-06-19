/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 09:48:36 by tima              #+#    #+#             */
/*   Updated: 2020/06/11 12:40:24 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		read_operations(t_ps *push)
{
	char*	line;
	int		ret;

	line = NULL;
	while((ret = get_next_line(0, &line)) > 0)
	{
		if (ret < 0 || validate_options(line) == 1)
		{
			ft_memdel((void**)&line);
			return (1);
		}
		do_operations_1(line, push);
		ft_memdel((void**)&line);
	}
	return (0);
}

void	do_operations_1(const char *line, t_ps *push)
{	
	t_stack *stack_A;
	t_stack *stack_B;

	stack_A = push->stack_A;
	stack_B = push->stack_B;
	if (ft_strcmp("sa", line) == 0 || ft_strcmp("ss", line) == 0)
		do_sa_sb(stack_A, push->size_A);
	if (ft_strcmp("sb", line) == 0 || ft_strcmp("ss", line) == 0)
		do_sa_sb(stack_B, push->size_B);
	if (ft_strcmp("pa", line) == 0)
		do_pa(push, stack_A, stack_B);
	if (ft_strcmp("pb", line) == 0)
		do_pb(push, stack_B, stack_A);
	if (ft_strcmp("ra", line) == 0 || ft_strcmp("rr", line) == 0)
		do_ra_rb(stack_A, push->size_A);
	if (ft_strcmp("rb", line) == 0 || ft_strcmp("rr", line) == 0)
		do_ra_rb(stack_B, push->size_B);
	if (ft_strcmp("rra", line) == 0 || ft_strcmp("rrr", line) == 0)
		do_rra_rrb(stack_A, push->size_A);
	if (ft_strcmp("rrb", line) == 0 || ft_strcmp("rrr", line) == 0)
		do_rra_rrb(stack_B, push->size_B);
}

int	main(int argc, char **argv)
{
	t_ps push;

	if (argc > 1)
	{
		if (create_stacks(&push, argc, argv) == 1)
			return (error_free(&push));
		if (duplicate_found(push.stack_A->next) == 1)
			return (error_free(&push));
		if (read_operations(&push) == 1)
			return (error_free(&push));
		if (is_sort(push.stack_A->next) == 1 || push.size_B != 0)
			write(1, "KO\n", 3);
		else
			write(1, "OK\n", 3);
		correct_free(&push);
	}
	return (0);
}
