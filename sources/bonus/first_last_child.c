/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_last_child.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:50:02 by cdutel            #+#    #+#             */
/*   Updated: 2024/03/11 17:18:19 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_child(t_pipex ppx, int pipes[][2], char **argv, char **envp)
{
	dup2(ppx.fd1, STDIN_FILENO);
	dup2(pipes[ppx.i + 1][1], STDOUT_FILENO);
	//close_pipes(ppx);
	close_pipes_2(ppx, pipes);
	ppx.j = 0;
	ppx.cmd = ft_split(argv[ppx.cmd_number], ' ');
	if (argv[ppx.cmd_number][0] != ' ')
	{
		while (ppx.cmd[ppx.j])
		{
			ppx.ar[ppx.j] = ppx.cmd[ppx.j];
			ppx.j++;
		}
	}
	else
		ppx.ar[ppx.j++] = argv[ppx.cmd_number];
	ppx.ar[ppx.j] = NULL;
	if (ft_strnstr(ppx.ar[0], "/", ft_strlen(ppx.ar[0])) != 0)
		case_directory(ppx, envp);
	else
		case_command(ppx, envp);
}

void	last_child(t_pipex ppx, int pipes[][2], char **argv, char **envp)
{
	dup2(pipes[ppx.i][0], STDIN_FILENO);
	dup2(ppx.fd2, STDOUT_FILENO);
	//close_pipes(ppx);
	close_pipes_2(ppx, pipes);
	ppx.j = 0;
	ppx.cmd = ft_split(argv[ppx.cmd_number], ' ');
	if (argv[ppx.cmd_number][0] != ' ')
	{
		while (ppx.cmd[ppx.j])
		{
			ppx.ar[ppx.j] = ppx.cmd[ppx.j];
			ppx.j++;
		}
	}
	else
		ppx.ar[ppx.j++] = argv[ppx.cmd_number];
	ppx.ar[ppx.j] = NULL;
	if (ft_strnstr(ppx.ar[0], "/", ft_strlen(ppx.ar[0])) != 0)
		case_directory(ppx, envp);
	else
		case_command(ppx, envp);
}

void	inter_child(t_pipex ppx, int pipes[][2], char **argv, char **envp)
{
	dup2(pipes[ppx.i][0], STDIN_FILENO);
	dup2(pipes[ppx.i + 1][1], STDOUT_FILENO);
	close_pipes_2(ppx, pipes);
	ppx.j = 0;
	ppx.cmd = ft_split(argv[ppx.cmd_number], ' ');
	if (argv[ppx.cmd_number][0] != ' ')
	{
		while (ppx.cmd[ppx.j])
		{
			ppx.ar[ppx.j] = ppx.cmd[ppx.j];
			ppx.j++;
		}
	}
	else
		ppx.ar[ppx.j++] = argv[ppx.cmd_number];
	ppx.ar[ppx.j] = NULL;
	if (ft_strnstr(ppx.ar[0], "/", ft_strlen(ppx.ar[0])) != 0)
		case_directory(ppx, envp);
	else
		case_command(ppx, envp);
}
