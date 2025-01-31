/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:01:04 by rmarrero          #+#    #+#             */
/*   Updated: 2025/01/31 19:12:45 by rmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* lib */
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdint.h>
# include <stdbool.h>

/* libft++ */
# include "../libft/libft.h"

// --- 0. check if the data is valid --- //
int		ft_thera_are_error(int argc, char **argv);
int		ft_2147483648(char **argv);
int		ft_error_params(int argc, char **argv);
void	ft_print_errors(void);
int		ft_no_repeat(char **argv);

// --- algorithm --- //
// --- 1. define the struct --- //
typedef struct s_stack
{
	int					value;
	size_t				index;
	int					group;
	struct s_stack		*prev;
	struct s_stack		*next;
}	t_stack;

// --- 2. create stack element --- //
t_stack	*ft_create_value(int value);

// --- 3. link the elements of the stack --- //
void	ft_add_back_the_list(t_stack **list, t_stack *new_value);

// --- 4. call the main function to create stack --- //
t_stack	*create_a_new_list(char **str_of_values, int argc);

// --- 5. function to link the circular list --- //
void	ft_linke_first_to_last(t_stack **stack);

// --- 6. apply details to the element --- //
void	assign_indices(t_stack *stack);
int		chuncks_opimi(int argc);
void	assign_chunks(t_stack *stack, int num_chunks);

// --- 7. check if they are sorted --- //
int		sorted(t_stack *stack);

// --- 8. sort if not --- //
void	sort(t_stack **stack_a);

// --- 9. find case and send to its function --- //
void	sort_case(t_stack **stack_a, t_stack **stack_b, int argc);

// --- 9.1 Functions for specific cases --- //
void	sort_three(t_stack **stack_a);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_six(t_stack **stack_a, t_stack **stack_b);

// --- 9.2 Functions for large cases --- //
// --- 9.2.1 Finding the optimal element --- //
t_stack	*find_best_element(t_stack *stack);

// --- 9.2.2 cost of ra or rra --- //
int		calculate_cost(t_stack *stack, t_stack *target);

// --- 9.2.3 search for optimal push --- //
void	optimize_and_push(t_stack **stack_a, t_stack **stack_b);

// --- 9.2.4 used the above move to b all --- //
void	pass_group_to_b(t_stack **stack_a, t_stack **stack_b, int argc);

// --- 9.2.5 find the best largest element in b --- //
t_stack	*find_best_element_b(t_stack *stack);

// --- 9.2.6 optimal push to send from b to a --- //
void	optimize_and_push_to_b(t_stack **stack_a, t_stack **stack_b);

// --- 9.2.7 optimal push to send from b to j to --- //
void	go_to_a(t_stack **stack_a, t_stack **stack_b, int argc);

// --- 9.2.8 if necessary sort the end --- //
void	sort_fixed(t_stack **stack_a, t_stack **stack_b);

// --- useful functions --- //
// --- get last value --- //
t_stack	*ft_get_last_value(t_stack *list);

// --- function to delete --- //
void	free_stack(t_stack **stack);

// --- function to apply position --- //
void	assign_position(t_stack *stack);

// --- get elements --- //
int		max_value(t_stack *stack_a);
int		min_value(t_stack *stack_a);
t_stack	*min_nodo(t_stack *stack);
t_stack	*max_nodo(t_stack *stack);
int		get_max_group(t_stack *stack_a);

// --- size stack --- //
size_t	size_stack(t_stack *stack);

// --- (optional) --- //
// --- stack viewer (optional) --- //
void	visual(t_stack *stack, int argc);

// --- print elements (optional) --- //
void	ft_read_all_stack(t_stack *stack);

// --- checker (optional) --- //
void	checker(t_stack *stack);

// --- all movements --- //

// --- swap --- //
void	ft_sa_swap_a(t_stack **stack_a, int print);
void	ft_sb_swap_b(t_stack **stack_b, int print);
void	ft_ss_swap_ab(t_stack **stack_a, t_stack **stack_b);

// --- push --- //
void	ft_pa_push_a(t_stack **stack_a, t_stack **stack_b);
void	ft_pb_push_b(t_stack **stack_a, t_stack **stack_b);

// --- rotate --- //
void	ft_ra_rotate_a(t_stack **stack_a, int print);
void	ft_rb_rotate_b(t_stack **stack_b, int print);
void	ft_rr_rotate_ab(t_stack **stack_a, t_stack **stack_b);

// --- reverse --- //
void	ft_rra_reverse_a(t_stack **stack_a, int print);
void	ft_rrb_reverse_b(t_stack **stack_b, int print);
void	ft_rrr_reverse_ab(t_stack **stack_a, t_stack **stack_b);
#endif
