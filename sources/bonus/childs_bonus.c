/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:35:04 by cdutel            #+#    #+#             */
/*   Updated: 2024/03/19 01:35:46 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*get_command(char **path_tab, char *cmd_name)
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

void	case_directory(t_pipex ppx, char **envp)
{
	if (access(ppx.ar[0], F_OK) != 0)
		print_error_msg_3(ERR_FILE_DIR, ppx.ar[0], ppx, 127);
	if (access(ppx.ar[0], F_OK | X_OK) != 0)
		print_error_msg_3(ERR_PERM, ppx.ar[0], ppx, 126);
	ppx.path = ppx.ar[0];
	if (execve(ppx.path, ppx.ar, envp) < 0)
	{
		free_all(ppx);
		print_error_msg_2(ERR_EXEC);
	}
}

void	case_command(t_pipex ppx, char **envp)
{
	ppx.path = get_command(ppx.path_tab, ppx.ar[0]);
	if (ppx.ar[0][0] == '\0')
	{
		free(ppx.path);
		print_error_msg_3(ERR_PERM, ppx.ar[0], ppx, 126);
	}
	if (!ppx.path)
		print_error_msg_3(ERR_CMD, ppx.ar[0], ppx, 127);
	if (execve(ppx.path, ppx.ar, envp) < 0)
	{
		free_all(ppx);
		print_error_msg_2(ERR_EXEC);
	}
}

void	childs_process(t_pipex ppx, int **pipes, char **argv, char **envp)
{
	if (ppx.i == 0)
	{
		if (ppx.error_with_file_1 == 1)
		{
			free_all(ppx);
			close_pipes(ppx, pipes);
			exit(1);
		}
		first_child(ppx, pipes, argv, envp);
	}
	else if (ppx.i == ppx.n_cmd_to_do - 1)
	{
		if (ppx.error_with_file_2 == 1)
		{
			free_all(ppx);
			close_pipes(ppx, pipes);
			exit(1);
		}
		last_child(ppx, pipes, argv, envp);
	}
	else
	{
		inter_child(ppx, pipes, argv, envp);
	}
}
