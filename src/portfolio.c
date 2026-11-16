#include "../inc/push_swap.h"

void	sort_three(t_sim *s)
{
	t_node	*big;

	big = find_max(s->a);
	if (big == s->a)
		op_ra(s);
	else if (s->a->next == big)
		op_rra(s);
	if (s->a->nbr > s->a->next->nbr)
		op_sa(s);
}

static void	min_on_top(t_sim *s)
{
	t_node	*min_node;

	current_index(s->a);
	min_node = find_min(s->a);
	while (s->a != min_node)
	{
		if (min_node->index <= stack_len(s->a) / 2)
			op_ra(s);
		else
			op_rra(s);
	}
}

static void	run_variant(t_sim *s, t_node *orig_a)
{
	int		n;
	t_node	*ch;

	s->a = clone_stack(orig_a);
	s->b = NULL;
	init_ops(&s->ops);
	n = stack_len(s->a);
	assign_ranks(s->a);
	if (s->use_lis)
		mark_dp_lis(s->a);
	else
		mark_keep_three(s->a);
	push_chunks(s, n);
	if (!s->use_lis)
		sort_three(s);
	while (s->b)
	{
		ch = get_cheapest_b(s);
		exec_cheapest_b(s, ch);
	}
	min_on_top(s);
	optimize_ops(&s->ops);
	free_stack(&s->a);
}

static void	configure_variants(t_sim v[6])
{
	v[0] = (t_sim){NULL, NULL, {NULL, 0, 0}, 4, true, false};
	v[1] = (t_sim){NULL, NULL, {NULL, 0, 0}, 6, true, false};
	v[2] = (t_sim){NULL, NULL, {NULL, 0, 0}, 8, true, true};
	v[3] = (t_sim){NULL, NULL, {NULL, 0, 0}, 6, false, false};
	v[4] = (t_sim){NULL, NULL, {NULL, 0, 0}, 8, false, true};
	v[5] = (t_sim){NULL, NULL, {NULL, 0, 0}, 10, false, true};
}

void	run_portfolio(t_node *orig_a)
{
	t_sim	v[6];
	int		i;
	int		best;

	configure_variants(v);
	i = 0;
	best = 0;
	while (i < 6)
	{
		run_variant(&v[i], orig_a);
		if (v[i].ops.len < v[best].ops.len)
			best = i;
		i++;
	}
	print_ops(&v[best].ops);
	i = 0;
	while (i < 6)
		free(v[i++].ops.arr);
}
