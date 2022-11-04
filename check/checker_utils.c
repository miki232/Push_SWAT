/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:10:39 by mardolin          #+#    #+#             */
/*   Updated: 2022/11/04 16:10:53 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	*loader_int(char **argv, t_stack *stack_a, int i, int c)
{
	stack_a->stack = malloc(sizeof(int) * (stack_a->size));
	if (!stack_a->stack)
		return (0);
	while (i < stack_a->size + c)
	{
		if (c)
			stack_a->stack[i - 1] = ft_atoi(argv[i]);
		else
			stack_a->stack[i] = ft_atoi(argv[i]);
		i++;
	}
	return (0);
}

int	init_struct(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size = 0;
	stack_b->size = 0;
	stack_a->id = 'a';
	stack_b->id = 'b';
	stack_b->size = 0;
	return (0);
}

void	checker_one(t_stack *stack_a, t_stack *stack_b, char **argv)
{
	char	**arg;

	init_struct(stack_a, stack_b);
	arg = ft_split(argv[1], ' ');
	stack_a->size = check_dig2(arg);
	loader_int(arg, stack_a, 0, 0);
	ft_equals(stack_a);
	ft_ordered(stack_a);
}

void	checker_two(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	init_struct(stack_a, stack_b);
	check_dig(argv);
	stack_a->size = argc - 1;
	stack_a->k = 0;
	stack_b->k = 0;
	loader_int(argv, stack_a, 1, 1);
	ft_equals(stack_a);
	ft_ordered(stack_a);
}

char	**read_move(int size)
{
	char	**moves;
	int		max_moves;
	int		i;

	i = 0;
	max_moves = 9000;
	if (size <= 3)
		max_moves = 3;
	else if (size <= 5)
		max_moves = 12;
	else if (size <= 100)
		max_moves = 1200;
	moves = malloc(max_moves * sizeof(char *));
	while (1)
	{
		moves[i] = malloc(4 * sizeof(char));
		moves[i] = get_next_line(0);
		if (moves[i] == NULL)
		{
			free(moves[i]);
			break ;
		}
		i++;
	}
	return (moves);
}
