/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 23:19:33 by rmarrero          #+#    #+#             */
/*   Updated: 2025/01/11 23:19:38 by rmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"


// --- caso de 3 elementos ---
void	sort_three(t_stack **stack)
{
	if (min_value(*stack) == (*stack)->value)
	{
		ft_rra_reverse_a(stack, 1);
		if (!sorted(*stack))
			ft_sa_swap_a(stack, 1);
	}
	else if (max_value(*stack) == (*stack)->value)
	{
		ft_ra_rotate_a(stack, 1);
		if (!sorted(*stack))
			ft_sa_swap_a(stack, 1);
	}
	else
		ft_sa_swap_a(stack, 1);
}