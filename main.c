/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:07:33 by mtoia             #+#    #+#             */
/*   Updated: 2022/11/03 14:00:00 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push.h"

void	sort_how(t_stack *stack_a, t_stack *stack_b, t_stack *temp)
{
	if (stack_a->size == 2)
		swap_a(stack_a);
	else if (stack_a->size == 3)
		three_guys(stack_a);
	else if (stack_a->size == 4)
		four_guys(stack_a, stack_b);
	else if (stack_a->size == 5)
		five_guys(stack_a, stack_b);
	else if (stack_a->size == 500)
		sortc(stack_a, stack_b, temp);
	else if (stack_a->size == 100)
		sort(stack_a, stack_b, temp);
	else
		sortea(stack_a, stack_b);
}

void	checker_one(t_stack *stack_a, t_stack *stack_b, char **argv)
{
	char	**arg;
	t_stack	temp;

	init_struct(stack_a, stack_b);
	arg = ft_split(argv[1], ' ');
	stack_a->size = check_dig2(arg);
	if (stack_a->size <= 1)
		exit (0);
	loader_int(arg, stack_a, 0, 0);
	stack_b->stack = malloc(sizeof(int *) * stack_a->size);
	ft_equals(stack_a);
	ft_ordered(stack_a);
	sort_how(stack_a, stack_b, &temp);
	freearg(arg);
	free(arg);
}

void	checker_two(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	t_stack	temp;

	init_struct(stack_a, stack_b);
	check_dig(argv);
	stack_a->size = argc - 1;
	if (stack_a->size <= 1)
		exit (0);
	stack_a->k = 0;
	stack_b->k = 0;
	stack_b->stack = malloc(sizeof(int *) * stack_a->size);
	loader_int(argv, stack_a, 1, 1);
	ft_equals(stack_a);
	ft_ordered(stack_a);
	sort_how(stack_a, stack_b, &temp);
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
