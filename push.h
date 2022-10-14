/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:06:16 by mtoia             #+#    #+#             */
/*   Updated: 2022/10/14 18:24:10 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_H
# define PUSH_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>


char	**ft_split(const char *s, char c);
int	get_word(const char *s, char c);
char	*ft_substr(const char *s, int start, int len);
char	*ft_strdup(const char *s);
int	ft_strlen(char *str);
int	ft_atoi(const char *str);

#endif