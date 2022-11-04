/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:32:58 by mtoia             #+#    #+#             */
/*   Updated: 2022/11/03 16:34:22 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

void	hold_first_num_cin(t_stack *stack_a, int **cn, int j)
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
		while (stack_a->stack[i] != cn[j][c] && c < 45)
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

void	hold_second_num_cin(t_stack *stack_a, int **cn, int j)
{
	int	i;
	int	c;
	int	s;

	c = 0;
	s = 1;
	i = stack_a->size - 1;
	while (i > 0 && s)
	{
		c = 0;
		while ((stack_a->stack[i] != cn[j][c]
			|| stack_a->stack[i] == cn[j][c]) && c < 45)
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

void	find_n_set_a(t_stack *stack_a, int **cn, int j)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	hold_first_num_cin(stack_a, cn, j);
	hold_second_num_cin(stack_a, cn, j);
	i = moves_for_first(stack_a);
	c = moves_for_second(stack_a);
	if ((stack_a->size - c) > i)
	{	
		while (i > 0)
		{
			rotate_a(stack_a);
			i--;
		}
	}
	else
	{
		while (c < stack_a->size)
		{
			rev_ra(stack_a);
			c++;
		}
	}
}

void	freechunk_c(int **cn)
{
	int	j;

	j = 10;
	while (j >= 0)
	{
		free(cn[j]);
		j--;
	}
}

void	sortc(t_stack *stack_a, t_stack *stack_b, t_stack *temp)
{
	int	**cn;

	min_max_val(stack_a);
	stack_b->j = 10;
	stack_a->sec = 0;
	cn = malloc(sizeof(int **) * 11);
	cn = init_cin(cn, stack_a, temp);
	endmmove(stack_a, stack_b, temp, cn);
	free(temp->stack);
	freechunk_c(cn);
	free(cn);
}
