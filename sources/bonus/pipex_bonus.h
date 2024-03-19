/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:50:11 by cdutel            #+#    #+#             */
/*   Updated: 2024/03/19 01:30:25 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <unistd.h>
# include "../../libft/libft.h"

# define ERR_ARG "Wrong number of arguments\n"
# define ERR_PATH "No PATH\n"
# define ERR_PIPE "Error with pipe"
# define ERR_FORK "Error with fork"
# define ERR_EXEC "Error with execve\n"
# define ERR_PERM "Permission denied: "
# define ERR_FILE_DIR "No such file or directory: "
# define ERR_CMD "Command not found: "
# define CMD1 2
# define CMD1HD 3
# define FILE_HD "file_hd"

typedef struct s_pipex
{
	int		status;
	int		exit_status;
	int		error_with_file_1;
	int		error_with_file_2;
	int		i;
	int		j;
	int		cmd_number;
	int		n_cmd_to_do;
	int		pid;
	int		pid_to_wait;
	int		pid2;
	int		fd1;
	int		fd2;
	int		tab_size;
	char	*limiter;
	char	*str_hd;
	char	*err_msg;
	char	*err_msg2;
	char	*env_path;
	char	*path;
	char	*ar[10];
	char	**cmd;
	char	**path_tab;
	int		*pids;
	int		**pipes;
}	t_pipex;

/*Childs*/
char	*get_command(char **path_tab, char *cmd_name);
void	case_directory(t_pipex ppx, char **envp);
void	case_command(t_pipex ppx, char **envp);
void	childs_process(t_pipex ppx, int **pipes, char **argv, char **envp);

/*First_last_child*/
void	first_child(t_pipex ppx, int **pipes, char **argv, char **envp);
void	last_child(t_pipex ppx, int **pipes, char **argv, char **envp);
void	inter_child(t_pipex ppx, int **pipes, char **argv, char **envp);

/*Pipex*/
void	print_error_msg(char *err_msg, char *err_msg2);
void	print_error_msg_2(char *err_msg);
void	print_error_msg_3(char *err_msg, char *err_msg2, t_pipex ppx, int ex);

/*Utils*/
void	free_all(t_pipex ppx);
void	ft_le_xav(char **dest);
void	free_int_tab(int **pipes, int tab_size);
void	close_pipes(t_pipex ppx, int **pipes);
int		wait_for_childs(t_pipex ppx, int pids);
t_pipex	init_ppx(void);

/*Without_here_doc*/
int		without_here_doc(int argc, char **argv, char **envp);
void	get_path(int argc, char **argv, char **envp, t_pipex *ppx);
int		**open_pipes(int taille, t_pipex *ppx);
int		check_acces(int argc, char **argv, t_pipex ppx);

/*Here_doc*/
int		here_doc(int argc, char **argv, char **envp);

#endif
