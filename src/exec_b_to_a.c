/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_b_to_a.c                                      */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:45:00 by student           #+#    #+#             */
/*   Updated: 2026/11/16 18:45:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	exec_both_up(t_sim *s, t_node *ch)
{
	while (s->a != ch->target && s->b != ch)
		op_rr(s);
	while (s->a != ch->target)
		op_ra(s);
	while (s->b != ch)
		op_rb(s);
}

static void	exec_both_down(t_sim *s, t_node *ch)
{
	while (s->a != ch->target && s->b != ch)
		op_rrr(s);
	while (s->a != ch->target)
		op_rra(s);
	while (s->b != ch)
		op_rrb(s);
}

static void	exec_mixed(t_sim *s, t_node *ch)
{
	if (ch->route == 2)
	{
		while (s->a != ch->target)
			op_ra(s);
		while (s->b != ch)
			op_rrb(s);
	}
	else
	{
		while (s->a != ch->target)
			op_rra(s);
		while (s->b != ch)
			op_rb(s);
	}
}

void	exec_cheapest_b(t_sim *s, t_node *ch)
{
	if (ch->route == 0)
		exec_both_up(s, ch);
	else if (ch->route == 1)
		exec_both_down(s, ch);
	else
		exec_mixed(s, ch);
	op_pa(s);
}
