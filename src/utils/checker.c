/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:19:28 by rmarrero          #+#    #+#             */
/*   Updated: 2025/01/31 17:52:10 by rmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

// --- checker --- //
void	checker(t_stack *stack)
{
	if (!sorted(stack))
		ft_printf("\033[0;31m[KO]\033[0m");
	else
		ft_printf("\033[0;32m[OK]\033[0m\n");
}

// --- get stack size --- //
size_t	size_stack(t_stack *stack)
{
	t_stack	*tmp;
	size_t	i;

	if (!stack)
		return (0);
	i = 0;
	tmp = stack;
	while (tmp->next && tmp->next != stack)
	{
		i++;
		tmp = tmp->next;
	}
	return (i + 1);
}
