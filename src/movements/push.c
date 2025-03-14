/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:41:04 by rmarrero          #+#    #+#             */
/*   Updated: 2025/01/31 11:50:16 by rmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	update_src(t_stack **src)
{
	t_stack	*tmp;

	tmp = (*src)->next;
	if (*src == tmp)
		tmp = NULL;
	else
	{
		(*src)->prev->next = (*src)->next;
		(*src)->next->prev = (*src)->prev;
	}
	*src = tmp;
}

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = *src;
	update_src(src);
	if (*dst == NULL)
	{
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	else
	{
		tmp->next = *dst;
		tmp->prev = (*dst)->prev;
		(*dst)->prev->next = tmp;
		(*dst)->prev = tmp;
	}
	*dst = tmp;
}

// --- pa push a: Takes the first element from stack b and puts it  --- //
// --- first in stack a. It does nothing if b is empty. --- //
void	ft_pa_push_a(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

// --- pb push b: Takes the first element from stack a and puts it  --- //
// --- first in stack b. Does nothing if a is empty. --- //
void	ft_pb_push_b(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
