/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 21:52:35 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/09 16:44:53 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			**split_env_list(t_env *vlist)
{
	char		**env;
	char		*line;
	size_t		nb;
	t_env		*tmp;

	tmp = vlist;
	nb = 0;
	while (tmp)
	{
		tmp = tmp->next;
		nb++;
	}
	if (!(env = (char**)ft_memalloc((sizeof(char*) * (nb + 1)))))
		return (NULL);
	nb = 0;
	while (vlist)
	{
		line = ft_strjoin(ft_strjoin(vlist->vname, "="), vlist->vcntt);
		env[nb++] = ft_strnew(ft_strlen(line));
		vlist = vlist->next;
		ft_memdel((void**)&line);
	}
	env[nb] = NULL;
	return (env);
}

int				execute_cmd(char **args, t_env *vlist)
{
	pid_t		pid;
	char		**env;
	char		*cmd;
	int			nb;

	env = split_env_list(vlist);
	cmd = args[0];
	args++;
	pid = fork();
	if (pid < 0)
	{

		return (-1);
	}
	if (pid > 0)
		wait(&nb);
	if (pid == 0)
		execve(cmd, args, env);
	return (0);
}
