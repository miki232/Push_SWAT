/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:42:40 by mardolin          #+#    #+#             */
/*   Updated: 2022/10/30 15:02:26 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

void	secondmin(t_stack *s)
{
	int	i;
	int	temp;

	i = 0;
	temp = s->min;
	while (temp < s->max)
	{
		i = 0;
		temp++;
		while (i < s->size)
		{
			if (temp == s->stack[i])
			{
				s->min = s->stack[i];
				return ;
			}
			i++;
		}
	}
}

void	printcn(int **chunk, int c)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		printf("Al chunck[%d][%d] = %d \n", c, i, chunk[c][i]);
		i++;
	}
}

void	calc_moves(t_stack *stack)
{
	while (stack->stack[stack->i] != stack->min)
		stack->i++;
	while (stack->stack[stack->c] != stack->max)
		stack->c++;
	if (stack->i > stack->size / 2 && stack->c > stack->size / 2)
	{
		stack->i_max = (stack->size - stack->c);
		stack->i_min = (stack->size - stack->i);
	}
	else if (stack->i < stack->size / 2 && stack->c < stack->size / 2)
	{
		stack->i_max = stack->c;
		stack->i_min = stack->i;
	}
	else if (stack->i < stack->size / 2 && stack->c > stack->size / 2)
	{
		stack->i_max = (stack->size - stack->c);
		stack->i_min = stack->i;
	}
	else if (stack->i > stack->size / 2 && stack->c < stack->size / 2)
	{
		stack->i_max = stack->c;
		stack->i_min = (stack->size - stack->i);
	}
}

int	shiva(t_stack *temp, t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	c;

	c = stack_b->size - 1;
	i = 99;
	while (temp->stack[i] != stack_a->stack[0])
		i--;
	while (c >= 0)
	{
		if (stack_b->stack[c] == temp->stack[i - 1])
			return (stack_b->stack[c]);
		else if (c == 0)
		{
			c = stack_b->size;
			i--;
		}
		c--;
	}
	return (0);
}

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
