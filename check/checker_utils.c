/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:27:41 by mtoia             #+#    #+#             */
/*   Updated: 2022/11/04 20:31:00 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	*loader_int(char **argv, t_stack *stack_a, int i, int c)
{
	stack_a->stack = malloc(sizeof(int **) * (stack_a->size));
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

void	freearg(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
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
	stack_b->stack = malloc(sizeof(int *) * stack_a->size);
	loader_int(arg, stack_a, 0, 0);
	freearg(arg);
	free(arg);
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
	stack_b->stack = malloc(sizeof(int *) * stack_a->size);
	loader_int(argv, stack_a, 1, 1);
	ft_equals(stack_a);
	ft_ordered(stack_a);
}
