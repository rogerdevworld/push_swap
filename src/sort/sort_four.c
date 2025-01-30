#include "../../include/push_swap.h"

// --- caso de 4 elementos ---
void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int		count;

	count = 0;
	while (count < 4)
	{
		if ((*stack_a)->index == 1)
		{
			ft_pb_push_b(stack_a, stack_b);
			break ;
		}
		else if (min_nodo(*stack_a)->index > 2)
			ft_rra_reverse_a(stack_a, 1);
		else
			ft_ra_rotate_a(stack_a, 1);
		count++;
	}
	sort_three(stack_a);
	ft_pa_push_a(stack_a, stack_b);
}