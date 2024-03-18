/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:21:07 by cdutel            #+#    #+#             */
/*   Updated: 2024/03/18 17:40:56 by cdutel           ###   ########.fr       */
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
	if (ppx.pids)
		free(ppx.pids);
	if (ppx.limiter)
		free(ppx.limiter);
}

void	close_pipes(t_pipex ppx, int pipes[][2])
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

int	wait_for_childs(t_pipex ppx, int pids)
{
	int (exit_status) = 0;
	int (pid) = 0;
	while (pid != -1)
	{
		pid = waitpid(-1, &ppx.status, 0);
		if (pid == pids)
			exit_status = WEXITSTATUS(ppx.status);
	}
	return (exit_status);
}

t_pipex	init_ppx(void)
{
	t_pipex	ppx;

	ppx.error_with_file_1 = 0;
	ppx.error_with_file_2 = 0;
	ppx.i = 0;
	ppx.exit_status = 0;
	ppx.cmd_number = CMD1HD;
	ppx.pids = NULL;
	ppx.limiter = NULL;
	ppx.str_hd = NULL;
	ppx.cmd = NULL;
	return (ppx);
}
