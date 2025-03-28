/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:26:29 by rmarrero          #+#    #+#             */
/*   Updated: 2025/01/31 17:50:38 by rmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

// --- initialize the node --- //
t_stack	*ft_create_value(int value)
{
	t_stack	*new_value;

	new_value = (t_stack *)malloc(sizeof(t_stack));
	if (!new_value)
		return (NULL);
	new_value->value = value;
	new_value->index = 0;
	new_value->group = 1;
	new_value->next = NULL;
	new_value->prev = NULL;
	return (new_value);
}

// --- get last node--- //
t_stack	*ft_get_last_value(t_stack *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

// --- add to the end of the stack --- //
void	ft_add_back_the_list(t_stack **list, t_stack *new_value)
{
	t_stack	*last_value;

	if (!list || !new_value)
		return ;
	if (!*list)
		*list = new_value;
	else
	{
		last_value = ft_get_last_value(*list);
		last_value->next = new_value;
		new_value->prev = last_value;
	}
}

// --- circular list link between the last and the first one --- //
void	ft_linke_first_to_last(t_stack **stack)
{
	t_stack	*first_value;
	t_stack	*last_value;

	first_value = *stack;
	last_value = ft_get_last_value(*stack);
	if (!stack || !*stack || !(*stack)->next)
		return ;
	first_value->prev = last_value;
	last_value->next = first_value;
}

// --- function to remove the lists ft_free() --- //
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		(*stack)->value = 0;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
