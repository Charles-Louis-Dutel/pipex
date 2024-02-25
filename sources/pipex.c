/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:48:40 by cdutel            #+#    #+#             */
/*   Updated: 2024/02/24 17:33:28 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *get_path(char **envp)
{
	int (i) = 0;
	if (envp)
	{
		while(envp[i])
		{
			if (strncmp("PATH", envp[i], 4) == 0)
				return (envp[i] + 5);
			i++;
		}
	}
	return (NULL);
}

static void	fd_and_pipe(int argc, char **argv, t_pipex *ppx)
{
	ppx->fd1 = open(argv[1], O_RDONLY);
	if (ppx->fd1 < 0)
		print_error_msg(ERR_FILE_DIR, argv[1]);
	ppx->fd2 = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (ppx->fd1 < 0)
		print_error_msg(ERR_FILE_DIR, argv[argc - 1]);
	if (pipe(ppx->pipefd) < 0)
		print_error_msg_2(ERR_PIPE);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	ppx;
	int status;

	if (argc != 5)
		return(1);
	fd_and_pipe(argc, argv, &ppx);
	ppx.env_path = get_path(envp);
	ppx.path_tab = ft_split(ppx.env_path, ':');
	ppx.pid1 = fork();
	if (ppx.pid1 < 0)
			print_error_msg_2(ERR_FORK);
	if (ppx.pid1 == 0)
		child_number_one(ppx, argv, envp);
	ppx.pid2 = fork();
	if (ppx.pid2 < 0)
		print_error_msg_2(ERR_FORK);
	if (ppx.pid2 == 0)
		child_number_two(ppx, argv, envp);
	close_pipes(ppx);
	waitpid(ppx.pid1, &status, 0);
	waitpid(ppx.pid2, &status, 0);
	if (ppx.path_tab)
		ft_le_xav(ppx.path_tab);
	if (WEXITSTATUS(status))
	{
		ppx.exit_status = WEXITSTATUS(status);
		return(ppx.exit_status);
	}
	return (0);
}

