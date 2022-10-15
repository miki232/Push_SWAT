/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:06:16 by mtoia             #+#    #+#             */
/*   Updated: 2022/10/15 17:52:00 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_H
# define PUSH_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>



char		**ft_split(const char *s, char c);
int			get_word(const char *s, char c);
char		*ft_substr(const char *s, int start, int len);
char		*ft_strdup(const char *s);
int			ft_strlen(char *str);
int			ft_atoi(const char *str);
void		ft_ordered(int *array, int argc);
void		ft_equals(int *array, int argc);
int			isdigits(char *arg);
void   check_dig(char **arg);
int   check_dig2(char **arg);
int		ft_space(char *arg);
#endif