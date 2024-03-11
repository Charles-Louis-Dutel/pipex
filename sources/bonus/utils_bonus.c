/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:21:07 by cdutel            #+#    #+#             */
/*   Updated: 2024/03/11 20:06:29 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_le_xav(char **dest)
{
	size_t	i;

	i = 0;
	if (!dest)
		return ;
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

// void	close_pipes(t_pipex ppx, int **pipes)
// {
// 	close(ppx.fd1);
// 	close(ppx.fd2);
// 	//close(ppx.pipefd[0]);
// 	//close(ppx.pipefd[1]);
// }

void	close_pipes_2(t_pipex ppx, int pipes[][2])
{
	int (j) = 0;
	close(ppx.fd1);
	close(ppx.fd2);
	while (j <= ppx.n_cmd_to_do)
	{
		close(pipes[j][0]);
		close(pipes[j][1]);
		j++;
	}
}
