/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 20:05:10 by tima              #+#    #+#             */
/*   Updated: 2020/07/06 18:54:35 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_on_start(t_ps *push)
{
	if (push->size == 1)
		return (1);
	if (is_sort(push->stack_a->next) == 0)
		return (1);
	return (0);
}

int	duplicate_found(t_stack *stack)
{
	t_stack *tmp;

	if (!stack)
		return (1);
	tmp = stack;
	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->elem == tmp->elem)
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	validate_args(char *str)
{
	int i;
	int len;
	int n;

	i = 0;
	if (str[0] == '-')
		i++;
	len = ft_strlen(str + i);
	if (len > 10 || len == 0)
		return (1);
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (1);
		i++;
	}
	n = ft_atoi(str);
	if (str[0] != '-' && n < 0)
		return (1);
	if (str[0] == '-' && n > 0)
		return (1);
	return (0);
}

int	validate_all_args(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (validate_args(str[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	is_sort(t_stack *stack)
{
	t_stack	*left;
	t_stack	*right;

	if (!stack)
		return (1);
	left = stack;
	right = stack->next;
	while (right)
	{
		if (left->elem > right->elem)
			return (1);
		right = right->next;
		left = left->next;
	}
	return (0);
}
