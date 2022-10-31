/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:07:33 by mtoia             #+#    #+#             */
/*   Updated: 2022/10/31 16:51:17 by mardolin         ###   ########.fr       */
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

int	init_temp_c(t_stack *temp)
{
	temp->j = 44;
	temp->i = 0;
	temp->c = 10;
	return (0);
}

int	check_stack(t_stack *stack)
{
	if (stack->size > 0)
		return (1);
	return (0);
}

void	sortea(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int c;
	int	k;
	int	e;
	
	c = 0;
	i = 0;
	k = 0;
	e = 0;
	min_max_val(stack_a);
	secondmin(stack_a);
	while (i < stack_a->size)
	{
		e = 0;
		c = 0;
		min_max_val(stack_a);
		while (stack_a->stack[c] != stack_a->min)
			c++;
		secondmin(stack_a);
		while (stack_a->stack[e] != stack_a->min)
			e++;
		if (c > (stack_a->size / 2) && e > (stack_a->size / 2))
		{
			if (c > e)
			{
				while (c < stack_a->size)
				{
					rev_ra(stack_a);
					k++;
					c++;
				}
			}
			else if (e > c)
			{
				while (e < stack_a->size)
				{
					rev_ra(stack_a);
					k++;
					e++;
				}
			}
		}
		else if (c > (stack_a->size / 2) && e < (stack_a->size / 2))
		{
			if (c > e)
			{
				while (c < stack_a->size)
				{
					rev_ra(stack_a);
					k++;
					c++;
				}
			}
			else if (e < c)
			{
				while (e > 0)
				{
					rotate_a(stack_a);
					k++;
					e--;
				}
			}
		}
		else if (c < (stack_a->size / 2) && e > (stack_a->size / 2))
		{
			if (c < e)
			{
				while (c > 0)
				{
					rotate_a(stack_a);
					k++;
					c--;
				}
			}
		}
		else if (e < (stack_a->size / 2) && c < (stack_a->size / 2))
		{
			if (c < e)
			{
				while (c > 0)
				{
					rotate_a(stack_a);
					k++;
					c--;
				}
			}
			else if (e < c)
			{
				while (e > 0)
				{
					rotate_a(stack_a);
					k++;
					e--;
				}
			}
		}
		i++;
		secondmin(stack_a);
		push_to_b(stack_a, stack_b);
		k++;
		// print_st(stack_b);
		// print_st(stack_a);
		if (i >= stack_a->size)
			i = 0;
	}
	i = 0;
	while (i < stack_b->size)
	{
		push_to_a(stack_a, stack_b);
		k++;
		i++;
		if (i >= stack_b->size)
			i = 0;
	}
	
	print_st(stack_b);
	print_st(stack_a);
	printf("%d\n", k);
	// min_max_val(stack_a);
	// printf("%d\n", stack_a->min);
	// secondmin(stack_a);
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
	else if (stack_a->size < 100)
		sortea(stack_a, stack_b);
	else if (stack_a->size <= 500 && stack_a->size > 100)
		sortc(stack_a, stack_b, &temp);
	// print_st(stack_a);
	// print_st(stack_b);
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
	else if (stack_a->size < 100)
		sortea(stack_a, stack_b);
	else if (stack_a->size <= 500 && stack_a->size > 100)
		sortc(stack_a, stack_b, &temp);
	// print_st(stack_a);
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
}
