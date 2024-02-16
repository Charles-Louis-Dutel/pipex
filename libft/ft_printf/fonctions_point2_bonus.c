/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_point2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:02:57 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/24 12:36:54 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_point_hexa(va_list args, int n)
{
	unsigned long long	i;

	i = va_arg(args, unsigned);
	if (i == 0 && n == 0)
		return (0);
	if (!n)
		n = 0;
	else if (n > ft_calcul_length_hexa(i))
		n = ft_put_0(n - ft_calcul_length_hexa(i), i);
	else
		n = 0;
	return (ft_convert_hexa(i) + n);
}

int	ft_point_hexamaj(va_list args, int n)
{
	unsigned long long	i;

	i = va_arg(args, unsigned);
	if (i == 0 && n == 0)
		return (0);
	if (!n)
		n = 0;
	else if (n > ft_calcul_length_hexa(i))
		n = ft_put_0(n - ft_calcul_length_hexa(i), i);
	else
		n = 0;
	return (ft_convert_hexa_maj(i) + n);
}

int	ft_point_adress(va_list args, int n)
{
	unsigned long long	i;
	int					len;

	len = 0;
	i = va_arg(args, unsigned long long);
	if (!i)
		return (ft_putstr("(nil)"));
	len += ft_putstr("0x");
	if (n > ft_calcul_length_hexa(i))
		len += ft_put_0(n - ft_calcul_length_hexa(i), i);
	else
		len += 0;
	return (ft_convert_hexa(i) + len);
}
