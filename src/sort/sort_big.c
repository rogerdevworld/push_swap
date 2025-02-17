/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:22:07 by rmarrero          #+#    #+#             */
/*   Updated: 2025/02/01 13:44:52 by rmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

// --- función para encontrar el elemento más rentable para mover --- //
t_stack	*find_best_element(t_stack *stack)
{
	t_stack	*best;
	t_stack	*tmp;

	if (!stack)
		return (NULL);
	best = stack;
	tmp = stack;
	while (tmp->next != stack)
	{
		if (tmp->group > best->group || (tmp->group == best->group))
			best = tmp;
		tmp = tmp->next;
	}
	if (tmp->group > best->group || (tmp->group == best->group))
		best = tmp;
	return (best);
}

// --- función para pasar todos los grupos menos el 0 --- //
// --- pasa el nodo en orden ascendente de grupo --- //
void	pass_group_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int		max_group;
	int		max;
	t_stack	*tmp;
	t_stack	*start;

	if (!stack_a || !*stack_a)
		return ;
	max_group = get_max_group(*stack_a);
	max = 0;
	tmp = *stack_a;
	start = *stack_a;
	while (1)
	{
		if (tmp->group != 0)
			optimize_and_push(stack_a, stack_b);
		tmp = tmp->next;
		max++;
		if (max > 3000)
			break ;
	}
}

// --- función para encontrar el elemento más rentable para mover al a --- //
t_stack	*find_best_element_to_a(t_stack *stack)
{
	t_stack	*best;
	t_stack	*tmp;

	if (!stack)
		return (NULL);
	best = stack;
	tmp = stack;
	while (tmp->next != stack)
	{
		if (tmp->index > best->index)
			best = tmp;
		tmp = tmp->next;
	}
	if (tmp->index > best->index)
		best = tmp;
	return (best);
}

// --- Función para mover el elemento más rentable --- //
// --- al tope y pasarlo al stack_b --- //
void	optimize_and_push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*best;
	int		direction;

	if (!stack_b || !*stack_b)
		return ;
	best = find_best_element_to_a(*stack_b);
	if (!best)
		return ;
	direction = calculate_cost(*stack_b, best);
	while (*stack_b != best)
	{
		if (direction == 1)
			ft_rb_rotate_b(stack_b, 1);
		else
			ft_rrb_reverse_b(stack_b, 1);
	}
	ft_pa_push_a(stack_a, stack_b);
}

// --- pasa el nodo en orden ascendente de grupo --- //
void	go_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*start;

	if (!stack_b || !*stack_b)
		return ;
	tmp = *stack_b;
	start = tmp;
	while (1)
	{
		if (tmp->group != 0)
			optimize_and_push_to_b(stack_a, stack_b);
		tmp = tmp->next;
		if (tmp == start)
			break ;
	}
}
