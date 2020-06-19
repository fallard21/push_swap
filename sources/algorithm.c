/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 03:05:28 by tima              #+#    #+#             */
/*   Updated: 2020/06/11 12:32:14 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choosing_algorithm(t_ps *push, int num)
{
	t_stack *tmp_B;
	int i;	
	int rot;
	int rev_rot;

	i = 0;
	tmp_B = push->stack_B->next;
	while(tmp_B && i++ < num)
		tmp_B = tmp_B->next;
	/*
	ft_printf("CHECKING: cost: %d, element: %d\n", tmp_B->cost, tmp_B->elem);
	ft_printf("{3} ra: %d |  rb: %d{0}\n", tmp_B->ra, tmp_B->rb);
	ft_printf("{3}rra: %d | rrb: %d{0}\n", tmp_B->rra, tmp_B->rrb);
	ft_printf("{3}rr: %d | rrr: %d{0}\n", tmp_B->rr, tmp_B->rrr);
	*/
	if (!tmp_B->rr)
		return (algorithm_zero(push, tmp_B));
	rot = tmp_B->rr + tmp_B->ra + tmp_B->rb;
	rev_rot = tmp_B->rrr + tmp_B->rra + tmp_B->rrb;
	if (tmp_B->flag_cost_1)
		return(algorithm_cost1(push, tmp_B));
	algorithm_main(push, tmp_B, rot, rev_rot);
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
	
	while(ra-- > 0)
		do_operations("ra", push);
	while(rb-- > 0)
		do_operations("rb", push);
	while(rra-- > 0)
		do_operations("rra", push);
	while(rrb-- > 0)
		do_operations("rrb", push);
	do_operations("pa", push);
}

void 	algorithm_zero(t_ps *push, t_stack *tmp)
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
	while(n-- > 0)
		do_operations(str, push);
	do_operations("pa", push);
}

void	algorithm_main(t_ps *push, t_stack *tmp, int rot, int rev_rot)
{
	if (rot < rev_rot)
	{
		while(tmp->rr-- > 0)
			do_operations("rr", push);
		while(tmp->ra-- > 0)
			do_operations("ra", push);
		while(tmp->rb-- > 0)
			do_operations("rb", push);
	}
	else
	{
		while(tmp->rrr-- > 0)
			do_operations("rrr", push);
		while(tmp->rra-- > 0)
			do_operations("rra", push);
		while(tmp->rrb-- > 0)
			do_operations("rrb", push);
	}
	do_operations("pa", push);
}

void 	start_sorting(t_ps *push)
{
	int num;

	num = 0;
	if (push->size > 2 && push->size < 8)
		algo_low_stack(push);
	while (push->size_B != 0)
	{
		analyzing_B(push);
		num = get_low_cost(push->stack_B->next);
		choosing_algorithm(push, num);
		//print_args(push->stack_A, push->stack_B);
		//getchar();
	}
}
