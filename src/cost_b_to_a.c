/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_b_to_a.c                                      */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:45:00 by student           #+#    #+#             */
/*   Updated: 2026/11/16 18:45:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_node	*find_target_in_a(t_node *a, int rank_b)
{
	t_node	*curr;
	t_node	*target;
	int		best_rank;

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

static void	eval_routes(t_node *nb, int la, int lb, bool rrr_bias)
{
	int	c[4];
	int	i;

	c[0] = nb->index;
	if (nb->target->index > nb->index)
		c[0] = nb->target->index;
	c[1] = lb - nb->index;
	if ((la - nb->target->index) > (lb - nb->index))
		c[1] = la - nb->target->index;
	c[2] = nb->target->index + (lb - nb->index);
	c[3] = (la - nb->target->index) + nb->index;
	nb->cost = c[0];
	nb->route = 0;
	i = 0;
	while (++i < 4)
	{
		if (c[i] < nb->cost || (rrr_bias && i == 1 && c[i] == nb->cost))
		{
			nb->cost = c[i];
			nb->route = i;
		}
	}
}

t_node	*get_cheapest_b(t_sim *s)
{
	t_node	*ch;
	t_node	*curr;
	int		la;
	int		lb;

	current_index(s->a);
	current_index(s->b);
	la = stack_len(s->a);
	lb = stack_len(s->b);
	curr = s->b;
	ch = curr;
	while (curr)
	{
		curr->target = find_target_in_a(s->a, curr->rank);
		eval_routes(curr, la, lb, s->rrr_bias);
		if (curr->cost < ch->cost)
			ch = curr;
		curr = curr->next;
	}
	return (ch);
}
