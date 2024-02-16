/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:46:12 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/24 10:14:41 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_0(int nbr_0, int i)
{
	int	result;

	if (nbr_0 <= 0 && i >= 0)
		return (0);
	result = 0;
	while (nbr_0 != 0)
	{
		result += ft_putchar('0');
		nbr_0--;
	}
	return (result);
}

int	ft_point_d_i(va_list args, int n)
{
	long	i;
	int		len;

	i = va_arg(args, int);
	len = 0;
	if (i == 0)
		return (ft_put_0(n, i));
	else if (i < 0)
	{
		i *= -1;
		ft_putchar('-');
		if (n > (ft_length(i)))
			len = ft_put_0(n - ft_length(i), i);
		return (ft_putnbr(i) + len + 1);
	}
	else if (i > 0)
	{
		if (n > ft_length(i))
			len = ft_put_0(n - ft_length(i), i);
		return (ft_putnbr(i) + len);
	}
	return (0);
}

int	ft_point_u(va_list args, int n)
{
	unsigned long long	i;

	i = 0;
	i = va_arg(args, unsigned);
	if (!n && i == 0)
		return (0);
	else if (i == 0 && n > 0)
	{
		n = ft_put_0(n, i);
		return (n);
	}
	n -= ft_length(i);
	if (n < 0)
		n = 0;
	else
		n = ft_put_0(n, i);
	return (ft_putnbr_unsigned(i) + n);
}

int	ft_point_s(va_list args, int n)
{
	char	*str;
	int		i;
	int		len;

	str = va_arg(args, char *);
	i = 0;
	len = 0;
	if (!str && n < 6)
		return (0);
	else if (!str)
		return (ft_putstr("(null)"));
	while (i < n && str[i])
	{
		len += ft_putchar(str[i]);
		i++;
	}
	return (len);
}

int	ft_fonctions_point(char *s, va_list args)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (s[0] >= '0' && s[0] <= '9')
		n = ft_calcul_space(&s[0]);
	else if (s[i + 1] >= '0' && s[i + 1] <= '9')
		n = ft_calcul_space(&s[i + 1]);
	if (s[0 + ft_check_width(s)] == 'd' || s[0 + ft_check_width(s)] == 'i')
		return (ft_point_d_i(args, n));
	else if (s[0 + ft_check_width(s)] == 'u')
		return (ft_point_u(args, n));
	else if (s[0 + ft_check_width(s)] == 's')
		return (ft_point_s(args, n));
	else if (s[0 + ft_check_width(s)] == 'x')
		return (ft_point_hexa(args, n));
	else if (s[0 + ft_check_width(s)] == 'X')
		return (ft_point_hexamaj(args, n));
	else if (s[0 + ft_check_width(s)] == 'p')
		return (ft_point_adress(args, n));
	else if (s[0 + ft_check_width(s)] == 'c')
		return (ft_putchar(va_arg(args, int)));
	return (0);
}
