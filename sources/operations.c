/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 10:11:20 by tima              #+#    #+#             */
/*   Updated: 2020/07/06 18:51:11 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa_sb(t_stack *stack_0, int size)
{
	t_stack	*stack_1;
	t_stack	*tmp;

	if (size > 1)
	{
		stack_1 = stack_0->next;
		tmp = stack_1->next;
		stack_0->next = stack_1->next;
		stack_1->next = tmp->next;
		tmp->next = stack_1;
	}
}

void	do_pb(t_ps *push, t_stack *stack_b, t_stack *stack_a)
{
	t_stack	*tmp;

	if (push->size_a > 0)
	{
		tmp = stack_a->next;
		stack_a->next = tmp->next;
		tmp->next = stack_b->next;
		stack_b->next = tmp;
		push->size_a = push->size_a - 1;
		push->size_b = push->size_b + 1;
	}
}

void	do_pa(t_ps *push, t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;

	if (push->size_b > 0)
	{
		tmp = stack_b->next;
		stack_b->next = tmp->next;
		tmp->next = stack_a->next;
		stack_a->next = tmp;
		push->size_b = push->size_b - 1;
		push->size_a = push->size_a + 1;
	}
}

void	do_ra_rb(t_stack *stack_0, int size)
{
	t_stack	*tmp_1;
	t_stack	*tmp_2;

	if (size > 1)
	{
		tmp_1 = stack_0;
		tmp_2 = stack_0->next;
		while (tmp_1 && tmp_1->next)
			tmp_1 = tmp_1->next;
		stack_0->next = tmp_2->next;
		tmp_1->next = tmp_2;
		tmp_2->next = NULL;
	}
}

void	do_rra_rrb(t_stack *stack_0, int size)
{
	t_stack	*tmp_1;
	t_stack	*tmp_2;

	if (size > 1)
	{
		tmp_1 = stack_0;
		while (size-- - 1)
			tmp_1 = tmp_1->next;
		tmp_2 = tmp_1->next;
		tmp_1->next = NULL;
		tmp_1 = stack_0->next;
		stack_0->next = tmp_2;
		tmp_2->next = tmp_1;
	}
}
