/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:40:26 by mardolin          #+#    #+#             */
/*   Updated: 2022/11/02 17:46:07 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

void	checkss(t_stack *stack_a, t_stack *temp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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

int	check_first(int **chunk, t_stack *temp)
{
	if (temp->i < 20)
		chunk[temp->c][temp->j] = temp->stack[temp->i];
	else if (temp->i > 19 && temp->i < 40)
	{
		if (temp->i == 20)
		{
			temp->j = 19;
			temp->c--;
		}
		chunk[temp->c][temp->j] = temp->stack[temp->i];
	}
	else if (temp->i > 39 && temp->i < 60)
	{
		if (temp->i == 40)
		{
			temp->j = 19;
			temp->c--;
		}
		chunk[temp->c][temp->j] = temp->stack[temp->i];
	}
	return (1);
}

int	check_second(int **chunk, t_stack *temp)
{
	if (temp->i > 59 && temp->i < 80)
	{
		if (temp->i == 60)
		{
			temp->j = 19;
			temp->c--;
		}
		chunk[temp->c][temp->j] = temp->stack[temp->i];
	}
	else if (temp->i > 79 && temp->i < 100)
	{
		if (temp->i == 80)
		{
			temp->j = 19;
			temp->c--;
		}
		chunk[temp->c][temp->j] = temp->stack[temp->i];
	}
	temp->i++;
	temp->j--;
	return (1);
}

int	check_chunk(int **chunk, t_stack *temp)
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
	check_chunk(chunk, temp);
	return (chunk);
}
