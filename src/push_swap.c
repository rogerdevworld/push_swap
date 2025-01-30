#include "../include/push_swap.h"

t_stack  *create_a_new_list(char **str_of_values, int argc)
{
    t_stack *tmp;
    int i;

    i = 1;
    tmp = NULL;
    while (str_of_values[i])
    {
        ft_add_back_the_list(&tmp, ft_create_value(ft_atoi(str_of_values[i])));
        i++;
    }
    ft_linke_first_to_last(&tmp);
    return (tmp);
}

// --- elementos ordenados o no ---
int sorted(t_stack *stack)
{
    t_stack *tmp;
    t_stack *tmp_next;

    if (!stack || !stack->next)
        return (1);
    tmp = stack;
    tmp_next = stack->next;
    while (tmp->next != stack)
    {
        if (tmp->value > tmp_next->value)
            return (0);
        tmp = tmp_next;
        tmp_next = tmp_next->next;
    }
    return (1);
}

// --- filtrar por caso ---
void	sort_case(t_stack **stack_a, t_stack **stack_b, int argc)
{
	assign_indices(*stack_a);
	if (size_stack(*stack_a) == 2)
		ft_sa_swap_a(stack_a, 1);
	else if (size_stack(*stack_a) == 3)
		sort_three(stack_a);
	else if (size_stack(*stack_a) == 4)
		sort_four(stack_a, stack_b);
    else if (size_stack(*stack_a) == 5)
		sort_five(stack_a, stack_b);
    else if (size_stack(*stack_a) == 6)
		sort_six(stack_a, stack_b);
	else
    {
        assign_chunks(*stack_a, chuncks_opimi(argc));
        pass_group_to_b(stack_a, stack_b, argc);
		go_to_a(stack_a, stack_b, argc);
        if (size_stack(*stack_b) == 1)
            ft_pa_push_a(stack_a, stack_b);
        else
            sort_fixed(stack_a, stack_b);
    }
}

// --- main --- //
int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if (!ft_thera_are_error(argc, argv))
    {
        free_stack(&stack_a);
        free_stack(&stack_a);
        ft_print_errors();
        return 0;
    }
    stack_a = create_a_new_list(argv, argc - 1);
    if (!sorted(stack_a))
        sort_case(&stack_a, &stack_b, argc);
    //ft_printf("%i\n", chuncks_opimi(argc));
    return (0);
}
/* cmd > 

//letras
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' '); ./push_swap $ARG

//cheker
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' '); ./push_swap $ARG | ./checkr $ARG

//visualizador
ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' '); python3 pyviz.py $ARG

 */