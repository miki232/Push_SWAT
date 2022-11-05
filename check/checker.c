/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:32:58 by mtoia             #+#    #+#             */
/*   Updated: 2022/11/05 11:43:37 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	run_2_move(t_stack *stack_a, t_stack *stack_b, char *moves)
{
	if (!ft_strcmp(moves, "ra\n"))
		rotate_a(stack_a);
	else if (!ft_strcmp(moves, "rb\n"))
		rotate_b(stack_a);
	else if (!ft_strcmp(moves, "rra\n"))
		rev_ra(stack_a);
	else if (!ft_strcmp(moves, "rrb\n"))
		rev_rb(stack_b);
	else if (!ft_strcmp(moves, "ss\n"))
		swap_a_b(stack_a, stack_b);
	else if (!ft_strcmp(moves, "rr\n"))
		ra_rb(stack_a, stack_b);
	else if (!ft_strcmp(moves, "rrr\n"))
		rev_ra_rb(stack_a, stack_b);
}

void	simple_moves(t_stack *stack_a, t_stack *stack_b, char **moves)
{
	if (!ft_strcmp(moves[stack_a->j], "pb\n"))
		push_to_b(stack_a, stack_b);
	else if (!ft_strcmp(moves[stack_a->j], "pa\n"))
		push_to_a(stack_a, stack_b);
	else if (!ft_strcmp(moves[stack_a->j], "sa\n"))
		swap_a(stack_a);
	else if (!ft_strcmp(moves[stack_a->j], "sb\n"))
		swap_b(stack_b);
	else if (!ft_strcmp(moves[stack_a->j], "ra\n"))
		rotate_a(stack_a);
	else if (!ft_strcmp(moves[stack_a->j], "rb\n"))
		rotate_b(stack_b);
}

void	run_moves(t_stack *stack_a, t_stack *stack_b, char **moves)
{
	stack_a->j = 0;
	while (stack_a->j < char_array_len(moves))
	{
		simple_moves(stack_a, stack_b, moves);
		if (!ft_strcmp(moves[stack_a->j], "rra\n"))
			rev_ra(stack_a);
		else if (!ft_strcmp(moves[stack_a->j], "rrb\n"))
			rev_rb(stack_b);
		else if (!ft_strcmp(moves[stack_a->j], "ss\n"))
			swap_a_b(stack_a, stack_b);
		else if (!ft_strcmp(moves[stack_a->j], "rr\n"))
			ra_rb(stack_a, stack_b);
		else if (!ft_strcmp(moves[stack_a->j], "rrr\n"))
			rev_ra_rb(stack_a, stack_b);
		stack_a->j++;
	}
}

void	check_move(t_stack *stack_a, t_stack *stack_b, char **moves)
{
	run_moves(stack_a, stack_b, moves);
	if (ft_ordered(stack_a))
		printf("OK\n");
	else
		printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	**moves;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	if (ft_space(argv[1]))
		checker_one(&stack_a, &stack_b, argv);
	else
		checker_two(&stack_a, &stack_b, argc, argv);
	stack_b.stack = malloc(sizeof(int) * stack_a.size);
	moves = read_move(stack_a.size);
	check_move(&stack_a, &stack_b, moves);
	free(moves);
	free(stack_a.stack);
	free(stack_b.stack);
}
