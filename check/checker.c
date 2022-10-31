/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:32:58 by mtoia             #+#    #+#             */
/*   Updated: 2022/10/29 20:09:04 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	init_struct(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size = 0;
	stack_b->size = 0;
	stack_a->id = 'a';
	stack_b->id = 'b';
	// stack_b->stack[0] = 4;
	stack_b->size = 0;
	return (0);
}

void	checker_one(t_stack *stack_a, t_stack *stack_b, char **argv)
{
	char	**arg;

	init_struct(stack_a, stack_b);
	arg = ft_split(argv[1], ' ');
	stack_a->size = check_dig2(arg);
	loader_int(arg, stack_a, 0, 0);
	stack_b->stack = malloc(sizeof(int) * stack_a->size);
	ft_equals(stack_a);
	ft_ordered(stack_a);
}

void	checker_two(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	init_struct(stack_a, stack_b);
	check_dig(argv);
	stack_a->size = argc - 1;
	stack_a->k = 0;
	stack_b->k = 0;
	stack_b->stack = malloc(sizeof(int) * stack_a->size);
	loader_int(argv, stack_a, 1, 1);
	ft_equals(stack_a);
	ft_ordered(stack_a);
}

char  **read_move(int size)
{
    char **moves;
    int i;
    
	i = 0;
    moves = malloc(size * sizeof(char *));
    while (1)
    {
        moves[i] = malloc(4 * sizeof(char));
        moves[i] = get_next_line(0);
		//printf("ok\n");
		if (moves[i] == NULL)
		{
    	//	printf("%s", moves[0]);
			free(moves[i]);
			break ;
		}
        i++;
    }
    return (moves);
}

int	char_array_len(char **str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len] != NULL)
		len++;
	return (len);
}

void	run_2_move(t_stack *stack_a, t_stack *stack_b, char *moves)
{
	if (!ft_strcmp(moves, "ra\n"))
		rotate_a(stack_a);
	else if (!ft_strcmp(moves, "rb\n"))
		rotate_b(stack_a);
	else if (!ft_strcmp(moves, "rra\n"))
		rev_ra(stack_a);
	else if (!ft_strcmp(moves, "rrb\n"))
		rev_rb(stack_b);
	else if (!ft_strcmp(moves, "ss\n"))
		swap_a_b(stack_a, stack_b);
	else if (!ft_strcmp(moves, "rr\n"))
		ra_rb(stack_a, stack_b);
	else if (!ft_strcmp(moves, "rrr\n"))
		rev_ra_rb(stack_a, stack_b);
}

void	run_moves(t_stack *stack_a, t_stack *stack_b, char **moves)
{
	int j;

	j = 0;
	//printf("%s\n", moves[0]);
	while (j < char_array_len(moves))
	{
		if (!ft_strcmp(moves[j], "pb\n"))
			push_to_b(stack_a, stack_b);
		else if (!ft_strcmp(moves[j], "pa\n"))
			push_to_a(stack_a, stack_b);
		else if (!ft_strcmp(moves[j], "sa\n"))
			swap_a(stack_a);
		else if (!ft_strcmp(moves[j], "sb\n"))
			swap_b(stack_b);
		else
			run_2_move(stack_a, stack_a, moves[j]);
		j++;
	}
	
}

void	check_move(t_stack *stack_a, t_stack *stack_b, char **moves)
{
	run_moves(stack_a, stack_b, moves);
	if (ft_ordered(stack_a))
		printf("OK\n");
	else
		printf("KO\n");
}

int main(int argc, char **argv)
{
    t_stack	stack_a;
	t_stack	stack_b;
    char **moves;
	
	if (argc < 2)
	{
		exit(0);
	}
	if (ft_space(argv[1]))
		checker_one(&stack_a, &stack_b, argv);
	else
		checker_two(&stack_a, &stack_b, argc, argv);
	print_st(&stack_a);
    moves = read_move(stack_a.size);
	check_move(&stack_a, &stack_b, moves);
	print_st(&stack_a);
    //printf("%s", moves[0]);
}

