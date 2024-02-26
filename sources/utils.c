/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:21:07 by cdutel            #+#    #+#             */
/*   Updated: 2024/02/26 17:12:09 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_le_xav(char **dest)
{
	size_t	i;

	i = 0;
	while (dest[i])
	{
		free(dest[i]);
		i++;
	}
	free(dest);
}

void	free_all(t_pipex ppx)
{
	if (ppx.path_tab)
		ft_le_xav(ppx.path_tab);
	if (ppx.cmd)
		ft_le_xav(ppx.cmd);
}

void	close_pipes(t_pipex ppx)
{
	close(ppx.fd1);
	close(ppx.fd2);
	close(ppx.pipefd[0]);
	close(ppx.pipefd[1]);
}
