/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:04:37 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/14 18:44:22 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	len_dst;
	unsigned long	len_src;

	len_src = ft_strlen(src);
	if (dst)
		len_dst = ft_strlen(dst);
	else
		len_dst = 0;
	i = len_dst;
	j = 0;
	if (size > len_dst)
	{
		while (src[j] && j < size - len_dst - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	if (size < len_dst)
		return (size + len_src);
	return (len_dst + len_src);
}
