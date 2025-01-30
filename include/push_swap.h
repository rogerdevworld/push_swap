# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* lib */
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdint.h>
#include <stdbool.h>

/* libft++ */
# include "../libft/libft.h"

/* stuct for project staks */
/* max int value from 2147483647 to -2147483648 */
/* unsigned int max 4294967295 the index can control from min int to max int */
typedef struct s_stack
{
    int value;
    size_t  index;
    int group;
    struct  s_stack *prev;
    struct  s_stack *next;
}   t_stack;

/* push_swap.c */
t_stack  *create_a_new_list(char **str_of_values, int argc);
void ft_read_all_stack(t_stack *stack);

// --- visual ---
void visual(t_stack *stack, int argc);

// --- creacion de las pilas ---
t_stack  *ft_create_value(int value);
t_stack  *ft_get_last_value(t_stack *list);
void    ft_add_back_the_list(t_stack **list, t_stack *new_value);
void    ft_linke_first_to_last(t_stack **stack);

// --- mas detalles ---
void assign_indices(t_stack *stack);

// --- mas detalles ---
int chuncks_opimi(int argc);
void assign_chunks(t_stack *stack, int num_chunks);

/* funcion para eliminar las listas ft_free() */
void    free_stack(t_stack **stack);

// --- algorithm ---

/* funcion para verificar si el stack esta ordenado */
int	sorted(t_stack *stack);
void	sort(t_stack **stack_a);

/* libft */
int	ft_atoi(const char *nptr);

/* libft v 2.0 */
long	ft_atoi_long(const char *nptr);
int	ft_sqrt(int nb);

// --- all movements --- 

// --- swap --- 
void    ft_sa_swap_a(t_stack **stack_a, int print);
void    ft_sb_swap_b(t_stack **stack_b, int print);
void    ft_ss_swap_ab(t_stack **stack_a, t_stack **stack_b);

// --- push --- 
void    ft_pa_push_a(t_stack **stack_a, t_stack **stack_b);
void    ft_pb_push_b(t_stack **stack_a, t_stack **stack_b);

// --- rotate --- 
void    ft_ra_rotate_a(t_stack **stack_a, int print);
void    ft_rb_rotate_b(t_stack **stack_b, int print);
void    ft_rr_rotate_ab(t_stack **stack_a, t_stack **stack_b);

// --- reverse --- 
void    ft_rra_reverse_a(t_stack **stack_a, int print);
void    ft_rrb_reverse_b(t_stack **stack_b, int print);
void    ft_rrr_reverse_ab(t_stack **stack_a, t_stack **stack_b);

// --- parse --- //
int    ft_thera_are_error(int argc, char **argv);
int    ft_2147483648(char **argv);
int    ft_error_params(int argc, char **argv);
void    ft_print_errors();
int    ft_no_repeat(char **argv);

// --- sort case --- //
void	sort_case(t_stack **stack_a, t_stack **stack_b, int argc);

// --- cases --- //
void	sort_three(t_stack **stack_a);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void sort_six(t_stack **stack_a, t_stack **stack_b);

// --- position --- //
void assign_position(t_stack *stack);

/* mandando del stack b al a */
t_stack *find_best_element_b(t_stack *stack);
void optimize_and_push_b(t_stack **stack_a, t_stack **stack_b);

// --- get elements --- //
int	max_value(t_stack *stack_a);
int	min_value(t_stack *stack_a);
t_stack *min_nodo(t_stack *stack);
t_stack *max_nodo(t_stack *stack);

int get_max_group(t_stack *stack_a);


// --- size stack --- //
size_t size_stack(t_stack *stack);

void optimize_and_push(t_stack **stack_a, t_stack **stack_b);
int calculate_cost(t_stack *stack, t_stack *target);
t_stack *find_best_element(t_stack *stack);
void pass_group_to_b(t_stack **stack_a, t_stack **stack_b, int argc);

void go_to_a(t_stack **stack_a, t_stack **stack_b, int argc);

/* checker */
void checker(t_stack *stack);


//MOVE 6 
void    sort_fixed(t_stack **stack_a, t_stack **stack_b);

# endif
