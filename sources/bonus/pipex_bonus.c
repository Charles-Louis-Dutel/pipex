/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:51:22 by cdutel            #+#    #+#             */
/*   Updated: 2024/03/12 11:46:27 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
		return (print_error_msg_2(ERR_ARG), 1);
	if (argc >= 5)
	{
		if (argc >= 6 && ft_strncmp("here_doc", argv[1], 10) == 0)
			return (here_doc(argc, argv, envp));
		else if (argc == 5 && ft_strncmp("here_doc", argv[1], 10) == 0)
			return (print_error_msg_2(ERR_ARG), 1);
		else
			return (without_here_doc(argc, argv, envp));
	}
	return (0);
}
