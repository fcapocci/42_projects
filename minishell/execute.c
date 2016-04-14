/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 21:52:35 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/13 18:56:47 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			**split_env_list(t_env *vlist)
{
	char		**env;
	char		*line;
	char		*tmp;
	size_t		nb;

	nb = 0;
	nb = ft_count_list((t_list*)vlist);
	if (!(env = (char**)ft_memalloc((sizeof(char*) * (nb + 1)))))
		return (NULL);
	nb = 0;
	while (vlist)
	{
		tmp = ft_strjoin(vlist->vname, "=");
		line = ft_strjoin(tmp, vlist->vcntt);
		ft_memdel((void**)&tmp);
		env[nb++] = ft_strdup(line);
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
	args = scan_tld(args, vlist);
	pid = fork();
	if (pid < 0)
	{
		ft_free_strsplit(&env);
		return (-1);
	}
	if (pid > 0)
		wait(&nb);
	if (pid == 0)
		execve(cmd, args, env);
	ft_free_strsplit(&env);
	return (0);
}

int				exe_builtins(char *line, t_env **vlist)
{
	char		**args;

	line = sup_tab(line);
	args = ft_strsplit(line, ' ');
	if (!ft_strcmp("env", args[0]))
		print_env(*vlist);
	if (!ft_strcmp("setenv", args[0]))
		(*vlist) = set_env((*vlist), args, 0);
	if (!ft_strcmp("unsetenv", args[0]))
		unset_env(&(*vlist), args);
	if (!ft_strcmp("cd", args[0]))
		(*vlist) = cd_env((*vlist), args);
	quit_builts(&line, &args);
	return (0);
}
