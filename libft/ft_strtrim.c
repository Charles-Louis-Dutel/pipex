/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:38:18 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/19 13:02:52 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_compare(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_remplir_dest(char *dest, char const *s1, int start, int end)
{
	int	i;

	i = 0;
	while (start < end)
	{
		dest[i] = s1[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_get_start(char const *s1, char const *set)
{
	unsigned long int		i;

	i = 0;
	while (ft_compare(s1[i], set) == 1)
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char					*dest;
	unsigned long int		i;
	unsigned long int		start;

	if (!s1)
		return (NULL);
	start = ft_get_start(s1, set);
	i = ft_strlen(s1);
	while (ft_compare(s1[i - 1], set) == 1)
		i--;
	if (start != ft_strlen(s1))
	{
		dest = (char *)malloc(sizeof(char) * (i - start + 1));
		if (!dest)
			return (NULL);
		ft_remplir_dest(dest, s1, start, i);
	}
	else
	{
		dest = (char *)malloc(sizeof(char) * 1);
		if (!dest)
			return (NULL);
		dest[0] = '\0';
	}
	return (dest);
}
