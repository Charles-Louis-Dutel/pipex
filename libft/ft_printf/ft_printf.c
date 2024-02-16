/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:03:08 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/30 12:22:53 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*Fonction ft_put args : permet d'appeler les fonctions
correspondant aux flags "csdiuxXp%".*/
int	ft_put_args(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned)));
	else if (c == 'x')
		return (ft_convert_hexa(va_arg(args, unsigned)));
	else if (c == 'X')
		return (ft_convert_hexa_maj(va_arg(args, unsigned)));
	else if (c == 'p')
		return (ft_convert_adress(va_arg(args, unsigned long long)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

/*Fonction ft_check_width : permet de return le nombre de flag
après le '%' jusqu'au dernier flag "csdiuxXp%".*/
int	ft_check_width(char *s)
{
	int	i;

	i = 0;
	while (s[i] == '#' || s[i] == ' ' || s[i] == '+' || s[i] == '-'
		|| s[i] == '.' || (s[i] >= '0' && s[i] <= '9'))
		i++;
	return (i);
}

/*Fonction ft_length_flag : permet de return le nombre de caractère
après le '%' jusqu'au dernier flag "csdiuxXp%" + 2.*/
static int	ft_length_flag(char *s, char c)
{
	if (c == '#' || c == ' ' || c == '+' || c == '-' || c == '.'
		|| (c >= '0' && c <= '9'))
		return (ft_check_width(s) + 2);
	return (2);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		len;
	char	*str;

	va_start(args, s);
	i = 0;
	len = 0;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_check_flags(&str[i + 1], args);
			i += ft_length_flag(&str[i + 1], str[i + 1]);
		}
		if (str[i] && str[i] != '%')
		{
			len += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(args);
	return (len);
}
/*
int main()
{
	int x;
	int y;

	x = ft_printf("zee%");
	printf("\n");
	y = printf("zee%");
	printf("\n");

	printf("%d\n", x);
	printf("%d\n", y);
	return 0;
}*/
