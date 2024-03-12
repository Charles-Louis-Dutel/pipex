/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:35:04 by cdutel            #+#    #+#             */
/*   Updated: 2024/03/12 11:49:34 by cdutel           ###   ########.fr       */
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

void	print_old_pwd(char **envp)
{
	int (i) = 0;
	while (envp[i])
	{
		if (ft_strncmp("OLDPWD=", envp[i], 7) == 0)
		{
			ft_printf("/%s\n", envp[i] + 8);
			exit(0);
		}
		i++;
	}
}

void	case_command(t_pipex ppx, char **envp)
{
	if (ft_strncmp("pwd", ppx.ar[0], 4) == 0)
		print_old_pwd(envp);
	else
	{
		ppx.path = get_command(ppx.path_tab, ppx.ar[0]);
		if (!ppx.path || ppx.ar[0][0] == '\0')
			print_error_msg_3(ERR_CMD, ppx.ar[0], ppx, 127);
	}
	execve(ppx.path, ppx.ar, envp);
}

void	childs_process(t_pipex ppx, int pipes[][2], char **argv, char **envp)
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
