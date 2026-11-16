/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:45:00 by student           #+#    #+#             */
/*   Updated: 2026/11/16 18:45:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate_nodes(t_node **stack)
{
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	op_ra(t_sim *s)
{
	rotate_nodes(&s->a);
	record_op(&s->ops, OP_RA);
}

void	op_rb(t_sim *s)
{
	rotate_nodes(&s->b);
	record_op(&s->ops, OP_RB);
}

void	op_rr(t_sim *s)
{
	rotate_nodes(&s->a);
	rotate_nodes(&s->b);
	record_op(&s->ops, OP_RR);
}
