/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_0_point2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:02:54 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/25 09:56:37 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_0_point_u(va_list args, int n1, int n2)
{
	unsigned long long	i;
	int					len;

	i = va_arg(args, unsigned);
	len = 0;
	if (i == 0)
		return (ft_add_space(n1 - n2) + ft_put_0(n2, i));
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
	return (ft_putnbr_unsigned(i) + len);
}

int	ft_0_point_hexa(va_list args, int n1, int n2, char c)
{
	unsigned long long	i;
	int					len;

	i = va_arg(args, unsigned);
	len = 0;
	if (i == 0)
		return (ft_add_space(n1 - n2) + ft_put_0(n2, i));
	if (n1 > n2)
	{
		if (n2 <= ft_calcul_length_hexa(i))
			len += ft_add_space(n1 - ft_calcul_length_hexa(i));
		else
		{
			len += ft_add_space(n1 - n2);
			len += ft_put_0(n2 - ft_calcul_length_hexa(i), i);
		}
	}
	else
		len += ft_put_0(n2 - ft_calcul_length_hexa(i), i);
	if (c == 'x')
		return (ft_convert_hexa(i) + len);
	else if (c == 'X')
		return (ft_convert_hexa_maj(i) + len);
	return (0);
}

int	ft_0_point_adress(va_list args, int n1, int n2)
{
	unsigned long long	i;
	int					len;

	i = va_arg(args, unsigned long long);
	len = 0;
	if (!i)
		return (ft_add_space(n1 - 5) + ft_putstr("(nil)"));
	if (n1 > n2)
	{
		if (n2 <= ft_calcul_length_hexa(i))
		{
			len += ft_add_space(n1 - 2 - ft_calcul_length_hexa(i));
			len += ft_putstr("0x");
		}
		else
		{
			len += ft_add_space(n1 - n2 - 2) + ft_putstr("0x");
			len += ft_put_0(n2 - ft_calcul_length_hexa(i), i);
		}
		return (ft_convert_hexa(i) + len);
	}
	len += ft_putstr("0x");
	len += ft_put_0(n2 - ft_calcul_length_hexa(i), i);
	return (ft_convert_hexa(i) + len);
}
