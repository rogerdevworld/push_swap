#include "../inc/push_swap.h"

static void	swap_b(t_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	op_sb(t_sim *s)
{
	swap_b(&s->b);
	record_op(&s->ops, OP_SB);
}

void	op_ss(t_sim *s)
{
	swap_b(&s->a);
	swap_b(&s->b);
	record_op(&s->ops, OP_SS);
}
