/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:07:33 by mtoia             #+#    #+#             */
/*   Updated: 2022/11/02 18:11:31 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push.h"

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

void	checker_one(t_stack *stack_a, t_stack *stack_b, char **argv)
{
	char	**arg;
	t_stack	temp;

	init_struct(stack_a, stack_b);
	arg = ft_split(argv[1], ' ');
	stack_a->size = check_dig2(arg);
	loader_int(arg, stack_a, 0, 0);
	stack_b->stack = malloc(sizeof(int *) * stack_a->size);
	ft_equals(stack_a);
	ft_ordered(stack_a);
	if (stack_a->size == 3)
		three_guys(stack_a);
	else if (stack_a->size == 4)
		four_guys(stack_a, stack_b);
	else if (stack_a->size == 5)
		five_guys(stack_a, stack_b);
	else if (stack_a->size == 100)
		sort(stack_a, stack_b, &temp);
	else if (stack_a->size == 500)
		sortc(stack_a, stack_b, &temp);
	else
		sortea(stack_a, stack_b);
	freearg(arg);
	free(arg);
}

void	checker_two(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	t_stack	temp;

	init_struct(stack_a, stack_b);
	check_dig(argv);
	stack_a->size = argc - 1;
	stack_a->k = 0;
	stack_b->k = 0;
	stack_b->stack = malloc(sizeof(int *) * stack_a->size);
	loader_int(argv, stack_a, 1, 1);
	ft_equals(stack_a);
	ft_ordered(stack_a);
	if (stack_a->size == 3)
		three_guys(stack_a);
	else if (stack_a->size == 4)
		four_guys(stack_a, stack_b);
	else if (stack_a->size == 5)
		five_guys(stack_a, stack_b);
	else if (stack_a->size == 500)
		sortc(stack_a, stack_b, &temp);
	else if (stack_a->size == 100)
		sort(stack_a, stack_b, &temp);
	else
		sortea(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
	{
		exit(0);
	}
	if (ft_space(argv[1]))
		checker_one(&stack_a, &stack_b, argv);
	else
		checker_two(&stack_a, &stack_b, argc, argv);
	free(stack_a.stack);
	free(stack_b.stack);
	return (0);
}
