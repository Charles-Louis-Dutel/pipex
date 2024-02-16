/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:58:10 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/19 14:14:27 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fonction_d_i_0(char *s, va_list args)
{
	long	i;
	int		n;
	int		len;

	i = va_arg(args, int);
	n = 0;
	len = 0;
	if (s[0] >= '0' && s[0] <= '9')
		n = ft_calcul_space(&s[0]);
	if (i == 0)
		return (ft_put_0(n, i));
	if (i < 0)
	{
		i = -i;
		len += ft_putchar('-');
		if (n > ft_length(i) + 1)
			len += ft_put_0(n - (ft_length(i) + 1), i);
	}
	else if (i > 0)
	{
		if (n > ft_length(i))
			len = ft_put_0(n - ft_length(i), i);
	}
	return (ft_putnbr(i) + len);
}
