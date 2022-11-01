/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:06:16 by mardolin          #+#    #+#             */
/*   Updated: 2022/10/30 15:58:20 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int		*stack;
	int		size;
	char	id;
	int		max;
	int		min;
	int		i_max;
	int		i_min;
	int		k;
	int		hlf;
	int		hls;
	int		mv_first;
	int		mv_second;
	int		j;
	int		sec;
	int		i;
	int		c;
	int		*temp;
	int		**cn;

}			t_stack;

typedef struct s_chunk
{
	int		*cnk_1;
	int		*cnk_2;
	int		*cnk_3;
	int		*cnk_4;
	int		*cnk_5;
}		t_chunk;

void	mmove_b(t_stack *stack_a, t_stack *stack_b, t_stack *temp);
void	endmmove(t_stack *stack_a, t_stack *stack_b, t_stack *temp, int **cn);
void	find_n_set_a(t_stack *stack_a, int **cn, int j);
void	pushing(t_stack *stack_b);
void	move_ghelper(t_stack *stack_a, t_stack *stack_b);
void	chunck_index_increment(t_stack *stack_b);
int		ordered_int(t_stack *stack);
int		check_stack(t_stack *stack);
int		shiva_cin(t_stack *temp, t_stack *stack_a, t_stack *stack_b);
void	moves_count_min_max_cin(t_stack *stack, int num);
char	**ft_split(const char *s, char c);
int		get_word(const char *s, char c);
char	*ft_substr(const char *s, int start, int len);
char	*ft_strdup(const char *s);
int		ft_strlen(char *str);
void	min_max_val(t_stack *s);
void	secondmin(t_stack *s);
int		**init(int **chunk, t_stack *stack_a, t_stack *temp);
void	sort(t_stack *stack_a, t_stack *stack_b, t_stack *temp);
int		ft_atoi(const char *str);
void	ft_ordered(t_stack *stack_a);
void	ft_equals(t_stack *stack_a);
int		isdigits(char *arg);
void	check_dig(char **arg);
int		check_dig2(char **arg);
int		ft_space(char *arg);
void	swap_a(t_stack *stack_a);
void	swap_b(t_stack *stack_b);
void	swap_a_b(t_stack *stack_a, t_stack *stack_b);
int		push_to(t_stack *dest, t_stack *src);
void	push_to_a(t_stack *stack_a, t_stack *stack_b);
void	push_to_b(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack);
void	rotate_b(t_stack *stack_b);
void	rotate_a(t_stack *stack_a);
void	reverse_rotate(t_stack *stack);
void	rev_rb(t_stack *stack_b);
void	rev_ra(t_stack *stack_a);
void	rev_ra_rb(t_stack *stack_a, t_stack *stack_b);
void	ra_rb(t_stack *stack_a, t_stack *stack_b);
void	three_guys(t_stack *stack);
void	min_val(t_stack *stack);
void	five_guys(t_stack *stack, t_stack *stack_b);
void	print_st(t_stack *stack);
void	four_guys(t_stack *stack_a, t_stack *stack_b);
int		init_struct(t_stack *stack_a, t_stack *stack_b);
void	checker_one(t_stack *stack_a, t_stack *stack_b, char **argv);
void	checker_two(t_stack *stack_a, t_stack *stack_b, int argc, char **argv);
void	sortea(t_stack *stack_a, t_stack *stack_b);
int		mov_stack_b(t_stack *stack_a, t_stack *stack_b, t_stack *temp);
int		size(t_stack *stack_a, t_stack *stack_b);
int		base_moves(t_stack *stack_a);
int		init_temp(t_stack *temp);
int		check_first(int **chunk, t_stack *temp);
int		check_second(int **chunk, t_stack *temp);
int		check_chunk(int **chunk, t_stack *temp);
void	moves_count_min_max(t_stack *stack, int num);
int		shiva(t_stack *temp, t_stack *stack_a, t_stack *stack_b);
int		moves_for_first(t_stack *stack_a);
int		moves_for_second(t_stack *stack_a);
int		*loader_int(char **argv, t_stack *stack_a, int i, int c);
void	sortc(t_stack *stack_a, t_stack *stack_b, t_stack *temp);
void	hold_first_num(t_stack *stack_a, int **cn, int j);
void	hold_second_num(t_stack *stack_a, int **cn, int j);
void	checkss(t_stack *stack_a, t_stack *temp);

#endif