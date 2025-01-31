/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:02:21 by rmarrero          #+#    #+#             */
/*   Updated: 2025/01/31 19:19:53 by rmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

// --- get_max_group --- //
int	get_max_group(t_stack *stack)
{
	int		max_group;
	t_stack	*tmp;

	tmp = stack;
	max_group = 0;
	while (1)
	{
		if (tmp->group > max_group)
			max_group = tmp->group;
		tmp = tmp->next;
		if (tmp != stack)
			break ;
	}
	return (max_group);
}

// ---- This function finds and returns --- //
// --- the largest number on the given stack. --- //
int	max_value(t_stack *stack_a)
{
	int		i;
	t_stack	*tmp;

	tmp = stack_a;
	i = stack_a->value;
	while (stack_a->next != tmp)
	{
		if (stack_a->value > i)
			i = stack_a->value;
		stack_a = stack_a->next;
	}
	if (stack_a->value > i)
		i = stack_a->value;
	return (i);
}

// --- This function finds and returns the --- //
// ---  smallest number in the given stack. --- //
int	min_value(t_stack *stack_a)
{
	int		i;
	t_stack	*tmp;

	i = stack_a->value;
	tmp = stack_a;
	while (stack_a->next != tmp)
	{
		if (stack_a->value < i)
			i = stack_a->value;
		stack_a = stack_a->next;
	}
	return (i);
}

// --- search position in the list --- //
t_stack	*min_nodo(t_stack *stack)
{
	t_stack	*min_node;
	t_stack	*tmp;

	min_node = stack;
	tmp = stack;
	if (!stack)
		return (NULL);
	stack = stack->next;
	while (stack != tmp)
	{
		if (stack->value < min_node->value)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

// --- max value node --- //
t_stack	*max_nodo(t_stack *stack)
{
	t_stack	*max_node;
	t_stack	*tmp;

	tmp = stack;
	max_node = stack;
	if (!stack)
		return (NULL);
	stack = stack->next;
	while (stack != tmp)
	{
		if (stack->value > max_node->value)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}
