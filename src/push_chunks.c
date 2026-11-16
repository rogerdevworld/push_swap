#include "../inc/push_swap.h"

static int	count_in_band(t_node *a, int low, int high)
{
	int	count;

	count = 0;
	while (a)
	{
		if (!a->keep && a->rank >= low && a->rank < high)
			count++;
		a = a->next;
	}
	return (count);
}

static int	shortest_dir_to_band(t_node *a, int low, int high)
{
	int	len;
	int	i;
	int	first;
	int	last;

	len = stack_len(a);
	i = 0;
	first = -1;
	last = -1;
	while (a)
	{
		if (!a->keep && a->rank >= low && a->rank < high)
		{
			if (first == -1)
				first = i;
			last = i;
		}
		a = a->next;
		i++;
	}
	if (first <= len - last)
		return (1);
	return (-1);
}

static void	bring_valid_to_top(t_sim *s, int low, int high)
{
	int	dir;

	dir = shortest_dir_to_band(s->a, low, high);
	while (s->a->keep || s->a->rank < low || s->a->rank >= high)
	{
		if (dir == 1)
			op_ra(s);
		else
			op_rra(s);
	}
}

static void	push_two_bands(t_sim *s, int low, int mid, int high)
{
	int	rem;

	rem = count_in_band(s->a, low, high);
	while (rem > 0)
	{
		bring_valid_to_top(s, low, high);
		op_pb(s);
		rem--;
		if (s->b->rank < mid && stack_len(s->b) > 1)
		{
			if (rem > 0
				&& (s->a->keep || s->a->rank < low || s->a->rank >= high))
				op_rr(s);
			else
				op_rb(s);
		}
	}
}

void	push_chunks(t_sim *s, int n)
{
	int	step;
	int	low;
	int	mid;
	int	high;

	step = n / (s->bands / 2);
	if (step < 1)
		step = 1;
	low = 0;
	while (low < n)
	{
		mid = low + (step / 2);
		high = low + step;
		if (high > n)
			high = n;
		push_two_bands(s, low, mid, high);
		low += step;
	}
}
