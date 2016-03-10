/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 04:19:53 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/10 14:36:39 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_path			**tab_list(char **path)
{
	t_path		**tab_list;
	size_t		cmpt;
	size_t		i;

	i = 0;
	cmpt = 0;
	while (path[cmpt])
		cmpt++;
	tab_list = (t_path**)ft_memalloc(sizeof(t_path*) * (cmpt + 1));
	while (i <= cmpt)
	{
		tab_list[i] = creat_plist(*path);
		path++;
		i++;
	}
	tab_list[i] = NULL;
	return(tab_list);
}

int				check_path(char ***args, char **path)
{
	char		*cmd;
	t_path		**tablst_path;

	tablst_path = tab_list(path);
	cmd = ft_strjoin(*path, (*args)[0]);
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
	ft_free_strsplit(&args);
	ft_free_strsplit(&path);
	ft_memdel((void**)&line);
	return (0);
}
