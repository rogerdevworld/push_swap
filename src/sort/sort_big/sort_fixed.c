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

// --- I have problems with the constant was modified to 0.532 --- //
int	chuncks_opimi(int argc)
{
	int		chunks;
	double	z;

	chunks = 0;
	z = 0.532;
	if (argc <= 6)
		return (1);
	chunks = (int)(ft_sqrt(argc - 1) * z + 0.5);
	return (chunks);
}

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
