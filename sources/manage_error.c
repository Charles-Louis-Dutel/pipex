/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:58:36 by cdutel            #+#    #+#             */
/*   Updated: 2024/02/25 15:59:35 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error_msg(char *err_msg, char *err_msg2)
{
	write(2, err_msg, ft_strlen(err_msg));
	write(2, err_msg2, ft_strlen(err_msg2));
	write(2, "\n", 1);
	exit(0);
}

void	print_error_msg_2(char *err_msg)
{
	write(2, err_msg, ft_strlen(err_msg));
	exit(127);
}

void	print_error_msg_3(char *err_msg, char *err_msg2, t_pipex ppx)
{
	write(2, err_msg, ft_strlen(err_msg));
	write(2, err_msg2, ft_strlen(err_msg2));
	write(2, "\n", 1);
	free_all(ppx);
	exit(127);
}
