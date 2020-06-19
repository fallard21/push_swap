/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 10:12:58 by tima              #+#    #+#             */
/*   Updated: 2020/06/11 12:36:18 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	search_limits(t_ps *push)
{
	t_stack	*tmp;

	tmp = push->stack_A->next;
	push->min = tmp->elem;
	push->max = tmp->elem;
	while(tmp)
	{
		if (tmp->elem > push->max)
			push->max = tmp->elem;
		if (tmp->elem < push->min)
			push->min = tmp->elem;
		tmp = tmp->next;
	}
}

void	presorting(t_ps *push)
{
	int diff;

	search_limits(push);
	if (push->size < 8)
		return ;
	diff = (push->size >= 100 && push->size < 500) ? 50 : 100;
	if (push->size >= 100)
		presorting_diff(push, diff);
	push_all_to_b(push);
}

void	presorting_diff(t_ps *push, int diff)
{
	int	mid;
	int	i;
	int	elem;

	while (push->size_A > diff)
	{
		mid = mid_value(push, push->stack_A->next);
		i = 0;
		while (i < push->size_A)
		{
			elem = push->stack_A->next->elem;
			if (elem <= mid && elem != push->max && elem != push->min)
				do_operations("pb", push);
			else
				do_operations("ra", push);
			i++;
		}
	}
}

int		mid_value(t_ps *push, t_stack *stack_A)
{
	int mid;

	mid = 0;
	while(stack_A)
	{
		if (stack_A->elem != push->max && stack_A->elem != push->min)
			mid = mid + stack_A->elem;
		stack_A = stack_A->next;
	}
	mid = mid / (push->size_A - 2);
	return (mid);
}

void	push_all_to_b(t_ps *push)
{
	t_stack *tmp;
	
	tmp = push->stack_A;

	while(push->size_A != 2)
	{
		if (tmp->next->elem == push->max || tmp->next->elem == push->min)
			do_operations("ra", push);
		else
			do_operations("pb", push);
	}
	if (tmp->next->elem > tmp->next->next->elem)
		do_operations("sa", push);
}
