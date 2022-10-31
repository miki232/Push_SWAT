/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:32:58 by mtoia             #+#    #+#             */
/*   Updated: 2022/10/31 12:32:44 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	moves_count_min_max_cin(t_stack *stack, int num)
{
	int	i;
	
	i = 0;
	while (stack->stack[i] != num)
	{
		i++;
	}
	stack->i_max = i;	
}

// void	chunk1(int i, t_stack *temp, int **chunk)
// {
// 	if (i < 45)
// 			chunk[c][j] = temp->stack[i];
// 		else if (i > 44 && i < 90)
// 		{
// 			if(i == 45)
// 			{
// 				j = 44;
// 				c--;
// 			}
// 			chunk[c][j] = temp->stack[i];
// 			//printf("c%d\n", j);
// 		}
// 		else if (i > 89 && i < 135)
// 		{
// 			if(i == 90)
// 			{
// 				j = 44;
// 				c--;
// 			}
// 			chunk[c][j] = temp->stack[i];
// 		}
// }

int	**init_cin(int **chunk, t_stack *stack_a, t_stack *temp)
{
	int	i = 0;
	int	j = 44;
	

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
	int c = 10;
	while (i < 495)
	{
		if (i < 45)
			chunk[c][j] = temp->stack[i];
		else if (i > 44 && i < 90)
		{
			if(i == 45)
			{
				j = 44;
				c--;
			}
			chunk[c][j] = temp->stack[i];
			//printf("c%d\n", j);
		}
		else if (i > 89 && i < 135)  //////dividere sta mincia di funzione
		{
			if(i == 90)
			{
				j = 44;
				c--;
			}
			chunk[c][j] = temp->stack[i];
		}
		else if (i > 134 && i < 180)
		{
			if(i == 135)
			{
				j = 44;
				c--;
			}
			chunk[c][j] = temp->stack[i];
		}
		else if (i > 179 && i < 225)
		{
			if(i == 180)
			{
				j = 44;
				c--;
			}
			chunk[c][j] = temp->stack[i];
		}
		else if (i > 224 && i < 270)
		{
			if(i == 225)
			{
				j = 44;
				c--;
			}
			chunk[c][j] = temp->stack[i];
		}
		else if (i > 269 && i < 315)
		{
			if(i == 270)
			{
				j = 44;
				c--;
			}
			chunk[c][j] = temp->stack[i];
		}
		else if (i > 314 && i < 360)
		{
			if(i == 315)
			{
				j = 44;
				c--;
			}
			chunk[c][j] = temp->stack[i];
		}
		else if (i > 359 && i < 405)
		{
			if(i == 360)
			{
				j = 44;
				c--;
			}
			chunk[c][j] = temp->stack[i];
		}
		else if (i > 404 && i < 450)
		{
			if(i == 405)
			{
				j = 44;
				c--;
			}
			chunk[c][j] = temp->stack[i];
		}
		else if (i > 449 && i < 495)
		{
			if(i == 450)
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

int	shiva_cin(t_stack *temp, t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int	c;

	c = stack_b->size - 1;
	i = 499;
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

void	hold_first_num_cin(t_stack *stack_a, int **cn, int j)
{
	int i;
	int c;
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
	int s;
	
	c = 0;
	s = 1;
	i = stack_a->size - 1;
	while (i > 0 && s)
	{
		c = 0;
		while ((stack_a->stack[i] != cn[j][c] || stack_a->stack[i] == cn[j][c]) && c < 45)
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

void	chunck_index_increment(t_stack *stack_b)
{
	if (stack_b->size == 45)
		stack_b->j--;
	if (stack_b->size == 90)
		stack_b->j--;
	if (stack_b->size == 135)
		stack_b->j--;
	if (stack_b->size == 180)
		stack_b->j--;
	if (stack_b->size == 225)
		stack_b->j--;
	if (stack_b->size == 270)
		stack_b->j--;
	if (stack_b->size == 315)
		stack_b->j--;
	if (stack_b->size == 360)
		stack_b->j--;
	if (stack_b->size == 405)
		stack_b->j--;
	if (stack_b->size == 450)
		stack_b->j--;
}

void	mmove_b(t_stack *stack_a, t_stack *stack_b, t_stack *temp)
{
		if (stack_a->stack[0] < stack_b->min || stack_a->stack[0] > stack_b->max)
		{
			while (stack_b->stack[0] != stack_b->max)
			{
				moves_count_min_max_cin(stack_b, stack_b->max);
				if (stack_b->i_max > (stack_b->size / 2))
					rev_rb(stack_b);
				else
					rotate_b(stack_b);
			}
			push_to_b(stack_a, stack_b);
		}
		else 
		{
			stack_a->sec = shiva_cin(temp, stack_a, stack_b);
			while (stack_b->stack[0] != stack_a->sec)
			{
				moves_count_min_max_cin(stack_b, stack_a->sec);
				if (stack_b->i_max > (stack_b->size / 2))
					rev_rb(stack_b);
				else
					rotate_b(stack_b);
			}
			push_to_b(stack_a, stack_b);
		}
}

void	move_ghelper(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->stack[0] == stack_b->max || stack_b->size > 0)
	{
		while (stack_b->stack[0] != stack_b->max)
		{
			rev_rb(stack_b);
		}	
		push_to_a(stack_a, stack_b);
		if (stack_b->size > 0)
			min_max_val(stack_b);
	}
}

void	endmmove(t_stack *stack_a, t_stack *stack_b, t_stack *temp, int **cn)
{
	while (stack_a->size > (5))
	{
		find_n_set_a(stack_a, cn, stack_b->j);
		min_max_val(stack_b);
		if (stack_b->size < 1)
			push_to_b(stack_a, stack_b);
		else
			mmove_b(stack_a, stack_b, temp);
		chunck_index_increment(stack_b);
	}
	if (stack_a->size == 5)
		five_guys(stack_a, stack_b);
	min_max_val(stack_b);
	while (stack_b->stack[0] != stack_b->max)
	{
		rev_rb(stack_b);
	}
	move_ghelper(stack_a, stack_b);	
}

void	sortc(t_stack *stack_a, t_stack *stack_b, t_stack *temp)
{
	int **cn;

	min_max_val(stack_a);
	stack_b->j = 10;
	stack_a->sec = 0;
	cn = malloc(sizeof(int **) * 11);
	cn = init_cin(cn, stack_a, temp);
	endmmove(stack_a, stack_b, temp, cn);
}
