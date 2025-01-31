/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fixed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:17:58 by rmarrero          #+#    #+#             */
/*   Updated: 2025/01/31 13:19:29 by rmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../include/push_swap.h"

void	sort_fixed(t_stack **stack_a, t_stack **stack_b)
{
	int	max;

	max = 4;
	if (sorted(*stack_b))
	{
		if (size_stack(*stack_b) == 2)
			ft_sb_swap_b(stack_b, 1);
		while (*stack_b)
			ft_pa_push_a(stack_a, stack_b);
	}
	else
	{
		while (max--)
			optimize_and_push_to_b(stack_a, stack_b);
	}
}
