/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 06:08:42 by tima              #+#    #+#             */
/*   Updated: 2020/06/11 12:44:35 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	push;

	if (argc < 2)
		ft_printf("usage: ./push_swap [...] or ./push_swap [...] | ./checker [...]\n");
	else
	{
		if (create_stacks(&push, argc, argv) == 1)
			return (correct_free(&push));
		if (duplicate_found(push.stack_A->next) == 1)
			return (correct_free(&push));
		if (check_on_start(&push) == 1)
			return (correct_free(&push));
		presorting(&push);
		start_sorting(&push);
		normalize_stack(&push, push.stack_A->next);
			//ft_printf("Operations: %d\n", push.operations); // DEL
			//int n = is_sort(push.stack_A->next); // DEL
			//(n == 0) ? ft_printf("{2}SORTED{0}\n") : ft_printf("{1}NO SORTED{0}\n"); // DEL
		correct_free(&push);
	}
	return (0);
}
