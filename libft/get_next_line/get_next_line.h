/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:01:37 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/20 09:41:02 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct p_list
{
	char			*data;
	struct p_list	*next;
}	t_my_list;

char		*get_next_line(int fd);
char		*ft_new_line(t_my_list *temp);
void		ft_new_temp(t_my_list **temp);
t_my_list	*ft_get_last(t_my_list *temp);
void		ft_free_list(t_my_list *temp);
int			ft_stlen(char *s);

#endif
