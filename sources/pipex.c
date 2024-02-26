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

char	*get_path(char **envp)
{
	int (i) = 0;
	if (*envp)
	{
		while (envp[i])
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
	ppx->error_with_file_1 = 0;
	ppx->error_with_file_2 = 0;
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

int	main(int argc, char **argv, char **envp)
{
	t_pipex	ppx;

	if (argc != 5)
		return (1);
	fd_and_pipe(argc, argv, &ppx);
	ppx.env_path = get_path(envp);
	ppx.path_tab = ft_split(ppx.env_path, ':');
	ppx.pid1 = fork();
	if (ppx.pid1 < 0)
		print_error_msg_2(ERR_FORK);
	if (ppx.pid1 == 0 && ppx.error_with_file_1 == 0)
		child_number_one(ppx, argv, envp);
	ppx.pid2 = fork();
	if (ppx.pid2 < 0)
		print_error_msg_2(ERR_FORK);
	if (ppx.pid2 == 0 && ppx.pid1 != 0 && ppx.error_with_file_2 == 0)
		child_number_two(ppx, argv, envp);
	close_pipes(ppx);
	waitpid(ppx.pid1, &ppx.status, 0);
	waitpid(ppx.pid2, &ppx.status, 0);
	if (ppx.path_tab)
		ft_le_xav(ppx.path_tab);
	if (ppx.error_with_file_2 == 1)
		return (1);
	ppx.exit_status	= WEXITSTATUS(ppx.status);
	return (ppx.exit_status);
}

