/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 12:20:52 by tima              #+#    #+#             */
/*   Updated: 2020/07/06 18:43:01 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_low_stack(t_ps *push)
{
	t_stack *tmp;

	tmp = push->stack_a;
	while (push->size_a != 3)
	{
		if (tmp->next->elem == push->min || tmp->next->elem == push->max)
			do_operations("ra", push);
		else
			do_operations("pb", push);
	}
	algo_3_elem(push);
}

void	algo_3_elem(t_ps *push)
{
	int a;
	int b;
	int c;

	a = push->stack_a->next->elem;
	b = push->stack_a->next->next->elem;
	c = push->stack_a->next->next->next->elem;
	if (a > b && a < c && b < c)
		do_operations("sa", push);
	if (a > b && a > c && b > c)
		do_operations("sa", push);
	if (a < b && a < c && b > c)
		do_operations("sa", push);
}

void	normalize_stack(t_ps *push, t_stack *stack_a)
{
	int num;
	int flag_ra;
	int flag_rra;

	flag_ra = 0;
	flag_rra = 0;
	num = 0;
	while (stack_a && stack_a->elem != push->min)
	{
		num++;
		stack_a = stack_a->next;
	}
	if (num <= push->size_a / 2)
		flag_ra = num;
	else
		flag_rra = push->size_a - num;
	while (flag_ra-- > 0)
		do_operations("ra", push);
	while (flag_rra-- > 0)
		do_operations("rra", push);
}

void	do_operations(const char *line, t_ps *push)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

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
	ft_printf("%s\n", line);
	push->operations += 1;
}
