/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:44:51 by rmarrero          #+#    #+#             */
/*   Updated: 2025/01/24 16:58:32 by rmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

// --- ra rotate a: Moves up all elements in the stack --- //
// --- one position, so that the first element becomes the last. -- //
void	ft_ra_rotate_a(t_stack **stack_a, int print)
{
	if (!stack_a || !*stack_a || !((*stack_a)->next))
		return ;
	*stack_a = (*stack_a)->next;
	if (print)
		ft_printf("ra\n");
}

// --- rb rotate b: Moves up all elements of stack b one position, --- //
// --- so that the first element becomes the last one. 
// --- rr ra and rb at the same time. --- //
void	ft_rb_rotate_b(t_stack **stack_b, int print)
{
	if (!stack_b || !*stack_b || !((*stack_b)->next))
		return ;
	*stack_b = (*stack_b)->next;
	if (print)
		ft_printf("rb\n");
}

// --- rr ra y rb al mismo tiempo. --- //
void	ft_rr_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_ra_rotate_a(stack_a, 0);
	ft_rb_rotate_b(stack_b, 0);
	ft_printf("rr\n");
}
