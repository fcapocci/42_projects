/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 21:52:35 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/08 23:00:49 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				execute_cmd(char **args, char **env)
{
	pid_t		pid;
	char		*cmd;

	cmd = args[0];
	args++;
	pid = fork();
	if (pid > 0)
		wait(&pid);
	if (pid == 0)
		execve(cmd, args, env);
	return (0);
}
