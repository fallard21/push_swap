/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 06:08:42 by tima              #+#    #+#             */
/*   Updated: 2020/07/06 18:52:42 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	push;

	if (argc < 2)
		ft_printf("usage: ./push_swap [...] | ./checker [...]\n");
	else
	{
		if (create_stacks(&push, argc, argv) == 1)
			return (correct_free(&push));
		if (duplicate_found(push.stack_a->next) == 1)
			return (correct_free(&push));
		if (check_on_start(&push) == 1)
			return (correct_free(&push));
		presorting(&push);
		start_sorting(&push);
		normalize_stack(&push, push.stack_a->next);
		correct_free(&push);
	}
	return (0);
}
