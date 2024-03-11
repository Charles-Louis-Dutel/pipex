/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:35:04 by cdutel            #+#    #+#             */
/*   Updated: 2024/03/11 17:15:09 by cdutel           ###   ########.fr       */
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
	execve(ppx.path, ppx.ar, envp);
}

void	case_command(t_pipex ppx, char **envp)
{
	ppx.path = get_command(ppx.path_tab, ppx.ar[0]);
	if (!ppx.path)
		print_error_msg_3(ERR_CMD, ppx.ar[0], ppx, 127);
	execve(ppx.path, ppx.ar, envp);
}

void	childs_process(t_pipex ppx, int pipes[][2], char **argv, char **envp)
{
	if (ppx.i == 0)
	{
		first_child(ppx, pipes, argv, envp);
	}
	else if (ppx.i == ppx.n_cmd_to_do - 1)
	{
		last_child(ppx, pipes, argv, envp);
	}
	else
	{
		inter_child(ppx, pipes, argv, envp);
	}
}
