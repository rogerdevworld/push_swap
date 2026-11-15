#include "../inc/push_swap.h"

static int	count_pushable(t_stack_node *a, int limit)
{
	int	count;

	count = 0;
	while (a)
	{
		if (!a->keep && a->rank < limit)
			count++;
		a = a->next;
	}
	return (count);
}

static void	push_chunks_to_b(t_stack_node **a, t_stack_node **b, int n)
{
	int	to_push;

	to_push = count_pushable(*a, n / 2);
	while (to_push > 0)
	{
		if (!(*a)->keep && (*a)->rank < n / 2)
		{
			pb(b, a, false);
			to_push--;
			if ((*b)->rank < n / 4 && stack_len(*b) > 1)
			{
				if (to_push > 0 && ((*a)->keep || (*a)->rank >= n / 2))
					rr(a, b, false);
				else
					rb(b, false);
			}
		}
		else
			ra(a, false);
	}
}

static void	push_rest_to_b(t_stack_node **a, t_stack_node **b, int n)
{
	int	to_push;

	to_push = count_pushable(*a, n);
	while (to_push > 0)
	{
		if (!(*a)->keep)
		{
			pb(b, a, false);
			to_push--;
			if ((*b)->rank < (3 * n) / 4 && stack_len(*b) > 1)
			{
				if (to_push > 0 && (*a)->keep)
					rr(a, b, false);
				else
					rb(b, false);
			}
		}
		else
			ra(a, false);
	}
}

static void	min_on_top(t_stack_node **a)
{
	t_stack_node	*min_node;

	current_index(*a);
	min_node = find_min(*a);
	while (*a != min_node)
	{
		if (min_node->index <= stack_len(*a) / 2)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int				n;
	t_stack_node	*cheapest;

	n = stack_len(*a);
	assign_ranks(*a);
	mark_lis(*a);
	push_chunks_to_b(a, b, n);
	push_rest_to_b(a, b, n);
	while (*b)
	{
		cheapest = get_cheapest_b(*a, *b);
		exec_cheapest_b(a, b, cheapest);
	}
	min_on_top(a);
}
