/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_no_malloc.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 08:17:52 by cdutel            #+#    #+#             */
/*   Updated: 2024/03/14 11:44:10 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_NO_MALLOC_H
# define GNL_NO_MALLOC_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_gnl
{
	int		value;
	int		len;
	char	*line;
	char	*stock_line;
	char	*new_line;
	char	*dest;
}	t_gnl;

/*GNL*/
char	*gnl_no_malloc(int fd);

/*Utils*/
int		ft_len(char *s);
int		ft_check(char *stat);
char	*copy(char *src);
char	*join(char *s1, char *s2, t_gnl gnl);

#endif
