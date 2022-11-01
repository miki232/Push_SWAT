/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 01:25:33 by mtoia             #+#    #+#             */
/*   Updated: 2022/05/02 12:02:28 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	halo(long nb)
{
	int	len;
	int	mod;

	len = 1;
	mod = 1;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb / mod > 9)
	{
		mod *= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int num)
{
	char	*str;
	long	n;
	int		cfr;

	n = num;
	cfr = halo(n);
	str = ft_calloc(cfr + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[cfr--] = '\0';
	if (n == 0)
		str[0] = 48;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[cfr] = 48 + (n % 10);
		n = n / 10;
		cfr--;
	}
	return (str);
}
