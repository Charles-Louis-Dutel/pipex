/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   without_here_doc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 07:57:29 by cdutel            #+#    #+#             */
/*   Updated: 2024/03/18 17:41:34 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	check_acces(int argc, char **argv, t_pipex ppx)
{
	int (i) = ppx.cmd_number;
	while (i < argc - 1)
	{
		if (access(argv[i], F_OK | X_OK) < 0)
			return (0);
		i++;
	}
	return (1);
}

void	get_path(int argc, char **argv, char **envp, t_pipex *ppx)
{
	int (i) = 0;
	if (*envp == NULL && check_acces(argc, argv, *ppx) == 0)
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

void	open_pipes(int pipes[][2], int taille)
{
	int (pipe_number) = 0;
	while (pipe_number < taille)
	{
		if (pipe(pipes[pipe_number]) < 0)
		{
			print_error_msg_2(ERR_PIPE);
		}
		pipe_number++;
	}
}

static void	open_files(int argc, char **argv, t_pipex *ppx)
{
	ppx->fd1 = open(argv[1], O_RDONLY);
	if (access(argv[1], F_OK) >= 0)
	{
		if (access(argv[1], F_OK | R_OK) < 0)
		{
			ppx->error_with_file_1 = 1;
			print_error_msg(ERR_PERM, argv[1]);
		}
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
}

int	without_here_doc(int argc, char **argv, char **envp)
{
	t_pipex	ppx;
	int		pipes[argc - 2][2];

	ppx = init_ppx();
	ppx.pids = malloc(sizeof(int) * argc - 3);
	ppx.cmd_number = CMD1;
	ppx.n_cmd_to_do = argc - 3;
	open_files(argc, argv, &ppx);
	open_pipes(pipes, argc - 2);
	get_path(argc, argv, envp, &ppx);
	while (ppx.i < argc - 3)
	{
		ppx.pids[ppx.i] = fork();
		ppx.pid_to_wait = ppx.pids[ppx.i];
		if (ppx.pids[ppx.i] == 0 && ppx.i < argc - 3)
			childs_process(ppx, pipes, argv, envp);
		ppx.cmd_number++;
		ppx.i++;
	}
	close_pipes(ppx, pipes);
	ppx.exit_status = wait_for_childs(ppx, ppx.pid_to_wait);
	if (ppx.error_with_file_2 == 1)
		return (free_all(ppx), 1);
	return (free_all(ppx), ppx.exit_status);
}
