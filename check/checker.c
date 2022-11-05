/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:32:58 by mtoia             #+#    #+#             */
/*   Updated: 2022/11/05 14:56:17 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	read_move(t_stack *stack_a, t_stack *stack_b)
{
	char	*moves;

	while (1)
	{
		moves = get_next_line(0);
		if (moves == NULL)
		{
			break ;
		}
		run_moves(stack_a, stack_b, moves);
		free(moves);
	}
}

int	char_array_len(char **str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len] != NULL)
		len++;
	return (len);
}

void	run_moves(t_stack *stack_a, t_stack *stack_b, char *moves)
{
	if (!ft_strcmp(moves, "pb\n"))
		push_to_b(stack_a, stack_b);
	else if (!ft_strcmp(moves, "pa\n"))
		push_to_a(stack_a, stack_b);
	else if (!ft_strcmp(moves, "sa\n"))
		swap_a(stack_a);
	else if (!ft_strcmp(moves, "sb\n"))
		swap_b(stack_b);
	else if (!ft_strcmp(moves, "ra\n"))
		rotate_a(stack_a);
	else if (!ft_strcmp(moves, "rb\n"))
		rotate_b(stack_b);
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

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		exit(0);
	if (ft_space(argv[1]))
		checker_one(&stack_a, &stack_b, argv);
	else
		checker_two(&stack_a, &stack_b, argc, argv);
	read_move(&stack_a, &stack_b);
	check_move(&stack_a);
	free(stack_a.stack);
	free(stack_b.stack);
}
