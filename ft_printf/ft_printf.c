/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:49:13 by mtoia             #+#    #+#             */
/*   Updated: 2022/04/04 15:41:43 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_type(va_list args, const char type)
{
	int	ret_prit;

	ret_prit = 0;
	if (type == 'c')
		ret_prit += ft_putchar(va_arg(args, int));
	else if (type == 's')
		ret_prit += ft_putstr(va_arg(args, char *));
	else if (type == 'p')
		ret_prit += ft_ptr(va_arg(args, unsigned long long));
	else if (type == 'd')
		ret_prit += ft_printnbr(va_arg(args, int));
	else if (type == 'i')
		ret_prit += ft_printnbr(va_arg(args, int));
	else if (type == 'u')
		ret_prit += ft_print_unsigned(va_arg(args, int));
	else if (type == 'x' || type == 'X')
		ret_prit += ft_print_hex(va_arg(args, unsigned int), type);
	else if (type == '%')
		ret_prit += ft_percent();
	return (ret_prit);
}

int	ft_printf(const char *str, ...)
{
	int		flg;
	int		ret_prit;
	va_list	arg;

	flg = 0;
	ret_prit = 0;
	va_start (arg, str);
	while (str[flg])
	{
		if (str[flg] == '%')
		{
			ret_prit += ft_type(arg, str[flg + 1]);
			flg++;
		}
		else
			ret_prit += ft_putchar(str[flg]);
		flg++;
	}
	va_end(arg);
	return (ret_prit);
}
