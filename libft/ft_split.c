/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:20:52 by cdutel            #+#    #+#             */
/*   Updated: 2024/03/04 12:23:29 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_error(char **dest)
{
	size_t	i;

	i = 0;
	while (dest[i])
	{
		free(dest[i]);
		i++;
	}
	free(dest);
	return (NULL);
}

static int	ft_n_mot(char const *s, char c)
{
	int	i;
	int	nb_mot;

	i = 0;
	nb_mot = 0;
	while (s[i])
	{
		if (i == 0 && s[0] != c)
			nb_mot++;
		else if (s[i] != c && s[i - 1] == c)
			nb_mot++;
		i++;
	}
	return (nb_mot);
}

static char	*remplir_dest(char const *s, int start, int end, char **dest)
{
	char	*tab;
	int		i;

	tab = malloc(sizeof(char) * (end - start +1));
	if (!tab)
		return (ft_error(dest));
	i = 0;
	while (start < end)
	{
		tab[i] = s[start];
		i++;
		start++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char		**dest;
	int			start;

	size_t (i) = 0;
	int (j) = 0;
	if (!s)
		return (NULL);
	dest = malloc(sizeof(char *) * (ft_n_mot(s, c) + 1));
	if (!dest)
		return (NULL);
	while (i < ft_strlen(s))
	{
		if (s[i] != c && s[i])
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			dest[j++] = remplir_dest(s, start, i, dest);
			if (dest[j - 1] == NULL)
				return (NULL);
		}
		i++;
	}
	dest[j] = NULL;
	return (dest);
}
