/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_moins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:34:23 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/25 10:25:10 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_moins_d_i_neg(long i, int n1, int n2)
{
	int	len;

	i *= -1;
	len = 0;
	len += ft_putchar('-');
	if (n2 > ft_length(i))
		len += ft_put_0(n2 - ft_length(i), i);
	if (n1 > ft_length(i) + 1 && n1 > n2)
	{
		if (n2 > ft_length(i))
			n1 -= (ft_length(i) + 1 + (n2 - ft_length(i)));
		else
			n1 -= (ft_length(i) + 1);
		return (ft_putnbr(i) + ft_add_space(n1) + len);
	}
	return (ft_putnbr(i) + len);
}

static int	ft_moins_d_i(va_list args, int n1, int n2, char *c)
{
	long	i;
	int		len;

	i = va_arg(args, int);
	len = 0;
	if (i == 0 && c[0] != '.')
		return (ft_putnbr(0) + ft_add_space(n1 - 1));
	else if (i == 0)
		return (ft_put_0(n2, i) + ft_add_space(n1 - n2));
	if (i < 0)
		return (ft_moins_d_i_neg(i, n1, n2));
	if (n2 > ft_length(i))
		len += ft_put_0(n2 - ft_length(i), i);
	if (n1 > ft_length(i) && n1 > n2)
	{
		if (n2 > ft_length(i))
			n1 -= (ft_length(i) + (n2 - ft_length(i)));
		else
			n1 -= (ft_length(i));
		return (ft_putnbr(i) + ft_add_space(n1) + len);
	}
	return (ft_putnbr(i) + len);
}

static int	ft_moins_2(char *s, va_list args, int n1, int n2)
{
	if (s[0] == 'c')
		return (ft_putchar(va_arg(args, int)) + ft_add_space(n1 - 1));
	else if (s[0] == 's')
		return (ft_moins_s(args, n1, n2, "0"));
	else if (s[0] == 'd' || s[0] == 'i')
		return (ft_moins_d_i(args, n1, n2, "0"));
	else if (s[0] == 'u')
		return (ft_moins_u(args, n1, n2, "0"));
	else if (s[0] == 'x')
		return (ft_moins_hexa(args, n1, n2, "0"));
	else if (s[0] == 'X')
		return (ft_moins_hexamaj(args, n1, n2, "0"));
	else if (s[0] == 'p')
		return (ft_moins_adress(args, n1, n2));
	return (0);
}

static int	ft_moins_3(char *s, va_list args, int n1)
{
	int	i;
	int	n2;

	i = 1;
	n2 = 0;
	if (s[i] >= '0' && s[i] <= '9')
		n2 = ft_calcul_space(&s[i]);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] == 'c')
		return (ft_putchar(va_arg(args, int)) + ft_add_space(n1 - 1));
	else if (s[i] == 's')
		return (ft_moins_s(args, n1, n2, &s[0]));
	else if (s[i] == 'd' || s[i] == 'i')
		return (ft_moins_d_i(args, n1, n2, &s[0]));
	else if (s[i] == 'u')
		return (ft_moins_u(args, n1, n2, &s[0]));
	else if (s[i] == 'x')
		return (ft_moins_hexa(args, n1, n2, &s[0]));
	else if (s[i] == 'X')
		return (ft_moins_hexamaj(args, n1, n2, &s[0]));
	else if (s[i] == 'p')
		return (ft_moins_adress(args, n1, n2));
	return (0);
}

int	ft_fonctions_moins(char *s, va_list args)
{
	int		i;
	int		n1;
	int		n2;

	i = 0;
	n1 = 0;
	n2 = 0;
	while (s[i] == '-')
		i++;
	if (s[i] >= '1' && s[i] <= '9')
		n1 = ft_calcul_space(&s[i]);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] == '.')
		return (ft_moins_3(&s[i], args, n1));
	else if (s[i] == 'c' || s[i] == 'u' || s[i] == 'p' || s[i] == 'x'
		|| s[i] == 'X' || s[i] == 'd' || s[i] == 'i' || s[i] == 's')
		return (ft_moins_2(&s[i], args, n1, n2));
	else if (s[i] == '%')
		return (ft_putchar('%'));
	return (0);
}
