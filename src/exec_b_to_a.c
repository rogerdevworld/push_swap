#include "../inc/push_swap.h"

static void	exec_both_up(t_stack_node **a, t_stack_node **b, t_stack_node *ch)
{
	while (*a != ch->target_node && *b != ch)
		rr(a, b, false);
	while (*a != ch->target_node)
		ra(a, false);
	while (*b != ch)
		rb(b, false);
}

static void	exec_both_down(t_stack_node **a, t_stack_node **b, t_stack_node *ch)
{
	while (*a != ch->target_node && *b != ch)
		rrr(a, b, false);
	while (*a != ch->target_node)
		rra(a, false);
	while (*b != ch)
		rrb(b, false);
}

static void	exec_mixed(t_stack_node **a, t_stack_node **b, t_stack_node *ch)
{
	if (ch->move_type == 2)
	{
		while (*a != ch->target_node)
			ra(a, false);
		while (*b != ch)
			rrb(b, false);
	}
	else
	{
		while (*a != ch->target_node)
			rra(a, false);
		while (*b != ch)
			rb(b, false);
	}
}

void	exec_cheapest_b(t_stack_node **a, t_stack_node **b, t_stack_node *ch)
{
	if (ch->move_type == 0)
		exec_both_up(a, b, ch);
	else if (ch->move_type == 1)
		exec_both_down(a, b, ch);
	else
		exec_mixed(a, b, ch);
	pa(a, b, false);
}
