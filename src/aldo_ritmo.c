/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aldo_ritmo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:32:58 by mtoia             #+#    #+#             */
/*   Updated: 2022/11/01 17:48:25 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

void	hold_first_num(t_stack *stack_a, int **cn, int j)
{
	int	i;
	int	c;
	int	s;

	i = 0;
	s = 1;
	c = 0;
	while (i < stack_a->size && s)
	{
		c = 0;
		while (stack_a->stack[i] != cn[j][c] && c < 20)
		{
			c++;
			if (stack_a->stack[i] == cn[j][c])
			{
				stack_a->hlf = stack_a->stack[i];
				s = 0;
			}
		}
		i++;
	}
}

void	hold_second_num(t_stack *stack_a, int **cn, int j)
{
	int	i;
	int	c;
	int	s;

	c = 0;
	s = 1;
	i = stack_a->size - 1;
	while (i >= 0 && s)
	{
		c = 0;
		while ((stack_a->stack[i] != cn[j][c]
			|| stack_a->stack[i] == cn[j][c]) && c < 20)
		{
			if (stack_a->stack[i] == cn[j][c])
			{
				stack_a->hls = stack_a->stack[i];
				s = 0;
			}
			c++;
		}
		i--;
	}
}

int	size(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size == 20)
		stack_a->j++;
	if (stack_b->size == 40)
		stack_a->j++;
	if (stack_b->size == 60)
		stack_a->j++;
	if (stack_b->size == 80)
		stack_a->j++;
	return (1);
}

void	freechunk(t_stack *temp)
{
	int j;

	j = 4;
	while (j >= 0)
	{
		free(temp->cn[j]);
		j--;
	}
	
}

void	sort(t_stack *stack_a, t_stack *stack_b, t_stack *temp)
{
	min_max_val(stack_a);
	temp->cn = malloc(sizeof(int **) * 5);
	temp->cn = init(temp->cn, stack_a, temp);
	while (stack_a->size > (0))
	{
		hold_first_num(stack_a, temp->cn, stack_a->j);
		hold_second_num(stack_a, temp->cn, stack_a->j);
		stack_a->i = moves_for_first(stack_a);
		stack_a->c = moves_for_second(stack_a);
		base_moves(stack_a);
		min_max_val(stack_b);
		mov_stack_b(stack_a, stack_b, temp);
		size(stack_a, stack_b);
	}
	while (stack_b->stack[0] != stack_b->max)
	{
		rotate_b(stack_b);
		min_max_val(stack_b);
		while (stack_b->stack[0] == stack_b->max && stack_b->size > 0)
		{
			push_to_a(stack_a, stack_b);
			min_max_val(stack_b);
		}
	}
	freechunk(temp);
}
