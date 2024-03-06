/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:35:04 by cdutel            #+#    #+#             */
/*   Updated: 2024/03/04 18:49:47 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	childs_process(t_pipex ppx, char **argv, char **envp)
{
	if (!argv || !envp)
		return ;
	//ft_printf("%d\n", ppx.n_fork_to_do);
	ft_printf("child process\n");
	ppx.i = 0;
}
