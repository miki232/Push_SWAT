/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:07:33 by mtoia             #+#    #+#             */
/*   Updated: 2022/10/19 16:53:46 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

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
	free(stack_a);
}

int	init_struct(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size = 0;
	stack_b->size = 0;
	stack_a->id = 'a';
	stack_b->id = 'b';
	// stack_b->stack[0] = 4;
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
	stack_b->stack = malloc(sizeof(int) * stack_a->size);
	ft_equals(stack_a);
	ft_ordered(stack_a);
	if (stack_a->size == 3)
		three_guys(stack_a);
	else if (stack_a->size == 4)
		four_guys(stack_a, stack_b);
	else if (stack_a->size == 5)
		five_guys(stack_a, stack_b);
	//print_st(&stack_a);
	print_st(stack_a);
	print_st(stack_b);
}

void	checker_two(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
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
	// print_st(stack_a);
	// print_st(stack_a);
	//sortea(stack_a, stack_b);
	sort(stack_a, stack_b);
	//sortc(stack_a, stack_b);
	// print_st(stack_b);
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
	//print_st(&stack_a);
	// free(&stack_a);
	// free(&stack_b);
}
