/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_no_malloc_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 08:17:17 by cdutel            #+#    #+#             */
/*   Updated: 2024/03/14 11:44:23 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_no_malloc.h"

int	ft_len(char *s)
{
	int (i) = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_check(char *stat)
{
	int (i) = 0;
	while (stat[i])
	{
		if (stat[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*copy(char *src)
{
	char	*dest;

	int (i) = 0;
	dest = malloc(sizeof(char) * (ft_len(src) + 1));
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*join(char *s1, char *s2, t_gnl gnl)
{
	int (i) = 0;
	int (j) = 0;
	if (!s1 || !s2)
		return (NULL);
	gnl.dest = malloc(sizeof(char) * (ft_len(s1) + ft_len(s2) + 1));
	if (!gnl.dest)
		return (NULL);
	while (s1[i])
	{
		gnl.dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		gnl.dest[i] = s2[j];
		i++;
		j++;
	}
	gnl.dest[i] = '\0';
	free(s1);
	return (gnl.dest);
}
