/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aldo_ritmo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:32:58 by mtoia             #+#    #+#             */
/*   Updated: 2022/10/19 18:48:58 by mtoia            ###   ########.fr       */
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
			s->max = s->stack[i];
		if (s->min > s->stack[i])
			s->min = s->stack[i];
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
	chunk = malloc(sizeof(int **) * 5);
	while (i < 5)
	{
		chunk[i] = malloc(sizeof(int *) * 20);
		i++;
	}
	checkss(stack_a, temp);
	i = 0;
	//print_st(&temp);
	int c = 0;
	while (i < 100)
	{
		if (i < 20)
			chunk[c][j] = temp->stack[i];
		else if (i > 19 && i < 40)
		{
			if(i == 20)
			{
				j = 0;
				c++;
			}
			chunk[c][j] = temp->stack[i];
			//printf("c%d\n", j);
		}
		else if (i > 39 && i < 60)
		{
			if(i == 40)
			{
				j = 0;
				c++;
			}
			chunk[c][j] = temp->stack[i];
		}
		else if (i > 59 && i < 80)
		{
			if(i == 60)
			{
				j = 0;
				c++;
			}
			chunk[c][j] = temp->stack[i];
		}
		else if (i > 79 && i < 100)
		{
			if(i == 80)
			{
				j = 0;
				c++;
			}
			chunk[c][j] = temp->stack[i];
		}
		i++;
		j++;
	}
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

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int	c = 0;
	int	hlf = 0;
	int	s = 1;
	int	j = 0;
	int	hls = 0;
	int	sec = 0;
	int **cn;
	t_stack temp;
	
	min_max_val(stack_a);
	cn = init(cn, stack_a, &temp);
	i = 0;
	while (stack_a->size > (0))
	{
		while (i < stack_a->size && s)
		{
			c = 0;
			//printf("sssssdshjkdsvfhjkds %d\n", cn[j][c]);
			while (stack_a->stack[i] != cn[j][c] && c < 20)
			{
				c++;
				if (stack_a->stack[i] == cn[j][c])
				{
					hlf = stack_a->stack[i];
					s = 0;
				}
			}
			i++;
		}
		s = 1;
		i = stack_a->size - 1;
		while (i > 0 && s)
		{
			c = 0;
			while ((stack_a->stack[i] != cn[j][c] || stack_a->stack[i] == cn[j][c]) && c < 20)
			{
				if (stack_a->stack[i] == cn[j][c])
				{
					hls = stack_a->stack[i];
					s = 0;
				}
				c++;
			}
			i--;
		}
		i = 0;
		while (stack_a->stack[i] != hlf)
				i++;
		c = stack_a->size - 1;
		while (stack_a->stack[c] != hls || stack_a->stack[c] == hls)
		{
			if (stack_a->stack[c] == hls)
			{
				break ;
			}
			c--;
		}
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
		min_max_val(stack_b);
		if (stack_b->size < 1)
			push_to_b(stack_a, stack_b);
		else if (stack_a->stack[0] < stack_b->min || stack_a->stack[0] > stack_b->max)
		{
			//printf("%d %d\n", stack_b->min, stack_b->max);
			while (stack_b->stack[0] != stack_b->min)
			{
				rotate_b(stack_b);
				// check_move();
			}
			push_to_b(stack_a, stack_b);
		}
		else 
		{
			sec = shiva(&temp, stack_a, stack_b);
			while (stack_b->stack[0] != sec)
			{
				rotate_b(stack_b);
			}
			push_to_b(stack_a, stack_b);

		}
		if (stack_b->size == 20)
			j++;
		if (stack_b->size == 40)
			j++;
		if (stack_b->size == 60)
			j++;
		if (stack_b->size == 80)
			j++;
	}
	i = 0;
	min_max_val(stack_b);
	while (stack_b->stack[0] != stack_b->max)
		rotate_b(stack_b);
	if (stack_b->stack[0] == stack_b->max)
		push_to_a(stack_a, stack_b);
	while (stack_b->size > 0)
	{
		rev_rb(stack_b);
		push_to_a(stack_a, stack_b);
	}
	print_st(stack_a);	
}