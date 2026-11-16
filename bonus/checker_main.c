/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarrero  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:22:49 by rmarrero          #+#    #+#             */
/*   Updated: 2025/07/23 14:23:20 by rmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

static int	exec_swap_push(t_stack_node **a, t_stack_node **b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(a, false);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b, false);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b, false);
	else if (!ft_strcmp(line, "pa\n"))
		pa(a, b, false);
	else if (!ft_strcmp(line, "pb\n"))
		pb(b, a, false);
	else
		return (0);
	return (1);
}

static int	exec_rotate(t_stack_node **a, t_stack_node **b, char *line)
{
	if (!ft_strcmp(line, "ra\n"))
		ra(a, false);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b, false);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b, false);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a, false);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b, false);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b, false);
	else
		return (0);
	return (1);
}

static void	exec_instruction(t_stack_node **a, t_stack_node **b, char *line)
{
	if (exec_swap_push(a, b, line))
		return ;
	if (exec_rotate(a, b, line))
		return ;
	free(line);
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	read_and_exec(t_stack_node **a, t_stack_node **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		exec_instruction(a, b, line);
		free(line);
		line = get_next_line(0);
	}
	if (stack_sorted(*a) && !*b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2 && !argv[1][0])
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else if (argc == 2)
		handle_two_args(&a, argv[1]);
	else
		init_stack_a(&a, argv + 1);
	read_and_exec(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
