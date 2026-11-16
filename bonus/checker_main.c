/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:45:00 by student           #+#    #+#             */
/*   Updated: 2026/11/16 18:45:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	handle_two_args_b(t_node **a, char *arg)
{
	char	**split_argv;

	split_argv = ft_split(arg, ' ');
	if (!split_argv || !split_argv[0])
	{
		free_split(split_argv);
		write(2, "Error\n", 6);
		exit(1);
	}
	init_stack_a(a, split_argv);
	free_split(split_argv);
}

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static bool	exec_line(t_sim *s, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		return (op_sa(s), true);
	if (!ft_strcmp(line, "sb\n"))
		return (op_sb(s), true);
	if (!ft_strcmp(line, "ss\n"))
		return (op_ss(s), true);
	if (!ft_strcmp(line, "pa\n"))
		return (op_pa(s), true);
	if (!ft_strcmp(line, "pb\n"))
		return (op_pb(s), true);
	if (!ft_strcmp(line, "ra\n"))
		return (op_ra(s), true);
	if (!ft_strcmp(line, "rb\n"))
		return (op_rb(s), true);
	if (!ft_strcmp(line, "rr\n"))
		return (op_rr(s), true);
	if (!ft_strcmp(line, "rra\n"))
		return (op_rra(s), true);
	if (!ft_strcmp(line, "rrb\n"))
		return (op_rrb(s), true);
	if (!ft_strcmp(line, "rrr\n"))
		return (op_rrr(s), true);
	return (false);
}

static void	run_checker_loop(t_sim *s)
{
	char	*line;

	init_ops(&s->ops);
	line = get_next_line(0);
	while (line)
	{
		if (!exec_line(s, line))
		{
			free(line);
			free_stack(&s->a);
			free_stack(&s->b);
			free(s->ops.arr);
			write(2, "Error\n", 6);
			exit(1);
		}
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_sim	s;

	s.a = NULL;
	s.b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2 && !argv[1][0])
		return (write(2, "Error\n", 6), 1);
	else if (argc == 2)
		handle_two_args_b(&s.a, argv[1]);
	else
		init_stack_a(&s.a, argv + 1);
	run_checker_loop(&s);
	if (stack_sorted(s.a) && !s.b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&s.a);
	free_stack(&s.b);
	free(s.ops.arr);
	return (0);
}
