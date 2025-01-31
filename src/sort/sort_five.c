/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:43:13 by rmarrero          #+#    #+#             */
/*   Updated: 2025/01/31 13:44:49 by rmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

// --- caso de 5 elementos ---
void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	while (size_stack(*stack_a) > 3)
	{
		if ((*stack_a)->index <= 2)
			ft_pb_push_b(stack_a, stack_b);
		else
		{
			if (min_nodo(*stack_a)->index <= size_stack(*stack_a) / 2)
				ft_ra_rotate_a(stack_a, 1);
			else
				ft_rra_reverse_a(stack_a, 1);
		}
	}
	if (!sorted(*stack_a))
		sort_three(stack_a);
	ft_pa_push_a(stack_a, stack_b);
	ft_pa_push_a(stack_a, stack_b);
	if (!sorted(*stack_a))
		ft_sa_swap_a(stack_a, 1);
}
