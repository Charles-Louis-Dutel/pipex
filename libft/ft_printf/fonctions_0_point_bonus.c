/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_0_point_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:42:05 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/19 10:42:18 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_0_point_s(va_list args, int n1, int n2)
{
	char	*s;
	int		j;
	int		len;

	s = va_arg(args, char *);
	if (!s)
	{
		if (n2 < 6)
			return (ft_add_space(n1));
		return (ft_add_space(n1 - 6) + ft_putstr("(null)"));
	}
	len = 0;
	j = 0;
	if (n2 >= ft_slen(s))
		len += ft_add_space(n1 - ft_slen(s));
	else if (n2 < ft_slen(s))
		len += ft_add_space(n1 - n2);
	while (s[j] && j < n2)
	{
		len += ft_putchar(s[j]);
		j++;
	}
	return (len);
}

static int	ft_0_point_d_i_neg(long i, int n1, int n2)
{
	int	len;

	len = 0;
	i *= -1;
	if (n1 > n2)
	{
		if (n2 <= ft_length(i))
		{
			len += ft_add_space(n1 - (ft_length(i) + 1));
			len += ft_putchar('-');
		}
		else
		{
			len += ft_add_space(n1 - n2 - 1);
			len += ft_putchar('-');
			len += ft_put_0(n2 - (ft_length(i)), i);
		}
	}
	else
	{
		len += ft_putchar('-');
		len += ft_put_0(n2 - (ft_length(i)), i);
	}
	return (ft_putnbr(i) + len);
}

static int	ft_0_point_d_i(va_list args, int n1, int n2)
{
	long	i;
	int		len;

	i = va_arg(args, int);
	len = 0;
	if (i == 0)
		return (ft_add_space(n1 - n2) + ft_put_0(n2, i));
	if (i < 0)
		return (ft_0_point_d_i_neg(i, n1, n2));
	if (n1 > n2)
	{
		if (n2 <= ft_length(i))
			len += ft_add_space(n1 - ft_length(i));
		else
		{
			len += ft_add_space(n1 - n2);
			len += ft_put_0(n2 - ft_length(i), i);
		}
	}
	else
		len += ft_put_0(n2 - ft_length(i), i);
	return (ft_putnbr(i) + len);
}

static int	ft_fonctions_0_point2(char *s, va_list args, int n1, int n2)
{
	if (s[0] == 'c')
		return (ft_add_space(n1 - 1) + ft_putchar(va_arg(args, int)));
	else if (s[0] == 's')
		return (ft_0_point_s(args, n1, n2));
	else if (s[0] == 'd' || s[0] == 'i')
		return (ft_0_point_d_i(args, n1, n2));
	else if (s[0] == 'u')
		return (ft_0_point_u(args, n1, n2));
	else if (s[0] == 'x' || s[0] == 'X')
		return (ft_0_point_hexa(args, n1, n2, s[0]));
	else if (s[0] == 'p')
		return (ft_0_point_adress(args, n1, n2));
	return (0);
}

int	ft_fonctions_0_point(char *s, va_list args)
{
	int	i;
	int	n1;
	int	n2;

	i = 0;
	n1 = 0;
	n2 = 0;
	if (s[0] >= '0' && s[0] <= '9')
		n1 = ft_calcul_space(s);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] == '.')
		i++;
	if (s[i] >= '0' && s[i] <= '9')
		n2 = ft_calcul_space(&s[i]);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] == 'c' || s[i] == 'u' || s[i] == 'p' || s[i] == 'x'
		|| s[i] == 'X' || s[i] == 'd' || s[i] == 'i' || s[i] == 's')
		return (ft_fonctions_0_point2(&s[i], args, n1, n2));
	return (0);
}
