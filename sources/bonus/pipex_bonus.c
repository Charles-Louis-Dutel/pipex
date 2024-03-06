/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:51:22 by cdutel            #+#    #+#             */
/*   Updated: 2024/03/05 13:22:49 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	get_path(char **argv, char **envp, t_pipex *ppx)
{
	int (i) = 0;
	if (*envp == NULL && (access(argv[2], F_OK) < 0
			|| access(argv[3], F_OK) < 0))
		exit(127);
	while (envp[i])
	{
		if (strncmp("PATH", envp[i], 4) == 0)
		{
			ppx->env_path = envp[i] + 5;
			ppx->path_tab = ft_split(ppx->env_path, ':');
			return ;
		}
		i++;
	}
	ppx->env_path = NULL;
	ppx->path_tab = ft_split(ppx->env_path, ':');
}

static void	fd_and_pipe(int argc, char **argv, t_pipex *ppx)
{
	ppx->error_with_file_1 = 0;
	ppx->error_with_file_2 = 0;
	//ppx->n_fork_to_do = argc - 3;
	ppx->fd1 = open(argv[1], O_RDONLY);
	if (access(argv[1], F_OK | R_OK) < 0)
	{
		ppx->error_with_file_1 = 1;
		print_error_msg(ERR_PERM, argv[1]);
	}
	if (ppx->fd1 < 0 && ppx->error_with_file_1 == 0)
		print_error_msg(ERR_FILE_DIR, argv[1]);
	ppx->fd2 = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (access(argv[argc - 1], F_OK | R_OK | W_OK) < 0)
	{
		ppx->error_with_file_2 = 1;
		print_error_msg(ERR_PERM, argv[argc - 1]);
	}
	if (ppx->fd2 < 0 && ppx->error_with_file_2 == 0)
		print_error_msg(ERR_FILE_DIR, argv[argc - 1]);
	if (pipe(ppx->pipefd) < 0)
		print_error_msg_2(ERR_PIPE);
}

static int	without_here_doc(int argc, char **argv, char **envp)
{
	t_pipex	ppx;
	int		pids[argc - 3];

	fd_and_pipe(argc, argv, &ppx);
	get_path(argv, envp, &ppx);
	ppx.i = 0;
	while (ppx.i < argc - 3)
	{
		pids[ppx.i] = fork();
		if (pids[ppx.i] == 0)
		{
			childs_process(ppx, argv, envp);
			return (0);
		}
		ppx.i++;
	}
	while (ppx.pid2 != -1)
	{
		ppx.pid2 = waitpid(-1, &ppx.status, 0);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
		return (print_error_msg_2(ERR_ARG), 1);
	if (argc >= 5)
	{
		if (argc >= 6 && ft_strncmp("here_doc", argv[1], 10) == 0)
			return (print_error_msg_2("here_doc a faire"), 1);
		else
			return (without_here_doc(argc, argv, envp));
	}
	return (0);
}
