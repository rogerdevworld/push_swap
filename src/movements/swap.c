/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:22:07 by rmarrero          #+#    #+#             */
/*   Updated: 2024/11/22 13:12:57 by rmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

// --- All moves ---

// --- sa swap a: Swaps the first two elements of stack a. Does nothing if there are one or fewer elements. ---
void	ft_sa_swap_a(t_stack **stack_a, int print)
{
	int	tmp_value;
	int	tmp_index;

	tmp_value = (*stack_a)->value;
	tmp_index = (*stack_a)->index;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->index = (*stack_a)->next->index;
	(*stack_a)->next->value = tmp_value;
	(*stack_a)->next->index = tmp_index;
	if (print)
		ft_printf("sa\n");
}

// --- sb swap b: Swaps the first two elements of stack b. Does nothing if there are one or fewer elements. ---
void	ft_sb_swap_b(t_stack **stack_b, int print)
{
	int	tmp_value;
	int	tmp_index;

	tmp_value = (*stack_b)->value;
	tmp_index = (*stack_b)->index;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->index = (*stack_b)->next->index;
	(*stack_b)->next->value = tmp_value;
	(*stack_b)->next->index = tmp_index;
	if (print)
		ft_printf("sb\n");
}

// --- ss swap a and swap b at the same time. ---
void    ft_ss_swap_ab(t_stack **stack_a, t_stack **stack_b)
{
    if (!*stack_b || !((*stack_b)->next) || !*stack_a || !((*stack_a)->next))
        return ;
    ft_sa_swap_a(stack_a, 0);
    ft_sb_swap_b(stack_b, 0);
    ft_printf("ss\n");
}

