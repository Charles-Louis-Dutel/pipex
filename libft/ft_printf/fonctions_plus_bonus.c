/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_plus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:03:33 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/25 10:02:27 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_add_space(int len)
{
	int	i;

	i = 0;
	while (len > 0)
	{
		i += ft_putchar(' ');
		len--;
	}
	return (i);
}

static int	ft_putnbr_plus(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += ft_putchar('-');
		n = -n;
	}
	else if (n >= 0)
		i += ft_putchar('+');
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

int	ft_fonctions_plus(char *s, va_list args)
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
	{
		i = va_arg(args, int);
		if (i == 0)
			n = ft_add_space(n - 2);
		else
			n = ft_add_space(n - (ft_length(i) + 1));
		return (ft_putnbr_plus(i) + n);
	}
	return (0);
}
