/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:32:58 by mtoia             #+#    #+#             */
/*   Updated: 2022/11/04 16:26:33 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "get_next_line/get_next_line.h"

typedef struct s_stack
{
	int		e;
	int		j;
	int		k;
	int		i;
	int		c;
	char	id;
	int		hls;
	int		hlf;
	int		sec;
	int		**cn;
	int		max;
	int		min;
	int		size;
	int		i_max;
	int		i_min;
	int		*temp;
	int		*stack;
	int		mv_first;
	int		mv_second;
}			t_stack;

char	**ft_split(const char *s, char c);
int		ft_atoi(const char *str);
void	check_dig(char **arg);
int		check_dig2(char **arg);
void	print_st(t_stack *stack);
int		has_spaces(char *str);
void	ft_equals(t_stack *stack_a);
int		isdigits(char *arg);
int		ft_space(char *arg);
int		ft_strcmp(char *strg1, char *strg2);
void	rev_ra(t_stack *stack_a);
void	rev_rb(t_stack *stack_b);
void	rev_ra_rb(t_stack *stack_a, t_stack *stack_b);
void	rotate_a(t_stack *stack_a);
void	rotate_b(t_stack *stack_b);
void	ra_rb(t_stack *stack_a, t_stack *stack_b);
void	swap_a(t_stack *stack_a);
void	swap_b(t_stack *stack_b);
void	swap_a_b(t_stack *stack_a, t_stack *stack_b);
void	push_to_a(t_stack *stack_a, t_stack *stack_b);
void	push_to_b(t_stack *stack_a, t_stack *stack_b);
int		ft_ordered(t_stack *stack_a);
void	checker_one(t_stack *stack_a, t_stack *stack_b, char **argv);
void	checker_two(t_stack *stack_a, t_stack *stack_b, int argc, char **argv);
char	**read_move(int size);
int		char_array_len(char **str);

#endif