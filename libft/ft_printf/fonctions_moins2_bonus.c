/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_moins2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:30:39 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/19 10:40:46 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_moins_u(va_list args, int n1, int n2, char *c)
{
	unsigned long long	i;
	int					len;

	i = va_arg(args, unsigned);
	len = 0;
	if (i == 0 && c[0] != '.')
		return (ft_putnbr(0) + ft_add_space(n1 - 1));
	else if (i == 0)
		return (ft_put_0(n2, i) + ft_add_space(n1 - n2));
	if (n2 > ft_length(i))
		len += ft_put_0(n2 - ft_length(i), i);
	if (n1 > ft_length(i) && n1 > n2)
	{
		if (n2 > ft_length(i))
			n1 -= (ft_length(i) + (n2 - ft_length(i)));
		else
			n1 -= (ft_length(i));
		return (ft_putnbr_unsigned(i) + ft_add_space(n1) + len);
	}
	return (ft_putnbr_unsigned(i) + len);
}

int	ft_moins_hexa(va_list args, int n1, int n2, char *c)
{
	unsigned long long	i;
	int					len;
	int					len_hex;

	i = va_arg(args, unsigned);
	if (i == 0 && c[0] != '.')
		return (ft_putnbr(0) + ft_add_space(n1 - 1));
	if (i == 0)
		return (ft_put_0(n2, i) + ft_add_space(n1 - n2));
	len = 0;
	len_hex = ft_calcul_length_hexa(i);
	if (i == 0)
		return (ft_put_0(n2, i) + ft_add_space(n1 - n2));
	if (n2 > len_hex)
		len += ft_put_0(n2 - len_hex, i);
	if (n1 > len_hex && n1 > n2)
	{
		if (n2 > len_hex)
			n1 -= (len_hex + (n2 - len_hex));
		else
			n1 -= (len_hex);
		return (ft_convert_hexa(i) + ft_add_space(n1) + len);
	}
	return (ft_convert_hexa(i) + len);
}

int	ft_moins_hexamaj(va_list args, int n1, int n2, char *c)
{
	unsigned long long	i;
	int					len;
	int					len_hex;

	i = va_arg(args, unsigned);
	if (i == 0 && c[0] != '.')
		return (ft_putnbr(0) + ft_add_space(n1 - 1));
	else if (i == 0)
		return (ft_put_0(n2, i) + ft_add_space(n1 - n2));
	len = 0;
	len_hex = ft_calcul_length_hexa(i);
	if (i == 0)
		return (ft_put_0(n2, i) + ft_add_space(n1 - n2));
	if (n2 > len_hex)
		len += ft_put_0(n2 - len_hex, i);
	if (n1 > len_hex && n1 > n2)
	{
		if (n2 > len_hex)
			n1 -= (len_hex + (n2 - len_hex));
		else
			n1 -= (len_hex);
		return (ft_convert_hexa_maj(i) + ft_add_space(n1) + len);
	}
	return (ft_convert_hexa_maj(i) + len);
}

int	ft_moins_adress(va_list args, int n1, int n2)
{
	unsigned long long	i;
	int					len;
	int					len_hex;

	i = va_arg(args, unsigned long long);
	if (!i)
		return (ft_putstr("(nil)") + ft_add_space(n1 - 5));
	len = 0;
	len_hex = ft_calcul_length_hexa(i);
	len += ft_putstr("0x");
	if (n2 > len_hex)
		len += ft_put_0(n2 - len_hex, i);
	if (n1 > len_hex && n1 > n2)
	{
		if (n2 > len_hex)
			n1 -= (len_hex + 2 + (n2 - len_hex));
		else
			n1 -= (len_hex + 2);
		return (ft_convert_hexa(i) + ft_add_space(n1) + len);
	}
	return (ft_convert_hexa(i) + len);
}

int	ft_moins_s(va_list args, int n1, int n2, char *c)
{
	char	*str;
	int		j;
	int		len;

	str = va_arg(args, char *);
	if (!str)
	{
		if (c[0] == '.' && n2 < 6)
			return (ft_add_space(n1));
		return (ft_putstr("(null)") + ft_add_space(n1 - 6));
	}
	j = 0;
	len = 0;
	if (c[0] == '.')
	{
		while (j < n2 && str[j])
		{
			len += ft_putchar(str[j]);
			j++;
		}
		return (ft_add_space(n1 - len) + len);
	}
	len = ft_slen(str);
	return (ft_putstr(str) + ft_add_space(n1 - len));
}
