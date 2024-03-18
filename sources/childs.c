/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:55:14 by cdutel            #+#    #+#             */
/*   Updated: 2024/03/18 16:52:51 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_command(char **path_tab, char *cmd_name)
{
	char	*temp;
	char	*cmd;

	int (i) = 0;
	if (!path_tab)
		return (NULL);
	while (path_tab[i])
	{
		temp = ft_strjoin(path_tab[i], "/");
		cmd = ft_strjoin(temp, cmd_name);
		free(temp);
		if (access(cmd, F_OK) == 0)
		{
			if (access(cmd, X_OK) == 0)
				return (cmd);
			else
			{
				free(cmd);
				print_error_msg(ERR_PERM, cmd_name);
			}
		}
		free(cmd);
		i++;
	}
	return (NULL);
}

static void	case_directory(t_pipex ppx, char **envp)
{
	if (access(ppx.ar[0], F_OK) != 0)
		print_error_msg_3(ERR_FILE_DIR, ppx.ar[0], ppx, 127);
	if (access(ppx.ar[0], F_OK | X_OK) != 0)
		print_error_msg_3(ERR_PERM, ppx.ar[0], ppx, 126);
	ppx.path = ppx.ar[0];
	execve(ppx.path, ppx.ar, envp);
}

static void	case_command(t_pipex ppx, char **envp)
{
	ppx.path = get_command(ppx.path_tab, ppx.ar[0]);
	if (!ppx.path)
		print_error_msg_3(ERR_CMD, ppx.ar[0], ppx, 127);
	execve(ppx.path, ppx.ar, envp);
}

void	child_number_one(t_pipex ppx, char **argv, char **envp)
{
	dup2(ppx.fd1, STDIN_FILENO);
	dup2(ppx.pipefd[1], STDOUT_FILENO);
	close_pipes(ppx);
	ppx.i = 0;
	ppx.cmd = ft_split(argv[2], ' ');
	if (argv[2][0] != ' ')
	{
		while (ppx.cmd[ppx.i])
		{
			ppx.ar[ppx.i] = ppx.cmd[ppx.i];
			ppx.i++;
		}
	}
	else
		ppx.ar[ppx.i++] = argv[2];
	ppx.ar[ppx.i] = NULL;
	if (ft_strnstr(ppx.ar[0], "/", ft_strlen(ppx.ar[0])) != 0)
		case_directory(ppx, envp);
	else
		case_command(ppx, envp);
}

void	child_number_two(t_pipex ppx, char **argv, char **envp)
{
	dup2(ppx.pipefd[0], STDIN_FILENO);
	dup2(ppx.fd2, STDOUT_FILENO);
	close_pipes(ppx);
	ppx.i = 0;
	ppx.cmd = ft_split(argv[3], ' ');
	if (argv[3][0] != ' ')
	{
		while (ppx.cmd[ppx.i])
		{
			ppx.ar[ppx.i] = ppx.cmd[ppx.i];
			ppx.i++;
		}
	}
	else
		ppx.ar[ppx.i++] = argv[3];
	ppx.ar[ppx.i] = NULL;
	if (ft_strnstr(ppx.ar[0], "/", ft_strlen(ppx.ar[0])) != 0)
		case_directory(ppx, envp);
	else
		case_command(ppx, envp);
}
