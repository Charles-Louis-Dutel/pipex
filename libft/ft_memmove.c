/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:56:59 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/14 16:33:40 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned long	i;
	const char		*source;
	char			*destination;

	if (!dest && !src)
		return (NULL);
	source = (const char *)src;
	destination = (char *)dest;
	if (destination > source)
	{
		while (n > 0)
		{
			destination[n - 1] = source[n - 1];
			n--;
		}
	}
	else
	{
		i = -1;
		while (++i < n)
			destination[i] = source[i];
	}
	return (dest);
}
