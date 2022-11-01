/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:32:58 by mtoia             #+#    #+#             */
/*   Updated: 2022/11/01 17:21:08 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

int	**init_cin(int **chunk, t_stack *stack_a, t_stack *temp)
{
	int	i;
	int	j;
	int	c;

	j = 44;
	i = 0;
	temp->id = 't';
	temp->stack = malloc(sizeof(int) * stack_a->size);
	temp->size = stack_a->size;
	while (i < 11)
	{
		chunk[i] = malloc(sizeof(int *) * 45);
		i++;
	}
	checkss(stack_a, temp);
	i = 0;
	c = 10;
	while (i < 495)
	{
		if (i < 45)
			chunk[c][j] = temp->stack[i];
		else if (i > 44 && i < 90)
		{
			if (i == 45)
			{
				j = 44;
				c--;
			}
			chunk[c][j] = temp->stack[i];
		}
		else if (i > 89 && i < 135)
		{
			if (i == 90)
			{
				j = 44;
				c--;
			}
			chunk[c][j] = temp->stack[i];
		}
		else if (i > 134 && i < 180)
		{
			if (i == 135)
			{
				j = 44;
				c--;
			}
			chunk[c][j] = temp->stack[i];
		}
		else if (i > 179 && i < 225)
		{
			if (i == 180)
			{
				j = 44;
				c--;
			}
			chunk[c][j] = temp->stack[i];
		}
		else if (i > 224 && i < 270)
		{
			if (i == 225)
			{
				j = 44;
				c--;
			}
			chunk[c][j] = temp->stack[i];
		}
		else if (i > 269 && i < 315)
		{
			if (i == 270)
			{
				j = 44;
				c--;
			}
			chunk[c][j] = temp->stack[i];
		}
		else if (i > 314 && i < 360)
		{
			if (i == 315)
			{
				j = 44;
				c--;
			}
			chunk[c][j] = temp->stack[i];
		}
		else if (i > 359 && i < 405)
		{
			if (i == 360)
			{
				j = 44;
				c--;
			}
			chunk[c][j] = temp->stack[i];
		}
		else if (i > 404 && i < 450)
		{
			if (i == 405)
			{
				j = 44;
				c--;
			}
			chunk[c][j] = temp->stack[i];
		}
		else if (i > 449 && i < 495)
		{
			if (i == 450)
			{
				j = 44;
				c--;
			}
			chunk[c][j] = temp->stack[i];
		}
		i++;
		j--;
	}
	return (chunk);
}

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

void	sortc(t_stack *stack_a, t_stack *stack_b, t_stack *temp)
{
	int	**cn;

	min_max_val(stack_a);
	stack_b->j = 10;
	stack_a->sec = 0;
	cn = malloc(sizeof(int **) * 11);
	cn = init_cin(cn, stack_a, temp);
	endmmove(stack_a, stack_b, temp, cn);
	
}
