/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 00:53:14 by cdutel            #+#    #+#             */
/*   Updated: 2024/03/18 21:19:24 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	open_files_2(int argc, char **argv, t_pipex *ppx)
{
	ppx->fd1 = open(FILE_HD, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (access(FILE_HD, F_OK) >= 0)
	{
		if (access(FILE_HD, F_OK | R_OK | W_OK) < 0)
		{
			ppx->error_with_file_1 = 1;
			print_error_msg(ERR_PERM, FILE_HD);
		}
	}
	if (ppx->fd1 < 0 && ppx->error_with_file_1 == 0)
		print_error_msg(ERR_FILE_DIR, FILE_HD);
	else if (!(ppx->fd1 < 0))
		ft_putstr_fd(ppx->str_hd, ppx->fd1);
	close(ppx->fd1);
	ppx->fd1 = open(FILE_HD, O_RDWR);
	if (ppx->str_hd)
		free(ppx->str_hd);
	ppx->fd2 = open(argv[argc - 1], O_RDWR | O_APPEND | O_CREAT, 0644);
	if (access(argv[argc - 1], F_OK | R_OK | W_OK) < 0)
	{
		ppx->error_with_file_2 = 1;
		print_error_msg(ERR_PERM, argv[argc - 1]);
	}
	if (ppx->fd2 < 0 && ppx->error_with_file_2 == 0)
		print_error_msg(ERR_FILE_DIR, argv[argc - 1]);
}

static char	*get_here_doc(t_pipex ppx)
{
	char	*temp;
	char	*temp2;
	char	*dest;

	temp = NULL;
	temp2 = NULL;
	dest = malloc(sizeof(char));
	if (!dest)
		return (NULL);
	dest[0] = '\0';
	while (1)
	{
		temp2 = dest;
		temp = gnl_no_malloc(STDIN_FILENO);
		if (!temp || ft_strncmp(temp, ppx.limiter, ft_strlen(ppx.limiter)) == 0)
			break ;
		dest = (ft_strjoin(temp2, temp));
		free(temp);
		free(temp2);
	}
	if (temp)
		free (temp);
	return (dest);
}

int	here_doc(int argc, char **argv, char **envp)
{
	t_pipex	ppx;

	ppx = init_ppx();
	ppx.limiter = ft_strjoin(argv[2], "\n");
	ppx.str_hd = get_here_doc(ppx);
	ppx.pids = malloc(sizeof(int) * argc - 4);
	ppx.n_cmd_to_do = argc - 4;
	open_files_2(argc, argv, &ppx);
	ppx.pipes = open_pipes(argc - 3, &ppx);
	get_path(argc, argv, envp, &ppx);
	while (ppx.i < argc - 4)
	{
		ppx.pids[ppx.i] = fork();
		ppx.pid_to_wait = ppx.pids[ppx.i];
		if (ppx.pids[ppx.i] == 0 && ppx.i < argc - 4)
			childs_process(ppx, ppx.pipes, argv, envp);
		ppx.cmd_number++;
		ppx.i++;
	}
	close_pipes(ppx, ppx.pipes);
	ppx.exit_status = wait_for_childs(ppx, ppx.pid_to_wait);
	if (ppx.error_with_file_2 == 1)
		return (free_all(ppx), 1);
	return (free_all(ppx), ppx.exit_status);
}
