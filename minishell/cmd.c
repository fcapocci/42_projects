/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 04:19:53 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/10 12:19:51 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				check_path(char ***args, char **path)
{
	char		*cmd;

	while (*path)
	{
		cmd = ft_strjoin(*path, (*args)[0]);
		if (!ft_strcmp(*path, cmd))
		{
			(*args)[0] = cmd;
			ft_memdel((void**)&cmd);
			return (0);
		}
		path++;
	}
	ft_memdel((void**)&cmd);
	return (-1);
}

int				get_cmd(char *line, t_env *vlist)
{
	char		**args;
	char		**path;

	line = sup_tab(line);
	args = ft_strsplit(line, ' ');
	while (ft_strcmp(vlist->vname, "PATH"))
		vlist = vlist->next;
	path = ft_strsplit(vlist->vcntt, ':');
	if (check_path(&args, path))
		return (free_get_cmd(&args, &path, &line));
	//if (execute_cmd(args, vlist) == -1);
	//	return (free_get_cmd(&args, &path, &line));
	ft_free_strsplit(&args);
	ft_free_strsplit(&path);
	ft_memdel((void**)&line);
	return (0);
}
