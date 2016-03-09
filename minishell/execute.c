/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 21:52:35 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/09 14:32:42 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				execute_cmd(char **args, char **env)
{
	pid_t		pid;
	char		*cmd;
	int			nb;

	cmd = args[0];
	args++;
	pid = fork();
	nb = pid;
	if (pid < 0)
		return (-1);
	if (pid > 0)
		wait(&nb);
	if (pid == 0)
		execve(cmd, args, env);
	return (0);
}
