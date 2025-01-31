/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:22:07 by rmarrero          #+#    #+#             */
/*   Updated: 2025/01/31 13:26:10 by rmarrero         ###   ########.fr       */
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
void	pass_group_to_b(t_stack **stack_a, t_stack **stack_b, int argc)
{
    if (!stack_a || !*stack_a)
        return;

    int max_group = get_max_group(*stack_a);
    int max = 0;
    t_stack *tmp = *stack_a;
    t_stack *start = *stack_a;
    while (1) {
        if (tmp->group != 0)
            optimize_and_push(stack_a, stack_b);
        tmp = tmp->next;
        max++;
        if (max > 3000)
            break ;
    }
}

// --- vale ahora vamos por una version de la segunda parte suponiendo que ya tenemos  --- //
// --- todos los chuncks en orden --- //

// --- Función para encontrar el elemento más rentable para mover al a --- //
t_stack *find_best_element_to_a(t_stack *stack)
{
    if (!stack)
        return NULL;

    t_stack *best = stack;
    t_stack *tmp = stack;

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

// --- Función para mover el elemento más rentable al tope y pasarlo al stack_b --- //
void optimize_and_push_to_b(t_stack **stack_a, t_stack **stack_b)
{
    if (!stack_b || !*stack_b)
        return;
    t_stack *best = find_best_element_to_a(*stack_b);
    if (!best)
        return;
    int direction = calculate_cost(*stack_b, best);
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
void go_to_a(t_stack **stack_a, t_stack **stack_b, int argc)
{
    if (!stack_b || !*stack_b)
        return;
    t_stack *tmp = *stack_b;
    t_stack *start = *stack_b;
    do {
        if (tmp->group != 0)
            optimize_and_push_to_b(stack_a, stack_b);
        tmp = tmp->next;
    } while (tmp != start);
}
