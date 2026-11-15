#include "../inc/push_swap.h"

void	assign_ranks(t_stack_node *a)
{
	t_stack_node	*curr;
	t_stack_node	*cmp;
	int				rank;

	curr = a;
	while (curr)
	{
		rank = 0;
		cmp = a;
		while (cmp)
		{
			if (cmp->nbr < curr->nbr)
				rank++;
			cmp = cmp->next;
		}
		curr->rank = rank;
		curr->keep = false;
		curr = curr->next;
	}
}

static int	lis_from_node(t_stack_node *start, t_stack_node *head, bool mark)
{
	t_stack_node	*curr;
	int				last_rank;
	int				count;

	last_rank = start->rank;
	count = 1;
	if (mark)
		start->keep = true;
	curr = start->next;
	if (!curr)
		curr = head;
	while (curr != start)
	{
		if (curr->rank > last_rank)
		{
			last_rank = curr->rank;
			count++;
			if (mark)
				curr->keep = true;
		}
		curr = curr->next;
		if (!curr)
			curr = head;
	}
	return (count);
}

void	mark_lis(t_stack_node *a)
{
	t_stack_node	*curr;
	t_stack_node	*best_start;
	int				max_len;
	int				len;

	if (!a)
		return ;
	max_len = 0;
	best_start = a;
	curr = a;
	while (curr)
	{
		len = lis_from_node(curr, a, false);
		if (len > max_len)
		{
			max_len = len;
			best_start = curr;
		}
		curr = curr->next;
	}
	lis_from_node(best_start, a, true);
}
