/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_diese.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:45:18 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/23 19:27:37 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_0xhexa(unsigned long long n)
{
	char	*hexabase;
	int		i;

	if (n == 0)
		return (ft_putchar('0'));
	i = 0;
	hexabase = "0123456789abcdef";
	i += ft_putchar('0');
	i += ft_putchar('x');
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

int	ft_convert_0xmajhexa(unsigned long long n)
{
	char	*hexabase;
	int		i;

	if (n == 0)
		return (ft_putchar('0'));
	i = 0;
	hexabase = "0123456789ABCDEF";
	i += ft_putchar('0');
	i += ft_putchar('X');
	if (n < 16)
	{
		i += ft_putchar(hexabase[n]);
	}
	if (n >= 16)
	{
		i += ft_convert_hexa_maj(n / 16);
		i += ft_convert_hexa_maj(n % 16);
	}
	return (i);
}

int	ft_calcul_length_hexa(unsigned long long n)
{
	int		i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 16)
	{
		i++;
	}
	if (n >= 16)
	{
		i += ft_calcul_length_hexa(n / 16);
		i += ft_calcul_length_hexa(n % 16);
	}
	return (i);
}

int	ft_fonctions_diese(char *s, va_list args)
{
	unsigned long long	i;
	int					n;

	i = 0;
	n = 0;
	while (s[i] == '#' || s[i] == ' ' || s[i] == '+' || s[i] == '0'
		|| s[i] == '-' || s[i] == '.')
		i++;
	if (s[i] >= '0' && s[i] <= '9')
		n = ft_calcul_space(&s[i]);
	if (s[0 + ft_check_width(s)] == 'x')
	{
		i = va_arg(args, unsigned);
		n = ft_add_space(n - (ft_calcul_length_hexa(i) + 2));
		return (ft_convert_0xhexa(i) + n);
	}
	if (s[0 + ft_check_width(s)] == 'X')
	{
		i = va_arg(args, unsigned);
		n = ft_add_space(n - (ft_calcul_length_hexa(i) + 2));
		return (ft_convert_0xmajhexa(i) + n);
	}
	return (0);
}
