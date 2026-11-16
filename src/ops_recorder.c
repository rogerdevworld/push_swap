/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_recorder.c                                     */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:45:00 by student           #+#    #+#             */
/*   Updated: 2026/11/16 18:45:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_ops(t_ops *ops)
{
	ops->cap = 8192;
	ops->len = 0;
	ops->arr = malloc(sizeof(int) * (size_t)ops->cap);
}

void	record_op(t_ops *ops, int op)
{
	int	*new_arr;
	int	i;

	if (ops->len >= ops->cap)
	{
		ops->cap *= 2;
		new_arr = malloc(sizeof(int) * (size_t)ops->cap);
		i = 0;
		while (i < ops->len)
		{
			new_arr[i] = ops->arr[i];
			i++;
		}
		free(ops->arr);
		ops->arr = new_arr;
	}
	ops->arr[ops->len++] = op;
}

static int	merge_pair(int a, int b)
{
	if ((a == OP_RA && b == OP_RB) || (a == OP_RB && b == OP_RA))
		return (OP_RR);
	if ((a == OP_RRA && b == OP_RRB) || (a == OP_RRB && b == OP_RRA))
		return (OP_RRR);
	if ((a == OP_SA && b == OP_SB) || (a == OP_SB && b == OP_SA))
		return (OP_SS);
	if ((a == OP_PA && b == OP_PB) || (a == OP_PB && b == OP_PA))
		return (-1);
	if ((a == OP_RA && b == OP_RRA) || (a == OP_RRA && b == OP_RA))
		return (-1);
	if ((a == OP_RB && b == OP_RRB) || (a == OP_RRB && b == OP_RB))
		return (-1);
	return (0);
}

void	optimize_ops(t_ops *ops)
{
	int	i;
	int	j;
	int	m;

	i = 0;
	j = 0;
	while (i < ops->len)
	{
		m = 0;
		if (i + 1 < ops->len)
			m = merge_pair(ops->arr[i], ops->arr[i + 1]);
		if (m == -1)
			i += 2;
		else if (m > 0)
		{
			ops->arr[j++] = m;
			i += 2;
		}
		else
			ops->arr[j++] = ops->arr[i++];
	}
	ops->len = j;
}

void	print_ops(t_ops *ops)
{
	static const char	*names[12] = {
		"", "sa\n", "sb\n", "ss\n", "pa\n", "pb\n",
		"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"
	};
	int					i;
	int					len;

	i = 0;
	while (i < ops->len)
	{
		len = 3;
		if (ops->arr[i] >= OP_RRA)
			len = 4;
		int byte = write(1, names[ops->arr[i]], (size_t)len);
		(void)byte;
		i++;
	}
}
