#include "../inc/push_swap.h"

static void	rev_rotate_nodes(t_node **stack)
{
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	op_rra(t_sim *s)
{
	rev_rotate_nodes(&s->a);
	record_op(&s->ops, OP_RRA);
}

void	op_rrb(t_sim *s)
{
	rev_rotate_nodes(&s->b);
	record_op(&s->ops, OP_RRB);
}

void	op_rrr(t_sim *s)
{
	rev_rotate_nodes(&s->a);
	rev_rotate_nodes(&s->b);
	record_op(&s->ops, OP_RRR);
}
