/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:46:33 by rmarrero          #+#    #+#             */
/*   Updated: 2025/01/31 13:17:29 by rmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../include/push_swap.h"

// --- tengo problemas con la constante fue modificada a 0.532 --- //
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

// --- apply chunck --- //
void	assign_chunks(t_stack *stack, int num_chunks)
{
	size_t	max_index;
	size_t	range;
	t_stack	*tmp;
	t_stack	*start;

	if (!stack || num_chunks <= 0)
		return ;
	max_index = 0;
	tmp = stack;
	start = stack;
	while (tmp->next != start)
	{
		if (tmp->index > max_index)
			max_index = tmp->index;
		tmp = tmp->next;
	}
	if (tmp->index > max_index)
		max_index = tmp->index;
	range = (max_index) / num_chunks + ((max_index) % num_chunks != 0);
	tmp = stack;
	while (tmp->next != start)
	{
		tmp->group = (max_index - tmp->index) / range;
		tmp = tmp->next;
	}
	tmp->group = (max_index - tmp->index) / range;
}

// Determinar si usar ra o rra para mover el elemento al tope
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

// Función para mover el elemento más rentable al tope y pasarlo al stack_b
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
