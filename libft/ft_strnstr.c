/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:28:07 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/08 22:24:39 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned long int	i;
	unsigned long int	index;

	index = 0;
	if (!big && !len)
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	while (big[index] && index < len)
	{
		if (big[index] == little[0])
		{
			i = 1;
			while (little[i] && little[i] == big[i + index] && (index
					+ i) < len)
			{
				i++;
			}
			if (little[i] == '\0')
				return ((char *)&big[index]);
		}
		index++;
	}
	return (0);
}
