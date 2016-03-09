/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 04:19:53 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/09 15:05:03 by fcapocci         ###   ########.fr       */
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

char			*sup_tab(char *line)
{
	char		*new_line;
	size_t		i;
	size_t		p;
	char		tmp;

	new_line = ft_strnew(ft_strlen(line));
	i = 0;
	p = 0;
	while (i <= ft_strlen(line))
	{
		if (i == 0 && (line[i] == ' ' || line[i] == 9))
			while (line[i] == ' ' || line[i] == 9)
				i++;
		if (line[i] == 9)
			tmp = ' ';
		else
			tmp = line[i];
		new_line[p++] = tmp;
		while (line[i + 1] && (line[i] == ' ' || line[i] == 9) &&
		(line[i + 1] == ' ' || line[i + 1] == 9))
			i++;
		i++;
	}
	return (new_line);
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
	//execute_cmd(args, env);
	//	return (free_get_cmd(&args, &path, &line));
	ft_free_strsplit(&args);
	ft_free_strsplit(&path);
	ft_memdel((void**)&line);
	return (0);
}
