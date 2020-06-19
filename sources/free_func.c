/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 16:20:30 by tima              #+#    #+#             */
/*   Updated: 2020/06/11 10:16:46 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		error_free(t_ps *push)
{
	free_list(&push->stack_A);
	free_list(&push->stack_B);
	free_split(&push->args);
    write(2, "Error\n", 6);
	return (0);
}

int		correct_free(t_ps *push)
{
	free_list(&push->stack_A);
	free_list(&push->stack_B);
	free_split(&push->args);
	return (0);
}

void    free_split(char ***str)
{
	int i;

	i = 0;

	if (!(*str))
		return;
	while((*str)[i])
	{
		ft_memdel((void**)&(*str)[i]);
		i++;
	}
	ft_memdel((void**)&(*str));
}

void	free_list(t_stack **head)
{
	t_stack	*next;

	while(*head)
	{
		next = (*head)->next;
		ft_memdel((void**)&(*head));
		*head = next;
	}
}
