#include "../../include/push_swap.h"

// rra reverse rotate a: Shifts down all elements in stack a 
//one position, so that the last element becomes the first.
void    ft_rra_reverse_a(t_stack **stack_a, int print)
{
    if (!stack_a || !*stack_a || !((*stack_a)->next))
        return ;
    *stack_a = (*stack_a)->prev;
    if (print) 
        ft_printf("rra\n");
}

// rrb reverse rotate b: Shifts down all elements of stack b 
//one position, so that the last element becomes the first one.
void    ft_rrb_reverse_b(t_stack **stack_b, int print)
{
    if (!stack_b || !*stack_b || !((*stack_b)->next))
        return ;
    *stack_b = (*stack_b)->prev;
    if (print) 
        ft_printf("rrb\n");
}

// rrr rra and rrb at the same time.
void    ft_rrr_reverse_ab(t_stack **stack_a, t_stack **stack_b)
{
    ft_rra_reverse_a(stack_a, 0);
    ft_rrb_reverse_b(stack_b, 0);
    ft_printf("rrrrrarrb\n");
}
