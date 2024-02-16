/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:25:30 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/19 10:36:42 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n <= 9)
	{
		i += ft_putchar(n + '0');
	}
	if (n > 9)
	{
		i += ft_putnbr_unsigned(n / 10);
		i += ft_putnbr_unsigned(n % 10);
	}
	return (i);
}

int	ft_convert_adress(unsigned long long n)
{
	char	*hexabase;
	int		i;

	if (!n)
	{
		ft_putstr("(nil)");
		return (5);
	}
	i = 0;
	hexabase = "0123456789abcdef";
	ft_putchar('0');
	ft_putchar('x');
	i += 2;
	if (n < 16)
	{
		i += ft_putchar(hexabase[n]);
	}
	if (n >= 16)
	{
		i += ft_convert_hexa(n / 16);
		i += ft_convert_hexa(n % 16);
	}
	return (i);
}

int	ft_slen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
