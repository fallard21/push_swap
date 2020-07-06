/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 12:55:20 by tima              #+#    #+#             */
/*   Updated: 2020/07/06 18:54:01 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		create_stacks(t_ps *push, int argc, char **argv)
{
	ft_memset(push, 0, sizeof(t_ps));
	if (!(push->stack_a = ft_memalloc(sizeof(t_stack))))
		return (1);
	if (!(push->stack_b = ft_memalloc(sizeof(t_stack))))
		return (1);
	if (save_arguments(push, argc, argv))
		return (1);
	push->size = get_size_stack(push->stack_a->next);
	push->size_a = push->size;
	if (!push->size)
		return (1);
	return (0);
}

int		save_arguments(t_ps *push, int argc, char **argv)
{
	t_stack	*tmp;
	int		i;
	int		j;

	tmp = push->stack_a;
	i = 1;
	while (i < argc)
	{
		j = 0;
		if (!(push->args = ft_strsplit(argv[i++], ' ')))
			return (1);
		if (validate_all_args(push->args))
			return (1);
		while (push->args[j])
		{
			if (!(tmp->next = new_element(ft_atoi(push->args[j++]))))
				return (1);
			tmp = tmp->next;
		}
		free_split(&push->args);
	}
	return (0);
}

int		get_size_stack(t_stack *head)
{
	int count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

t_stack	*new_element(int elem)
{
	t_stack	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_stack))))
		return (NULL);
	tmp->elem = elem;
	return (tmp);
}
