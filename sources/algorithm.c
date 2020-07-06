/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 03:05:28 by tima              #+#    #+#             */
/*   Updated: 2020/07/06 18:45:39 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choosing_algorithm(t_ps *push, int num)
{
	t_stack *tmp_b;
	int		i;
	int		rot;
	int		rev_rot;

	i = 0;
	tmp_b = push->stack_b->next;
	while (tmp_b && i++ < num)
		tmp_b = tmp_b->next;
	if (!tmp_b->rr)
		return (algorithm_zero(push, tmp_b));
	rot = tmp_b->rr + tmp_b->ra + tmp_b->rb;
	rev_rot = tmp_b->rrr + tmp_b->rra + tmp_b->rrb;
	if (tmp_b->flag_cost_1)
		return (algorithm_cost1(push, tmp_b));
	algorithm_main(push, tmp_b, rot, rev_rot);
}

void	algorithm_cost1(t_ps *push, t_stack *tmp)
{
	int ra;
	int rra;
	int rb;
	int rrb;

	tmp->ra = tmp->rr + tmp->ra;
	tmp->rb = tmp->rr + tmp->rb;
	tmp->rra = tmp->rrr + tmp->rra;
	tmp->rrb = tmp->rrr + tmp->rrb;
	ra = (tmp->ra < tmp->rra) ? tmp->ra : 0;
	rra = (tmp->rra < tmp->ra) ? tmp->rra : 0;
	rb = (tmp->rb < tmp->rrb) ? tmp->rb : 0;
	rrb = (tmp->rrb < tmp->rb) ? tmp->rrb : 0;
	while (ra-- > 0)
		do_operations("ra", push);
	while (rb-- > 0)
		do_operations("rb", push);
	while (rra-- > 0)
		do_operations("rra", push);
	while (rrb-- > 0)
		do_operations("rrb", push);
	do_operations("pa", push);
}

void	algorithm_zero(t_ps *push, t_stack *tmp)
{
	const char	*str;
	int			n;

	n = 0;
	if (!tmp->ra)
	{
		str = (tmp->rb < tmp->rrb) ? "rb" : "rrb";
		n = (tmp->rb < tmp->rrb) ? tmp->rb : tmp->rrb;
	}
	else
	{
		str = (tmp->ra < tmp->rra) ? "ra" : "rra";
		n = (tmp->ra < tmp->rra) ? tmp->ra : tmp->rra;
	}
	while (n-- > 0)
		do_operations(str, push);
	do_operations("pa", push);
}

void	algorithm_main(t_ps *push, t_stack *tmp, int rot, int rev_rot)
{
	if (rot < rev_rot)
	{
		while (tmp->rr-- > 0)
			do_operations("rr", push);
		while (tmp->ra-- > 0)
			do_operations("ra", push);
		while (tmp->rb-- > 0)
			do_operations("rb", push);
	}
	else
	{
		while (tmp->rrr-- > 0)
			do_operations("rrr", push);
		while (tmp->rra-- > 0)
			do_operations("rra", push);
		while (tmp->rrb-- > 0)
			do_operations("rrb", push);
	}
	do_operations("pa", push);
}

void	start_sorting(t_ps *push)
{
	int num;

	num = 0;
	if (push->size > 2 && push->size < 8)
		algo_low_stack(push);
	while (push->size_b != 0)
	{
		analyzing_b(push);
		num = get_low_cost(push->stack_b->next);
		choosing_algorithm(push, num);
	}
}
