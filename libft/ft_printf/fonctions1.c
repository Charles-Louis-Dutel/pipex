/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:29:15 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/17 15:38:18 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = 0;
	while (s[i])
	{
		i += ft_putchar(s[i]);
	}
	return (i);
}

int	ft_putnbr(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += ft_putchar('-');
		n = -n;
	}
	if (n <= 9)
	{
		i += ft_putchar(n + '0');
	}
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	return (i);
}

int	ft_convert_hexa(unsigned long long n)
{
	char	*hexabase;
	int		i;

	i = 0;
	hexabase = "0123456789abcdef";
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

int	ft_convert_hexa_maj(unsigned long long n)
{
	char	*hexa_maj;
	int		i;

	i = 0;
	hexa_maj = "0123456789ABCDEF";
	if (n < 16)
	{
		i += ft_putchar(hexa_maj[n]);
	}
	if (n >= 16)
	{
		i += ft_convert_hexa_maj(n / 16);
		i += ft_convert_hexa_maj(n % 16);
	}
	return (i);
}
