/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:46:33 by rmarrero          #+#    #+#             */
/*   Updated: 2025/02/01 13:46:16 by rmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../include/push_swap.h"

// --- apply index --- //
void	assign_indices(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*comparator;
	int		index;

	if (!stack)
		return ;
	tmp = stack;
	while (1)
	{
		index = 1;
		comparator = stack;
		while (1)
		{
			if (comparator->value < tmp->value)
				index++;
			comparator = comparator->next;
			if (comparator == stack)
				break ;
		}
		tmp->index = index;
		tmp = tmp->next;
		if (tmp == stack)
			break ;
	}
}

size_t	get_max_index(t_stack *stack)
{
	t_stack	*tmp;
	size_t	max_index;

	max_index = 0;
	tmp = stack;
	while (tmp->next != stack)
	{
		if (tmp->index > max_index)
			max_index = tmp->index;
		tmp = tmp->next;
	}
	if (tmp->index > max_index)
		max_index = tmp->index;
	return (max_index);
}

// --- apply chunck --- //
void	assign_chunks(t_stack *stack, int num_chunks)
{
	t_stack	*tmp;
	size_t	max_index;
	size_t	range;

	if (!stack || num_chunks <= 0)
		return ;
	max_index = get_max_index(stack);
	range = max_index / num_chunks + (max_index % num_chunks != 0);
	tmp = stack;
	while (tmp->next != stack)
	{
		tmp->group = (max_index - tmp->index) / range;
		tmp = tmp->next;
	}
	tmp->group = (max_index - tmp->index) / range;
}

// --- Determine whether to use ra or rra to move the element to the top --- //
int	calculate_cost(t_stack *stack, t_stack *target)
{
	t_stack	*tmp;
	size_t	size;
	size_t	forward_steps;
	size_t	backward_steps;

	backward_steps = 0;
	forward_steps = 0;
	size = size_stack(stack);
	tmp = stack;
	while (tmp != target)
	{
		forward_steps++;
		tmp = tmp->next;
	}
	backward_steps = size - forward_steps;
	if (forward_steps <= backward_steps)
		return (1);
	else
		return (-1);
}

// --- Determine whether to use ra or rra to move the element to the top --- //
void	optimize_and_push(t_stack **stack_a, t_stack **stack_b)
{
	int		direction;
	t_stack	*best;

	if (!stack_a || !*stack_a)
		return ;
	best = find_best_element(*stack_a);
	if (!best)
		return ;
	direction = calculate_cost(*stack_a, best);
	while (*stack_a != best)
	{
		if (direction == 1)
			ft_ra_rotate_a(stack_a, 1);
		else
			ft_rra_reverse_a(stack_a, 1);
	}
	ft_pb_push_b(stack_a, stack_b);
}
