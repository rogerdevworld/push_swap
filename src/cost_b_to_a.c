/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarrero  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:22:49 by rmarrero          #+#    #+#             */
/*   Updated: 2025/07/23 14:23:20 by rmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

static t_stack_node	*find_target_in_a(t_stack_node *a, int rank_b)
{
	t_stack_node	*curr;
	t_stack_node	*target;
	int				best_rank;

	best_rank = INT_MAX;
	target = NULL;
	curr = a;
	while (curr)
	{
		if (curr->rank > rank_b && curr->rank < best_rank)
		{
			best_rank = curr->rank;
			target = curr;
		}
		curr = curr->next;
	}
	if (!target)
		return (find_min(a));
	return (target);
}

static void	calc_best_route(t_stack_node *node_b, int len_a, int len_b)
{
	int	c[4];
	int	i;

	if (node_b->target_node->index > node_b->index)
		c[0] = node_b->target_node->index;
	else
		c[0] = node_b->index;
	if ((len_a - node_b->target_node->index) > (len_b - node_b->index))
		c[1] = len_a - node_b->target_node->index;
	else
		c[1] = len_b - node_b->index;
	c[2] = node_b->target_node->index + (len_b - node_b->index);
	c[3] = (len_a - node_b->target_node->index) + node_b->index;
	node_b->push_cost = c[0];
	node_b->move_type = 0;
	i = 1;
	while (i < 4)
	{
		if (c[i] < node_b->push_cost)
		{
			node_b->push_cost = c[i];
			node_b->move_type = i;
		}
		i++;
	}
}

t_stack_node	*get_cheapest_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*cheapest;
	int				len_a;
	int				len_b;

	current_index(a);
	current_index(b);
	len_a = stack_len(a);
	len_b = stack_len(b);
	cheapest = b;
	while (b)
	{
		b->target_node = find_target_in_a(a, b->rank);
		calc_best_route(b, len_a, len_b);
		if (b->push_cost < cheapest->push_cost)
			cheapest = b;
		b = b->next;
	}
	return (cheapest);
}
