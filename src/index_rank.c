#include "../inc/push_swap.h"

void	current_index(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

void	assign_ranks(t_node *a)
{
	t_node	*curr;
	t_node	*cmp;
	int		rank;

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

void	mark_keep_three(t_node *a)
{
	int	n;

	n = stack_len(a);
	while (a)
	{
		if (a->rank >= n - 3)
			a->keep = true;
		else
			a->keep = false;
		a = a->next;
	}
}
