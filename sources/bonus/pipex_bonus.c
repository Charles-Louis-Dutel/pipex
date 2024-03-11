/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:51:22 by cdutel            #+#    #+#             */
/*   Updated: 2024/03/11 20:54:54 by cdutel           ###   ########.fr       */
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

static void	open_pipes(int pipes[][2], int taille)
{
	int (pipe_number) = 0;
	while(pipe_number < taille)
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
	ppx->error_with_file_1 = 0;
	ppx->error_with_file_2 = 0;
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

static int	wait_for_childs(t_pipex ppx, int pids)
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

static int	without_here_doc(int argc, char **argv, char **envp)
{
	t_pipex	ppx;
	int		pids[argc - 3];
	int		pipes[argc - 2][2];
	int		test;

	ppx.cmd_number = CMD1;
	ppx.n_cmd_to_do = argc - 3;
	open_files(argc, argv, &ppx);
	open_pipes(pipes, argc - 2);
	get_path(argv, envp, &ppx);
	ppx.i = 0;
	while (ppx.i < argc - 3)
	{
		pids[ppx.i] = fork();
		test = pids[ppx.i];
		if (pids[ppx.i] == 0 && ppx.i < argc -3)
		{
			childs_process(ppx, pipes, argv, envp);
		}
		ppx.cmd_number++;
		ppx.i++;
	}
	close_pipes_2(ppx, pipes);
	ppx.exit_status = wait_for_childs(ppx, test);
	if (ppx.path_tab)
		ft_le_xav(ppx.path_tab);
	if (ppx.error_with_file_2 == 1)
		return (1);
	return (ppx.exit_status);
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
