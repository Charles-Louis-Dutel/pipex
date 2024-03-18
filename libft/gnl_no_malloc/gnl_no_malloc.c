/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_no_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 08:17:46 by cdutel            #+#    #+#             */
/*   Updated: 2024/03/18 14:55:35 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_no_malloc.h"

static char	*get_line(char *s)
{
	char	*dest;

	int (i) = 0;
	int (len) = 0;
	if (!s)
		return (NULL);
	while (s[len] && s[len] != '\n')
		len++;
	if (s[len] && s[len] == '\n')
		len++;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (i < len && s[i] != '\n')
	{
		dest[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		dest[i++] = '\n';
	dest[i] = '\0';
	return (dest);
}

static void	new_stat(char *stat, t_gnl gnl)
{
	int (i) = 0;
	int (j) = 0;
	while (stat[i] && stat[i] != '\n')
		i++;
	if (stat[i] == '\n')
		i++;
	if (stat[i])
	{
		while (i < gnl.len)
		{
			stat[j] = stat[i];
			j++;
			i++;
		}
	}
	stat[j] = '\0';
}

static char	*ft_read(char *stat, t_gnl gnl, int fd)
{
	gnl.stock_line = NULL;
	gnl.value = 1;
	if (stat[0] >= 0 && stat[0] <= 126)
		gnl.stock_line = copy(stat);
	while (ft_check(stat) != 1 && gnl.value != 0)
	{
		gnl.value = read(fd, stat, BUFFER_SIZE);
		if (gnl.value == -1)
			return (NULL);
		stat[gnl.value] = '\0';
		if (!gnl.stock_line)
			gnl.stock_line = copy(stat);
		else
			gnl.stock_line = join(gnl.stock_line, stat, gnl);
	}
	gnl.new_line = get_line(gnl.stock_line);
	free(gnl.stock_line);
	gnl.len = ft_len(stat);
	new_stat(stat, gnl);
	return (gnl.new_line);
}

char	*gnl_no_malloc(int fd)
{
	t_gnl		gnl;
	static char	stat[BUFFER_SIZE + 1];

	gnl.line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	gnl.line = ft_read(stat, gnl, fd);
	if (gnl.line[0] == '\0')
	{
		free(gnl.line);
		return (NULL);
	}
	return (gnl.line);
}

// int main()
// {
// 	int	fd;
// 	char *test;
// 	int i = 0;

// 	test = NULL;
// 	fd = open("test.txt", O_RDONLY);
// 	while (i < 2)
// 	{
// 		test = gnl_no_malloc(fd);
// 		if (test == NULL)
// 			break;
// 		printf("%s", test);
// 		free(test);
// 		i++;
// 	}
// 	return 0;
// }
