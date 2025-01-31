/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_six.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:45:48 by rmarrero          #+#    #+#             */
/*   Updated: 2025/01/31 13:47:46 by rmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

// --- case of 6 elements ---
void	sort_six(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min_node;

	while (size_stack(*stack_a) > 3)
	{
		if ((*stack_a)->index <= 3)
			ft_pb_push_b(stack_a, stack_b);
		else
		{
			min_node = min_nodo(*stack_a);
			if (calculate_cost(*stack_a, min_node) == 1)
				ft_ra_rotate_a(stack_a, 1);
			else
				ft_rra_reverse_a(stack_a, 1);
		}
	}
	if (!sorted(*stack_a))
		sort_three(stack_a);
	while (*stack_b)
		ft_pa_push_a(stack_a, stack_b);
	if (!sorted(*stack_a))
		ft_sa_swap_a(stack_a, 1);
}
