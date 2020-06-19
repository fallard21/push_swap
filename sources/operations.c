/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 10:11:20 by tima              #+#    #+#             */
/*   Updated: 2020/06/11 12:34:23 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	print_args(t_stack *stack_A, t_stack *stack_B)
{
	int i = 0;
	ft_putchar('\n');
	stack_A = stack_A->next;
	stack_B = stack_B->next;
	ft_printf("/--------------------------\\\n");
	while(stack_A || stack_B)
	{
		if (stack_A)
			ft_printf("        %-6d", stack_A->elem);
		else
			ft_printf("              ");
		
		ft_printf("|");
		if (stack_B)
			ft_printf("%6d", stack_B->elem);
		if (stack_A)
			stack_A = stack_A->next;
		if (stack_B)
			stack_B = stack_B->next;
		ft_printf("\n");
	}
	ft_printf("       {3}---------------{0}\n");
	ft_printf("          {2}A{0}      {2}B{0}\n");
	ft_printf("\\--------------------------/\n");
}
*/

void    do_sa_sb(t_stack *stack_0, int size)
{
    t_stack *stack_1;
    t_stack *tmp;

    if (size < 2)
        return ;
    stack_1 = stack_0->next;
    tmp = stack_1->next;
    stack_0->next = stack_1->next;
    stack_1->next = tmp->next;
    tmp->next = stack_1;
}

void    do_pb(t_ps *push, t_stack *stack_B, t_stack *stack_A)
{
    t_stack    *tmp;

    if (!push->size_A)
        return ;
    tmp = stack_A->next;
    stack_A->next = tmp->next;
    tmp->next = stack_B->next;
    stack_B->next = tmp;
    push->size_A = push->size_A - 1;
    push->size_B = push->size_B + 1;
}

void    do_pa(t_ps *push, t_stack *stack_A, t_stack *stack_B)
{
    t_stack    *tmp;

    if (!push->size_B)
        return ;
    tmp = stack_B->next;
    stack_B->next = tmp->next;
    tmp->next = stack_A->next;
    stack_A->next = tmp;
    push->size_B = push->size_B - 1;
    push->size_A = push->size_A + 1;
}

void    do_ra_rb(t_stack *stack_0, int size)
{
    t_stack *tmp_1;
    t_stack *tmp_2;

    if (size < 2)
        return ;
    tmp_1 = stack_0;
    tmp_2 = stack_0->next;
    while(tmp_1 && tmp_1->next)
        tmp_1 = tmp_1->next;
    stack_0->next = tmp_2->next;
    tmp_1->next = tmp_2;
    tmp_2->next = NULL;
}

void    do_rra_rrb(t_stack *stack_0, int size)
{
    t_stack *tmp_1;
    t_stack *tmp_2;
    
    if (size < 2)
        return ;
    tmp_1 = stack_0;
    while(size-- - 1)
        tmp_1 = tmp_1->next;
    tmp_2 = tmp_1->next;
    tmp_1->next = NULL;
    tmp_1 = stack_0->next;
    stack_0->next = tmp_2;
    tmp_2->next = tmp_1;
}
