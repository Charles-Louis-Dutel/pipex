/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:26:26 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/15 09:40:30 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr(long n);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_slen(char *str);
int	ft_length(long i);
int	ft_convert_hexa(unsigned long long n);
int	ft_convert_hexa_maj(unsigned long long n);
int	ft_convert_adress(unsigned long long n);
int	ft_convert_0xhexa(unsigned long long n);
int	ft_convert_0xmajhexa(unsigned long long n);
int	ft_calcul_length_hexa(unsigned long long n);
int	ft_point_hexa(va_list args, int n);
int	ft_point_hexamaj(va_list args, int n);
int	ft_point_adress(va_list args, int n);
int	ft_moins_hexa(va_list args, int n1, int n2, char *c);
int	ft_moins_hexamaj(va_list args, int n1, int n2, char *c);
int	ft_moins_adress(va_list args, int n1, int n2);
int	ft_moins_u(va_list args, int n1, int n2, char *c);
int	ft_moins_s(va_list args, int n1, int n2, char *c);
int	ft_0_point_u(va_list args, int n1, int n2);
int	ft_0_point_hexa(va_list args, int n1, int n2, char c);
int	ft_0_point_adress(va_list args, int n1, int n2);
int	ft_fonctions_space(char *s, va_list args);
int	ft_fonctions_number_space(char *s, va_list args);
int	ft_fonctions_plus(char *s, va_list args);
int	ft_fonctions_diese(char *s, va_list args);
int	ft_fonctions_point(char *s, va_list args);
int	ft_fonctions_moins(char *s, va_list args);
int	ft_fonction_d_i_0(char *s, va_list args);
int	ft_fonctions_0_point(char *s, va_list args);
int	ft_put_0(int nbr_0, int i);
int	ft_add_space(int len);
int	ft_check_width(char *s);
int	ft_calcul_space(char *s);
int	ft_check_flags(char *s, va_list args);
int	ft_put_args(char c, va_list args);

#endif
