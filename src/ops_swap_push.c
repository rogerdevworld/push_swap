/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_push.c                                    */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:45:00 by student           #+#    #+#             */
/*   Updated: 2026/11/16 18:45:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	swap_nodes(t_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

static void	push_node(t_node **dst, t_node **src)
{
	t_node	*node;

	if (!*src)
		return ;
	node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node->prev = NULL;
	if (!*dst)
	{
		*dst = node;
		node->next = NULL;
	}
	else
	{
		node->next = *dst;
		node->next->prev = node;
		*dst = node;
	}
}

void	op_sa(t_sim *s)
{
	swap_nodes(&s->a);
	record_op(&s->ops, OP_SA);
}

void	op_pa(t_sim *s)
{
	push_node(&s->a, &s->b);
	record_op(&s->ops, OP_PA);
}

void	op_pb(t_sim *s)
{
	push_node(&s->b, &s->a);
	record_op(&s->ops, OP_PB);
}
