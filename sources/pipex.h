/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:48:58 by cdutel            #+#    #+#             */
/*   Updated: 2024/03/19 01:30:20 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

# define ERR_ARG "Wrong number of arguments\n"
# define ERR_PATH "No PATH\n"
# define ERR_PIPE "Error with pipe"
# define ERR_FORK "Error with fork"
# define ERR_EXEC "Error with execve\n"
# define ERR_PERM "Permission denied: "
# define ERR_FILE_DIR "No such file or directory: "
# define ERR_CMD "Command not found: "

typedef struct s_pipex
{
	int		status;
	int		exit_status;
	int		error_with_file_1;
	int		error_with_file_2;
	int		i;
	int		pid;
	int		pid1;
	int		pid2;
	int		fd1;
	int		fd2;
	int		pipefd[2];
	char	*err_msg;
	char	*err_msg2;
	char	*env_path;
	char	*path;
	char	*ar[6];
	char	**cmd;
	char	**path_tab;
}	t_pipex;

/*Childs*/
void	child_number_one(t_pipex ppx, char **argv, char **envp);
void	child_number_two(t_pipex ppx, char **argv, char **envp);

/*Pipex*/
void	print_error_msg(char *err_msg, char *err_msg2);
void	print_error_msg_2(char *err_msg);
void	print_error_msg_3(char *err_msg, char *err_msg2, t_pipex ppx, int ex);

/*Utils*/
void	free_all(t_pipex ppx);
void	ft_le_xav(char **dest);
void	close_pipes(t_pipex ppx);

#endif
