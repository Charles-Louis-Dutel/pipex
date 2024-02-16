/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_number_space.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:00:36 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/25 10:01:22 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_space_u(va_list args, int n)
{
	unsigned long long	i;
	int					len;

	i = va_arg(args, unsigned);
	len = 0;
	if (i == 0)
		return (ft_add_space(n - 1) + ft_putnbr(i));
	else if (n > ft_length(i))
		len = ft_add_space(n - ft_length(i));
	return (ft_putnbr_unsigned(i) + len);
}

static int	ft_space_hexa(va_list args, int n, char c)
{
	unsigned long long	i;
	int					len;

	i = va_arg(args, unsigned);
	len = 0;
	if (n > ft_calcul_length_hexa(i))
		len = ft_add_space(n - ft_calcul_length_hexa(i));
	if (c == 'x')
		return (ft_convert_hexa(i) + len);
	else if (c == 'X')
		return (ft_convert_hexa_maj(i) + len);
	return (0);
}

static int	ft_space_adress(va_list args, int n)
{
	unsigned long long	i;
	int					len;

	i = va_arg(args, unsigned long long);
	len = 0;
	if (!i)
	{
		if (n > 5)
			len = ft_add_space(n - 5);
		return (ft_putstr("(nil)") + len);
	}
	if (n > ft_length(i))
		len = ft_add_space(n - (ft_calcul_length_hexa(i) + 2));
	return (ft_convert_adress(i) + len);
}

static int	ft_space_number_d_i(va_list args, int n)
{
	long	i;
	int		len;

	i = 0;
	len = 0;
	i = va_arg(args, int);
	if (i == 0)
		return (ft_add_space(n - 1) + ft_putnbr(0));
	if (i < 0)
	{
		i *= -1;
		if (n > ft_length(i) + 1)
			len = ft_add_space(n - (ft_length(i) + 1));
		len += ft_putchar('-');
	}
	else
	{
		if (n > ft_length(i))
			len = ft_add_space(n - ft_length(i));
	}
	return (ft_putnbr(i) + len);
}

int	ft_fonctions_number_space(char *s, va_list args)
{
	int		i;
	int		n;
	char	c;

	i = 0;
	n = 0;
	if (s[i] >= '1' && s[i] <= '9')
		n = ft_calcul_space(&s[i]);
	if (s[0 + ft_check_width(s)] == 'u')
		return (ft_space_u(args, n));
	else if (s[0 + ft_check_width(s)] == 'x' || s[0 + ft_check_width(s)] == 'X')
		return (ft_space_hexa(args, n, s[0 + ft_check_width(s)]));
	else if (s[0 + ft_check_width(s)] == 'p')
		return (ft_space_adress(args, n));
	else if (s[0 + ft_check_width(s)] == 'd' || s[0 + ft_check_width(s)] == 'i')
		return (ft_space_number_d_i(args, n));
	else if (s[0 + ft_check_width(s)] == 'c')
	{
		c = va_arg(args, int);
		if (n >= 1)
			n = ft_add_space(n - 1);
		return (ft_putchar(c) + n);
	}
	return (0);
}
