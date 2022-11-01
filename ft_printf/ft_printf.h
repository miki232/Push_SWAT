/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:21:07 by mtoia             #+#    #+#             */
/*   Updated: 2022/03/30 11:09:01 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_strlen(const char *str);
int		ft_putstr(char *str);
char	*ft_itoa(int num);
int		ft_printnbr(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_putchar(char c);
int		ft_print_hex(unsigned int num, const char format);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *dst, int n);
void	*ft_memset(void *str, int c, int n);
void	ft_putchar_fd(char c, int fd);
int		ft_percent(void);
int		ft_ptr(unsigned long long ptr);
void	*ft_memcpy(void *dest, const void *source, size_t num);

#endif