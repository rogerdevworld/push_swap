/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp_lis.c                                           */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:45:00 by student           #+#    #+#             */
/*   Updated: 2026/11/16 18:45:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	fill_rot_ranks(t_node *a, int *arr, int start, int n)
{
	t_node	*curr;
	int		i;

	curr = a;
	i = 0;
	while (i < start)
	{
		curr = curr->next;
		i++;
	}
	i = 0;
	while (i < n)
	{
		arr[i] = curr->rank;
		curr = curr->next;
		if (!curr)
			curr = a;
		i++;
	}
}

static int	compute_dp(int *arr, int *dp, int *prev, int n)
{
	int	i;
	int	j;
	int	best;

	i = -1;
	best = 0;
	while (++i < n)
	{
		dp[i] = 1;
		prev[i] = -1;
		j = -1;
		while (++j < i)
		{
			if (arr[j] < arr[i] && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				prev[i] = j;
			}
		}
		if (dp[i] > dp[best])
			best = i;
	}
	return (best);
}

static void	apply_keep_marks(t_node *a, int *arr, int *prev, int best)
{
	t_node	*curr;

	while (best != -1)
	{
		curr = a;
		while (curr)
		{
			if (curr->rank == arr[best])
				curr->keep = true;
			curr = curr->next;
		}
		best = prev[best];
	}
}

static int  eval_rotation(t_node *a, int start, int n, bool mark)
{
    int *buf;
    int best;
    int len;

    len = 0;
    best = 0;
    // Cambiamos malloc por ft_calloc para inicializar todo a 0 por seguridad
    buf = calloc((size_t)(n * 3), sizeof(int));
    if (!buf)
        return (0);
    fill_rot_ranks(a, buf, start, n);
    best = compute_dp(buf, buf + n, buf + (2 * n), n);
    len = (buf + n)[best];
    if (mark)
        apply_keep_marks(a, buf, buf + (2 * n), best);
    free(buf);
    return (len);
}

void	mark_dp_lis(t_node *a)
{
	int	n;
	int	i;
	int	best_rot;
	int	max_len;
	int	len;

	n = stack_len(a);
	max_len = 0;
	best_rot = 0;
	i = 0;
	while (i < n)
	{
		len = eval_rotation(a, i, n, false);
		if (len > max_len)
		{
			max_len = len;
			best_rot = i;
		}
		i++;
	}
	eval_rotation(a, best_rot, n, true);
}
