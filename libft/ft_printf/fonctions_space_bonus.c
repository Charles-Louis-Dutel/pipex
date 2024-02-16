/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_space_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:03:42 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/19 10:41:18 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_calcul_space(char *s)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = n * 10 + (s[i] - '0');
		i++;
	}
	return (n);
}

int	ft_length(long i)
{
	int	result;

	result = 0;
	if (i == 0)
		return (1);
	if (i < 0)
	{
		i *= -1;
	}
	while (i > 0)
	{
		result++;
		i /= 10;
	}
	return (result);
}

static int	ft_space_d_i(va_list args, int n)
{
	long	i;
	int		len;

	i = 0;
	len = 0;
	i = va_arg(args, int);
	if (i == 0 && n > 1)
		return (ft_add_space(n - 1) + ft_putnbr(0));
	if (i < 0)
	{
		i *= -1;
		if (n > ft_length(i))
			len = ft_add_space(n - (ft_length(i) + 1));
		len += ft_putchar('-');
	}
	else
	{
		if (n <= ft_length(i))
			n = ft_length(i) + 1;
		len = ft_add_space(n - ft_length(i));
	}
	return (ft_putnbr(i) + len);
}

static int	ft_space_s(va_list args, int n)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		n = ft_add_space(n - 6);
		return (ft_putstr("(null)") + n);
	}
	n = ft_add_space(n - ft_slen(str));
	return (ft_putstr(str) + n);
}

int	ft_fonctions_space(char *s, va_list args)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (s[i] == '#' || s[i] == ' ' || s[i] == '+' || s[i] == '0'
		|| s[i] == '-' || s[i] == '.')
		i++;
	if (s[i] >= '0' && s[i] <= '9')
		n = ft_calcul_space(&s[i]);
	if (s[0 + ft_check_width(s)] == 'd' || s[0 + ft_check_width(s)] == 'i')
		return (ft_space_d_i(args, n));
	if (s[0 + ft_check_width(s)] == 's')
		return (ft_space_s(args, n));
	return (0);
}
