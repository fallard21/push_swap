/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 10:09:57 by tima              #+#    #+#             */
/*   Updated: 2020/07/06 18:47:32 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	analyzing_b(t_ps *push)
{
	t_stack	*tmp;
	int		num;

	num = 0;
	tmp = push->stack_b->next;
	while (tmp)
	{
		tmp->cost = 0;
		tmp->flag_cost_1 = 0;
		tmp->num_a = 0;
		tmp->num_b = num;
		tmp->cost = get_cost(push, push->stack_a->next, tmp);
		tmp = tmp->next;
		num++;
	}
}

int		get_cost(t_ps *push, t_stack *a, t_stack *current)
{
	t_stack	*right;
	int		flag;

	flag = 0;
	right = a->next;
	while (right)
	{
		if (a->elem < current->elem && right->elem > current->elem)
		{
			flag = 1;
			break ;
		}
		a = a->next;
		right = right->next;
		current->num_a = current->num_a + 1;
	}
	current->num_a = (flag == 1) ? current->num_a + 1 : 0;
	current->cost = calculate_cost(push, current);
	return (current->cost);
}

int		calculate_cost(t_ps *push, t_stack *tmp)
{
	int cost;
	int cost_1;

	tmp->rb = tmp->num_b;
	tmp->rrb = push->size_b - tmp->num_b;
	tmp->ra = tmp->num_a;
	tmp->rra = push->size_a - tmp->num_a;
	tmp->rr = min(tmp->ra, tmp->rb);
	tmp->rrr = min(tmp->rra, tmp->rrb);
	cost_1 = min(tmp->ra, tmp->rra) + min(tmp->rb, tmp->rrb);
	if (!tmp->rr)
		return (min(tmp->ra, tmp->rra) + min(tmp->rb, tmp->rrb));
	tmp->ra = tmp->ra - tmp->rr;
	tmp->rb = tmp->rb - tmp->rr;
	tmp->rra = tmp->rra - tmp->rrr;
	tmp->rrb = tmp->rrb - tmp->rrr;
	cost = min(tmp->rr + tmp->ra + tmp->rb, tmp->rrr + tmp->rra + tmp->rrb);
	tmp->flag_cost_1 = (cost_1 < cost) ? 1 : 0;
	return (cost_1 < cost ? cost_1 : cost);
}

int		get_low_cost(t_stack *tmp)
{
	int	num;
	int	max_elem;
	int	i;
	int	min_cost;

	i = 0;
	num = 0;
	max_elem = tmp->elem;
	min_cost = tmp->cost;
	while (tmp)
	{
		if (tmp->cost < min_cost || (tmp->cost == min_cost
			&& tmp->elem > max_elem))
		{
			min_cost = tmp->cost;
			num = i;
			max_elem = tmp->elem;
		}
		tmp = tmp->next;
		i++;
	}
	return (num);
}

int		min(int a, int b)
{
	return (a > b ? b : a);
}
