/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:07:33 by mtoia             #+#    #+#             */
/*   Updated: 2022/10/30 14:51:06 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	init_struct(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size = 0;
	stack_b->size = 0;
	stack_a->id = 'a';
	stack_b->id = 'b';
	stack_b->size = 0;
	stack_a->sec = 0;
	stack_a->i = 0;
	stack_a->c = 0;
	stack_a->j = 0;
	return (0);
}

int	init_temp(t_stack *temp)
{
	temp->j = 19;
	temp->i = 0;
	temp->c = 4;
	return (0);
}

void	checker_one(t_stack *stack_a, t_stack *stack_b, char **argv)
{
	char	**arg;
	t_stack	temp;

	init_struct(stack_a, stack_b);
	arg = ft_split(argv[1], ' ');
	stack_a->size = check_dig2(arg);
	loader_int(arg, stack_a, 0, 0);
	stack_b->stack = malloc(sizeof(int) * stack_a->size);
	ft_equals(stack_a);
	ft_ordered(stack_a);
	if (stack_a->size == 3)
		three_guys(stack_a);
	else if (stack_a->size == 4)
		four_guys(stack_a, stack_b);
	else if (stack_a->size == 5)
		five_guys(stack_a, stack_b);
	else
		sort(stack_a, stack_b, &temp);
	print_st(stack_a);
}

void	checker_two(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	t_stack	temp;

	init_struct(stack_a, stack_b);
	check_dig(argv);
	stack_a->size = argc - 1;
	stack_a->k = 0;
	stack_b->k = 0;
	stack_b->stack = malloc(sizeof(int) * stack_a->size);
	loader_int(argv, stack_a, 1, 1);
	ft_equals(stack_a);
	ft_ordered(stack_a);
	if (stack_a->size == 3)
		three_guys(stack_a);
	else if (stack_a->size == 4)
		four_guys(stack_a, stack_b);
	else if (stack_a->size == 5)
		five_guys(stack_a, stack_b);
	else
		sort(stack_a, stack_b, &temp);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
	{
		printf("ERROR\n");
		exit(0);
	}
	if (ft_space(argv[1]))
		checker_one(&stack_a, &stack_b, argv);
	else
		checker_two(&stack_a, &stack_b, argc, argv);
}
