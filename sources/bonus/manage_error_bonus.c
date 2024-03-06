/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:58:36 by cdutel            #+#    #+#             */
/*   Updated: 2024/03/04 17:24:17 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	print_error_msg(char *err_msg, char *err_msg2)
{
	write(2, err_msg, ft_strlen(err_msg));
	write(2, err_msg2, ft_strlen(err_msg2));
	write(2, "\n", 1);
}

void	print_error_msg_2(char *err_msg)
{
	write(2, err_msg, ft_strlen(err_msg));
	exit(127);
}

void	print_error_msg_3(char *err_msg, char *err_msg2, t_pipex ppx, int ex)
{
	char	*temp;
	char	*msg;

	temp = ft_strjoin(err_msg2, "\n");
	msg = ft_strjoin(err_msg, temp);
	write(2, msg, ft_strlen(msg));
	free(temp);
	free(msg);
	free_all(ppx);
	exit(ex);
}
