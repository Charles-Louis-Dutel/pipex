/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:48:40 by cdutel            #+#    #+#             */
/*   Updated: 2024/02/15 18:05:06 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char *path = NULL;

	int (fd) = 0;
	//int (fd2) = 0;
	char *ar[] = {argv[2], argv[1], NULL};

	if (argc == 3)
	{
		fd = open(argv[1], O_RDWR);
		if (fd == -1)
		{
			perror(argv[1]);
			return (1);
		}
		path = ft_strjoin(PATH, argv[2]);
		if(execve(path, ar, envp) == -1)
		{
			ft_printf("Invalid command or path\n");
			free(path);
			return(1);
		}

		//fd2 = open(argv[4], O_RDWR | O_CREAT, 0644);
	}
	return (0);
}

// int main()
// {
//     char *args[] = {"cat", "test.txt", NULL};
//     if (execve("/usr/bin/cat", args, NULL) == -1) {
//         perror("execve");
//     }
//     return 0;
// }
