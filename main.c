/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:07:33 by mtoia             #+#    #+#             */
/*   Updated: 2022/11/01 18:50:41 by mtoia            ###   ########.fr       */
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
	print_st(stack_a);
	if (stack_a->size == 3)
		three_guys(stack_a);
	else if (stack_a->size == 4)
		four_guys(stack_a, stack_b);
	else if (stack_a->size == 5)
		five_guys(stack_a, stack_b);
	sort(stack_a, stack_b);
	//print_st(&stack_a);
	print_st(stack_b);
}

int	islis(int num, int *arr, int i)
{
	while ((num != arr[i] || num == arr[i]) && i >= 0)
	{
		if (num == arr[i])
		{
			return (0);
		}
		i--;
	}
	
	return (1);
}

void	find_spot_on_b(t_stack *stack_b, int arr)
{
	int j;

	j = 0;
	while (j < stack_b->size)
	{
		if (stack_b->stack[j] < arr && stack_b->stack[j + 1] > arr)
		{
			stack_b->k = 1;
		}
		else if (stack_b->stack[j] < arr && stack_b->stack[j + 1] < arr && stack_b->stack[j + 2] > arr)
		{
			stack_b->k = 3;
		}
		
		
	}
	
}

void	mmove(t_stack *stack_a, t_stack *stack_b, int *arr, int i)
{
	int j;
	int	k;

	i -= 1;
	k = 0;
	j = 0;
	while (j < stack_a->size && k <= i)
	{
		if (stack_a->stack[0] != arr[k])
			rotate_a(stack_a);
		else
		{
			push_to_b(stack_a, stack_b);
			k++;
			j = 0;
		}
		//printf("Stack[0] = %d, lis %d\n", stack_a->stack[0], arr[i]);
		//i = k;
		j++;
	}
	i = 0;
	arr = ft_define_lis(stack_a->stack, stack_a->size, &i);
	i -= 1;
	j = 0;
	while (i >= 0)
	{
		while (j <= stack_a->size)
		{
			if (stack_a->stack[0] != arr[i])
			{
				rev_ra(stack_a);
			}
			else
			{
				find_spot_on_b(stack_b, arr[i]);	
			}
			j++;
		}
		i--;
	}
	
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
	int *arr;
	int i;
	i = 0;
	arr = malloc(sizeof(int) * stack_a->size);
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
	arr = ft_define_lis(stack_a->stack, stack_a->size, &i);
	mmove(stack_a, stack_b, arr, i);
	
		
	//sort(stack_a, stack_b);
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
