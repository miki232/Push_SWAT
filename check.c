/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:14:31 by mtoia             #+#    #+#             */
/*   Updated: 2022/10/31 14:51:43 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_ordered(t_stack *stack_a)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (stack_a->stack[i] < stack_a->stack[j])
	{
		i++;
		j++;
		if ((i + 1) == (stack_a->size))
		{
			printf("Ordered");
			exit(0);
		}
	}
}

void	ft_equals(t_stack *stack_a)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < stack_a->size)
	{
		while (j < stack_a->size)
		{
			if (stack_a->stack[i] == stack_a->stack[j])
			{
				printf("equals\n");
				exit(0);
			}
			j++;
		}
		i++;
		j = 1 + i;
	}
}

int	isdigits(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if ((arg[i] > 47 && arg[i] < 58) || arg[i] == 45 || arg[i] == 43)
			i++;
		else
		{
			printf("ERROR");
			exit(0);
		}
	}
	return (1);
}

int	ft_space(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ordered_int(t_stack *stack)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (stack->stack[i] < stack->stack[j])
	{
		i++;
		j++;
		if ((i + 1) == (stack->size))
		{
			return (0);
		}
	}
	return (1);
}
