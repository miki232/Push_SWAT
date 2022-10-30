/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aldo_ritmo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:32:58 by mtoia             #+#    #+#             */
/*   Updated: 2022/10/30 14:07:55 by mardolin         ###   ########.fr       */
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
				//printf("%d\n", s->min);
				return ;
			}
			i++;
		}
	}
}

void	sortea(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	c;
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

void	printcn(int **chunk, int c)
{
	int	i = 0;
	while (i < 20)
	{
		printf("Al chunck[%d][%d] = %d \n", c, i, chunk[c][i]);
		i++;
	}
	
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

int check_first(int **chunk, t_stack *temp)
{
	if (temp->i < 20)
		chunk[temp->c][temp->j] = temp->stack[temp->i];
	else if (temp->i > 19 && temp->i < 40)
	{
		if(temp->i == 20)
		{
			temp->j = 19;
			temp->c--;
		}
		chunk[temp->c][temp->j] = temp->stack[temp->i];
	}
	else if (temp->i > 39 && temp->i < 60)
	{
		if(temp->i == 40)
		{
			temp->j = 19;
			temp->c--;
		}
		chunk[temp->c][temp->j] = temp->stack[temp->i];
	}
	return (1);
}

int check_second(int **chunk, t_stack *temp)
{
	if (temp->i > 59 && temp->i < 80)
	{
		if(temp->i == 60)
		{
			temp->j = 19;
			temp->c--;
		}
		chunk[temp->c][temp->j] = temp->stack[temp->i];
	}
	else if (temp->i > 79 && temp->i < 100)
	{
		if(temp->i == 80)
		{
			temp->j = 19;
			temp->c--;
		}
		chunk[temp->c][temp->j] = temp->stack[temp->i];
	}
	temp->i++;
	temp->j--;
	return (0);
}

int check_chunk(int **chunk, t_stack *temp)
{
	init_temp(temp);
	while (temp->i < 100)
	{
		check_first(chunk, temp);
		check_second(chunk, temp);
	}
	return (1);
}

int	**init(int **chunk, t_stack *stack_a, t_stack *temp)
{
	temp->id = 't';
	temp->stack = malloc(sizeof(int) * stack_a->size);
	temp->size = stack_a->size;
	while (stack_a->i < 5)
	{
		chunk[stack_a->i] = malloc(sizeof(int *) * 20);
		stack_a->i++;
	}
	checkss(stack_a, temp);
	//print_st(&temp);
	check_chunk(chunk, temp);
	//printcn(chunk, 4);
	return (chunk);
}

void	calc_moves(t_stack *stack)
{
	while (stack->stack[stack->i] != stack->min)
		stack->i++;
	while (stack->stack[stack->c] != stack->max)
		stack->c++;
	if	(stack->i > stack->size / 2 && stack->c > stack->size / 2)
	{
			stack->i_max = (stack->size - stack->c);
			stack->i_min = (stack->size - stack->i);
	}
	else if	(stack->i < stack->size / 2 && stack->c < stack->size / 2)
	{
			stack->i_max = stack->c;
			stack->i_min = stack->i;
	}
	else if	(stack->i < stack->size / 2 && stack->c > stack->size / 2)
	{
			stack->i_max = (stack->size - stack->c);
			stack->i_min = stack->i;
	}
	else if	(stack->i > stack->size / 2 && stack->c < stack->size / 2)
	{
			stack->i_max = stack->c;
			stack->i_min = (stack->size - stack->i);
	}
}

int	shiva(t_stack *temp, t_stack *stack_a, t_stack *stack_b)
{
	int i;
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

// int	secmin(t_stack *temp, t_stack *stack_a, t_stack *stack_b)
// {

// }

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
	int s;
	
	c = 0;
	s = 1;
	i = stack_a->size - 1;
	while (i >= 0 && s)
	{
		c = 0;
		while ((stack_a->stack[i] != cn[j][c] || stack_a->stack[i] == cn[j][c]) && c < 20)
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

void	f_ra_rb(t_stack *stack_a, t_stack *stack_b, t_stack *temp)
{
	if (stack_a->hlf < stack_b->min || stack_a->hlf > stack_b->max)
	{
		if (stack_b->stack[0] != stack_b->max && stack_a->stack[0] != stack_a->hlf)
		{
			moves_count_min_max(stack_b, stack_b->max);
			while (stack_b->i_min < (stack_b->size / 2) && stack_a->stack[0] != stack_a->hlf && stack_b->stack[0] != stack_b->max)
			{
				ra_rb(stack_a, stack_b);
				stack_a->i--;
			}
		}					
	}
	else
	{
		stack_a->sec = shiva(temp, stack_a, stack_b);
		if (stack_b->stack[0] != stack_a->sec && stack_a->stack[0] != stack_a->hlf)
		{
			moves_count_min_max(stack_b, stack_a->sec);
			while (stack_b->i_min < (stack_b->size / 2) && stack_a->stack[0] != stack_a->hlf && stack_b->stack[0] != stack_a->sec)
			{
				ra_rb(stack_a, stack_b);
				stack_a->i--;
			}
		}
	}		
}

void	f(t_stack *stack_a, t_stack *stack_b, t_stack *temp)
{
	while (stack_a->i > 0)
	{
		min_max_val(stack_b);
		if (stack_b->size > 1)
		{
			f_ra_rb(stack_a, stack_b, temp);
		}
		if(stack_a->stack[0] != stack_a->hlf)
			rotate_a(stack_a);
		stack_a->i--;
	}
}

void	f_rev(t_stack *stack_a, t_stack *stack_b, t_stack *temp)
{
	if (stack_a->hls < stack_b->min || stack_a->hls > stack_b->max)
	{
		if (stack_b->stack[0] != stack_b->max && stack_a->stack[0] != stack_a->hls)
		{
			moves_count_min_max(stack_b, stack_b->max);
			while (stack_b->i_min > (stack_b->size / 2) && stack_a->stack[0] != stack_a->hls && stack_b->stack[0] != stack_b->max)
			{
				//printf("okkkkk\n");
				rev_ra_rb(stack_a, stack_b);
				stack_a->c++;
			}
		}
	}
	else
	{
		stack_a->sec = shiva(temp, stack_a, stack_b);
		// printf("stackb = %d, SEC = %d  HLS = %d\n", stack_b->stack[0], sec, stack_a->hlf);
		// print_st(stack_b);
		if (stack_b->stack[0] != stack_a->sec && stack_a->stack[0] != stack_a->hls)
		{
			moves_count_min_max(stack_b, stack_a->sec);
			while (stack_a->c < stack_a->size && stack_b->i_min > (stack_b->size / 2) && stack_a->stack[0] != stack_a->hls && stack_b->stack[0] != stack_a->sec)
			{
				printf("HLS = %d\n",stack_a->sec);
				moves_count_min_max(stack_b, stack_a->sec);
				rev_ra_rb(stack_a, stack_b);
				stack_a->c++;
			}
			//printf("okkkkk\n");
		}
	}
}

void	g(t_stack *stack_a, t_stack *stack_b, t_stack *temp)
{
	while (stack_a->c < stack_a->size)
	{
		min_max_val(stack_b);
		if (stack_b->size > 1)
			f_rev(stack_a, stack_b, temp);
	}
}

int mov_push(t_stack *stack_a, t_stack *stack_b, t_stack *temp)
{
	stack_a->sec = shiva(temp, stack_a, stack_b);
	//printf("stackb = %d, SEC = %d  HLS = %d\n", stack_b->stack[0], sec, stack_a->hls);
	// print_st(stack_b);
	while (stack_b->stack[0] != stack_a->sec)
	{
		moves_count_min_max(stack_b, stack_a->sec);
		if (stack_b->i_min > (stack_b->size / 2))
			rev_rb(stack_b);
		else
			rotate_b(stack_b);
	}
	push_to_b(stack_a, stack_b);
	return (1);
}

int h(t_stack *stack_a, t_stack *stack_b, t_stack *temp)
{
	if (stack_b->size < 1)
			push_to_b(stack_a, stack_b);
	else if (stack_a->stack[0] < stack_b->min || stack_a->stack[0] > stack_b->max)
	{
		while (stack_b->stack[0] != stack_b->max)
		{
			moves_count_min_max(stack_b, stack_b->max);
			if (stack_b->i_min > (stack_b->size / 2))
				rev_rb(stack_b);
			else
				rotate_b(stack_b);
		}
		push_to_b(stack_a, stack_b);
	} 
	else  ////calcolare quanto costa il movimento in di entrambi numeri in a (hlf, hls)compresi i  movimenti in b
		mov_push(stack_a, stack_b, temp);
	return (1);
}

int base_moves(t_stack *stack_a, t_stack *stack_b)
{
	if ((stack_a->size - stack_a->c) > stack_a->i)
	{
		while (stack_a->i > 0)
		{
			rotate_a(stack_a);
			 stack_a->i--;
		}
	}
	else
	{
		while (stack_a->c < stack_a->size)
		{
			rev_ra(stack_a);
			 stack_a->c++;
		}	
	}
	return 1;
}

int size(t_stack *stack_a, t_stack *stack_b)
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

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int **cn;
	t_stack temp;
	
	min_max_val(stack_a);
	cn = malloc(sizeof(int **) * 5);
	cn = init(cn, stack_a, &temp);
	while (stack_a->size > (0))
	{
		hold_first_num(stack_a, cn, stack_a->j);
		hold_second_num(stack_a, cn, stack_a->j);
		stack_a->i = moves_for_first(stack_a);
		stack_a->c = moves_for_second(stack_a);
		base_moves(stack_a, stack_b);
		// if ((stack_a->size - stack_a->c) > stack_a->i)
		// {
		// 	// printf("okk\n");
		// 	f(stack_a, stack_b, &temp);
		// 	// printf("kk\n");
		// }
		// else
		// {
		// 	g(stack_a, stack_b, &temp);
		// 	// printf("okk\n");
		// }
		// printf("hls = %d  hlf = %d\n stack_a[0] %d\n", stack_a->hls, stack_a->hlf, stack_a->stack[0]);
		// print_st(stack_b);
		min_max_val(stack_b);
		h(stack_a, stack_b, &temp);
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
	// while (stack_b->stack[0] == stack_b->max && stack_b->size > 0)
	// {
	// 	push_to_a(stack_a, stack_b);
	// 	min_max_val(stack_b);
	// }
	// while (stack_b->stack[0] != stack_b->max)
	// {
	// 	rotate_b(stack_b);
	// }
	// if (stack_b->stack[0] == stack_b->max)
	// {
	// 	push_to_a(stack_a, stack_b);
	// }
	// while (stack_b->size > 0)
	// {
	// 	rev_rb(stack_b);
	// 	push_to_a(stack_a, stack_b);
	// }
	// print_st(stack_b);
	// print_st(stack_a);
}