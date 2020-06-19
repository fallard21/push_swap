/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 05:57:00 by tima              #+#    #+#             */
/*   Updated: 2020/06/19 22:44:34 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	struct s_stack	*next;
	int				elem;
	int				index;
	int				flag_cost_1;
	int				cost;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				rr;
	int				rrr;
	int				numA;
	int				numB;
}					t_stack;

typedef struct s_ps
{
	t_stack			*stack_A;
	t_stack			*stack_B;
	int				size_A;
	int				size_B;
	char			**args;
	int				size;
	int				min;
	int				max;
	int				operations;
}					t_ps;

/*
** >------------------------< CREATING STACKS >------------------------<
*/
int					create_stacks(t_ps *push, int argc, char **argv);
int					save_args(t_ps *push, int argc, char **argv);
int					save_arguments(t_ps *push, int argc, char **argv);
int					get_size_stack(t_stack *head);
t_stack				*new_element(int elem);

/*
** >---------------------------< VALDATING >---------------------------<
*/
int					check_on_start(t_ps *push);
int     			duplicate_found(t_stack *stack);
int					validate_args(char *str);
int					validate_all_args(char **str);
int					is_sort(t_stack *stack);

/*
** >-------------------------< CALCULATE COST >------------------------<
*/
void				analyzing_B(t_ps *push);
int					get_cost(t_ps *push, t_stack *A, t_stack *current);
int					get_low_cost(t_stack *tmp);
int					calculate_cost(t_ps *push, t_stack *tmp);
int					min(int a, int b);
/*
** >---------------------------< OPERATIONS >--------------------------<
*/
void				do_sa_sb(t_stack *stack_0, int size);
void				do_pa_pb(t_ps *push, t_stack *stack_1, t_stack *stack_2, int size);
void				do_pa(t_ps *push, t_stack *stack_A, t_stack *stack_B);
void				do_pb(t_ps *push, t_stack *stack_B, t_stack *stack_A);
void				do_ra_rb(t_stack *stack_0, int size);
void				do_rra_rrb(t_stack *stack_0, int size);
void				do_operations(const char *line, t_ps *push);

/*
** >--------------------------< PRE-SORTING >--------------------------<
*/
void				presorting(t_ps *push);
void				search_limits(t_ps *push);
void				push_all_to_b(t_ps *push);
void				presorting_diff(t_ps *push, int diff);
int					mid_value(t_ps *push, t_stack *stack_A);

/*
** >----------------------------< ALGORIHM >---------------------------<
*/
void				start_sorting(t_ps *push);
void				choosing_algorithm(t_ps *push, int num);
void				algo_3_elem(t_ps *push);
void				algo_low_stack(t_ps *push);
void				algorithm_zero(t_ps *push, t_stack *tmp);
void				algorithm_cost1(t_ps *push, t_stack *tmp);
void				algorithm_main(t_ps *push, t_stack *tmp, int rot, int rev_rot);
void				normalize_stack(t_ps *push, t_stack *stack_A);

/*
** >------------------------< LEAKS TREATMENT >------------------------<
*/
void				free_split(char ***str);
void				free_list(t_stack **head);
int					error_free(t_ps *push);
int					correct_free(t_ps *push);

/*
** >----------------------------< CHECKER >----------------------------<
*/
void				do_operations_1(const char *line, t_ps *push);
int					read_operations(t_ps *push);
int					validate_options(const char *str);

//void	print_args(t_stack *stack_A, t_stack *stack_B); // DEL

#endif