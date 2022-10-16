/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:06:16 by mtoia             #+#    #+#             */
/*   Updated: 2022/10/16 19:52:04 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_H
# define PUSH_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef	struct s_stack
{
	int		*stack;
	int		size;
	char	id;
	int		max;
	int 	min;
}			t_stack;


char		**ft_split(const char *s, char c);
int			get_word(const char *s, char c);
char		*ft_substr(const char *s, int start, int len);
char		*ft_strdup(const char *s);
int			ft_strlen(char *str);
int			ft_atoi(const char *str);
void		ft_ordered(t_stack *stack_a);
void		ft_equals(t_stack *stack_a);
int			isdigits(char *arg);
void   		check_dig(char **arg);
int  		check_dig2(char **arg);
int			ft_space(char *arg);
void		swap_a(t_stack *stack_a);
void		swap_b(t_stack *stack_b);
void		swap_a_b(t_stack *stack_a, t_stack *stack_b);
int			push_to(t_stack *dest, t_stack *src);
void		push_to_a(t_stack *stack_a, t_stack *stack_b);
void		push_to_b(t_stack *stack_a, t_stack *stack_b);
void		rotate(t_stack *stack);
void		rotate_b(t_stack *stack_b);
void		rotate_a(t_stack *stack_a);
void		reverse_rotate(t_stack *stack);
void		rev_rb(t_stack *stack_b);
void		rev_ra(t_stack *stack_a);
void		rev_ra_rb(t_stack *stack_a, t_stack *stack_b);
void		ra_rb(t_stack *stack_a, t_stack *stack_b);
void		three_guys(t_stack *stack);
void		min_val(t_stack *stack);
void		five_guys(t_stack *stack, t_stack *stack_b);
void   		print_st(t_stack *stack);
void		four_guys(t_stack *stack_a, t_stack *stack_b);


#endif