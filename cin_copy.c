/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cin_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:32:58 by mtoia             #+#    #+#             */
/*   Updated: 2022/10/30 16:54:19 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	three_guys(t_stack *s)
{
	if (s->stack[0] > s->stack[1] && s->stack[1] < s->stack[2] \
		&& s->stack[2] > s->stack[0])
		swap_a(s);
	else if (s->stack[0] < s->stack[1] && s->stack[1] > s->stack[2] \
				&& s->stack[2] > s->stack[0])
	{
		swap_a(s);
		rotate_a(s);
	}
	else if (s->stack[0] < s->stack[1] && s->stack[1] > s->stack[2] \
			&& s->stack[2] < s->stack[0])
		rev_ra(s);
	else if (s->stack[0] > s->stack[1] && s->stack[1] > s->stack[2] \
			&& s->stack[2] < s->stack[0])
	{
		rotate_a(s);
		swap_a(s);
	}
	else if (s->stack[0] > s->stack[1] && s->stack[1] < s->stack[2] \
			&& s->stack[2] < s->stack[0])
		rotate_a(s);
}

void	moves_count_min_max(t_stack *stack, int num)
{
	int	i;
	
	i = 0;
	while (stack->stack[i] != num)
	{
		i++;
	}
	stack->i_min = i;	
}

void	min_max_val(t_stack *s)
{
	int	i;

	s->max = 0;
	s->min = 0;
	i = 0;
	s->max = s->stack[0];
	s->min = s->max;
	while (i < s->size)
	{
		if (s->max < s->stack[i])
		{
			s->max = s->stack[i];
			s->i_max = i;
		}
		if (s->min > s->stack[i])
		{
			s->min = s->stack[i];
			s->i_min = i;
		}
		i++;
	}
}

void	four_guys(t_stack *stack_a, t_stack *stack_b)
{
	min_max_val(stack_a);
	while (stack_a->stack[0] != stack_a->min)
		rotate_a(stack_a);
	push_to_b(stack_a, stack_b);
	three_guys(stack_a);
	push_to_a(stack_a, stack_b);
}

void	five_guys(t_stack *stack_a, t_stack *stack_b)
{
	min_max_val(stack_a);
	while (stack_a->stack[0] != stack_a->max)
		rotate_a(stack_a);
	push_to_b(stack_a, stack_b);
	while (stack_a->stack[0] != stack_a->min)
		rotate_a(stack_a);
	push_to_b(stack_a, stack_b);
	three_guys(stack_a);
	push_to_a(stack_a, stack_b);
	push_to_a(stack_a, stack_b);
	rotate_a(stack_a);
}

void	secondmin(t_stack *s)
{
	int i;
	int temp;

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
				//printf("%d\n", s->min);
				return ;
			}
			i++;
		}
	}
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

void	checkss(t_stack *stack_a, t_stack *temp)
{
	int	i = 0;
	int	j = 0;
	
	while (j < temp->size)
	{
		i = 0;
		while (i < stack_a->size)
		{
			if (stack_a->stack[i] == stack_a->min)
			{
				temp->stack[j] = stack_a->stack[i];
				secondmin(stack_a);
				break ;
			}
			i++;
		}
		j++;
	}
}

int	**init(int **chunk, t_stack *stack_a, t_stack *temp)
{
	int	i = 0;
	int	j = 0;
	

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
	//print_st(&temp);
	int c = 0;
	while (i < 495)
	{
		if (i < 45)
			chunk[c][j] = temp->stack[i];
		else if (i > 44 && i < 90)
		{
			if(i == 45)
			{
				j = 0;
				c++;
			}
			chunk[c][j] = temp->stack[i];
			//printf("c%d\n", j);
		}
		else if (i > 89 && i < 135)
		{
			if(i == 90)
			{
				j = 0;
				c++;
			}
			chunk[c][j] = temp->stack[i];
		}
		else if (i > 134 && i < 180)
		{
			if(i == 135)
			{
				j = 0;
				c++;
			}
			chunk[c][j] = temp->stack[i];
		}
		else if (i > 179 && i < 225)
		{
			if(i == 180)
			{
				j = 0;
				c++;
			}
			chunk[c][j] = temp->stack[i];
		}
        else if (i > 224 && i < 270)
		{
			if(i == 225)
			{
				j = 0;
				c++;
			}
			chunk[c][j] = temp->stack[i];
		}
        else if (i > 269 && i < 315)
		{
			if(i == 270)
			{
				j = 0;
				c++;
			}
			chunk[c][j] = temp->stack[i];
		}
        else if (i > 314 && i < 360)
		{
			if(i == 315)
			{
				j = 0;
				c++;
			}
			chunk[c][j] = temp->stack[i];
		}
        else if (i > 359 && i < 405)
		{
			if(i == 360)
			{
				j = 0;
				c++;
			}
			chunk[c][j] = temp->stack[i];
		}
        else if (i > 404 && i < 450)
		{
			if(i == 405)
			{
				j = 0;
				c++;
			}
			chunk[c][j] = temp->stack[i];
		}
        else if (i > 449 && i < 495)
		{
			if(i == 450)
			{
				j = 0;
				c++;
			}
			chunk[c][j] = temp->stack[i];
		}
		i++;
		j++;
	}
	//printf("cn  %d\n", chunk[0][44]);
	return (chunk);

}

void	calc_moves(t_stack *stack)
{
	int i;
	int c;

	c = 0;
	i = 0;
	while (stack->stack[i] != stack->min)
		i++;
	while (stack->stack[c] != stack->max)
		c++;
	if	(i > stack->size / 2 && c > stack->size / 2)
	{
			stack->i_max = (stack->size - c);
			stack->i_min = (stack->size - i);
	}
	else if	(i < stack->size / 2 && c < stack->size / 2)
	{
			stack->i_max = c;
			stack->i_min = i;
	}
	else if	(i < stack->size / 2 && c > stack->size / 2)
	{
			stack->i_max = (stack->size - c);
			stack->i_min = i;
	}
	else if	(i > stack->size / 2 && c < stack->size / 2)
	{
			stack->i_max = c;
			stack->i_min = (stack->size - i);
	}
}

int	shiva(t_stack *temp, t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int	c;

	c = stack_b->size - 1;
	i = 0;
	while (temp->stack[i] != stack_a->stack[0])
		i++;
	while (c >= 0)
	{
		if (stack_b->stack[c] == temp->stack[i + 1])
			return (stack_b->stack[c]);
		else if (c == 0)
		{
			c = stack_b->size;
			i++;
		}
		c--;
	}
	return (0);
}

void	hold_first_num(t_stack *stack_a, int **cn, int j)
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

void	hold_second_num(t_stack *stack_a, int **cn, int j)
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

int	moves_for_first(t_stack *stack_a)
{
	int i;

	i = 0;
	while (stack_a->stack[i] != stack_a->hlf)
		i++;
	return (i);	
}

int	moves_for_second(t_stack *stack_a)
{
	int c;
	
	c = stack_a->size - 1;
	while (stack_a->stack[c] != stack_a->hls || stack_a->stack[c] == stack_a->hls)
	{
		if (stack_a->stack[c] == stack_a->hls)
		{
			break ;
		}
		c--;
	}
	return (c);
}

void	sortc(t_stack *stack_a, t_stack *stack_b, t_stack *temp)
{
	int i;
	int	c = 0;
	int	j = 0;
	int	sec = 0;
	int **cn;
		
	min_max_val(stack_a);
	cn = malloc(sizeof(int **) * 11);
	cn = init(cn, stack_a, temp);
	i = 0;
	while (stack_a->size > (5))
	{
		hold_first_num(stack_a, cn, j);
		hold_second_num(stack_a, cn, j);
		i = moves_for_first(stack_a);
		c = moves_for_second(stack_a);
		if ((stack_a->size - c) > i)
		{	
			min_max_val(stack_b);
			moves_count_min_max(stack_b, stack_b->min);
			if ((stack_b->min > stack_a->size / 2) && stack_a->hlf > (stack_b->size / 2))
			{
				while (stack_b->stack[0] != stack_b->min && stack_a->stack[0] != stack_a->hlf)
				{
					rev_ra_rb(stack_a, stack_b);
				}
			}
			i = moves_for_first(stack_a);
			if ((stack_b->min < (stack_a->size / 2) && stack_a->hlf < (stack_b->size / 2)))
			{
				while (stack_b->stack[0] != stack_b->min && stack_a->stack[0] != stack_a->hlf)
				{
					//printf("okkkkkkkk\n");
					ra_rb(stack_a, stack_b);
				}
			}
			i = moves_for_first(stack_a);
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
		min_max_val(stack_b);
		if (stack_b->size < 1)
			push_to_b(stack_a, stack_b);
		else if (stack_a->stack[0] < stack_b->min || stack_a->stack[0] > stack_b->max)
		{
			while (stack_b->stack[0] != stack_b->min)
			{
				moves_count_min_max(stack_b, stack_b->min);
				if (stack_b->i_min > (stack_b->size / 2))
					rev_rb(stack_b);
				else
					rotate_b(stack_b);
			}
			push_to_b(stack_a, stack_b);
		}
		else 
		{
			sec = shiva(temp, stack_a, stack_b);
			while (stack_b->stack[0] != sec)
			{
				moves_count_min_max(stack_b, sec);
				if (stack_b->i_min > (stack_b->size / 2))
					rev_rb(stack_b);
				else
					rotate_b(stack_b);
			}
			push_to_b(stack_a, stack_b);

		}
		if (stack_b->size == 45)
			j++;
		if (stack_b->size == 90)
			j++;
		if (stack_b->size == 135)
			j++;
		if (stack_b->size == 180)
			j++;
        if (stack_b->size == 225)
			j++;
        if (stack_b->size == 270)
			j++;
        if (stack_b->size == 315)
			j++;
        if (stack_b->size == 360)
			j++;
        if (stack_b->size == 405)
			j++;
        if (stack_b->size == 450)
			j++;
	}
	i = 0;
	min_max_val(stack_b);
	if (stack_a->size == 5)
		five_guys(stack_a, stack_b);
	while (stack_b->stack[0] != stack_b->max)
	{
		rotate_b(stack_b);
	}
	if (stack_b->stack[0] == stack_b->max)
	{
		push_to_a(stack_a, stack_b);
	}
	while (stack_b->size > 0)
	{
		rev_rb(stack_b);
		push_to_a(stack_a, stack_b);
	}
	print_st(stack_a);	
}

	// if ((stack_b->min > stack_a->size / 2) && stack_a->hlf > (stack_b->size / 2))
	// 		{
	// 			while (stack_b->stack[0] != stack_b->min && stack_a->stack[0] != stack_a->hlf)
	// 			{
	// 				//printf("okkkkkkkk\n");
	// 				rev_ra_rb(stack_a, stack_b);
	// 			}
	// 		}
	// 		i = moves_for_first(stack_a);
	// 		if ((stack_b->min < stack_a->size / 2) && stack_a->hlf < (stack_b->size / 2))
	// 		{
	// 			while (stack_b->stack[0] != stack_b->min && stack_a->stack[0] != stack_a->hlf)
	// 			{
	// 				//printf("okkkkkkkk\n");
	// 				ra_rb(stack_a, stack_b);
	// 			}
	// 		}