/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 04:19:53 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/31 05:43:21 by fcapocci         ###   ########.fr       */
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
	if (!(tab_list = (t_path**)ft_memalloc(sizeof(t_path*) * (cmpt + 1))))
		return (NULL);
	while (i < cmpt)
	{
		if ((tab_list[i] = creat_plist(*path)))
			i++;
		path++;
	}
	tab_list[i] = NULL;
	return (tab_list);
}

int				check_path(char ***args, char **path)
{
	t_path		**tablst_path;
	t_path		**start;
	t_path		*tmp;
	int			i;

	i = 0;
	if ((tablst_path = tab_list(path)) == NULL)
		return (free_tab_list(&tablst_path, 0));
	start = tablst_path;
	while (start[i])
	{
		tmp = start[i];
		while (tmp && tmp->pname)
		{
			if (!ft_strcmp(tmp->pname, (*args)[0]))
			{
				ft_memdel((void**)&(*args)[0]);
				(*args)[0] = ft_strjoin(tmp->ppath, tmp->pname);
				if (access((*args)[0], X_OK) != 0)
					return (free_tab_list(&tablst_path, 0));
				return (free_tab_list(&tablst_path, 1));
			}
			tmp = tmp->next;
		}
		i++;
	}
	return (free_tab_list(&tablst_path, 0));
}

int				get_cmd(char *line, t_env *vlist)
{
	char		**args;
	char		**path;
	t_env		*start;
	int			nb;

	nb = 0;
	start = vlist;
	line = sup_tab(line);
	if ((args = ft_strsplit(line, ' ')) == NULL)
	{
		ft_memdel((void**)&line);
		return (0);
	}
	while (ft_strcmp(vlist->vname, "PATH") && vlist->next)
		vlist = vlist->next;
	if ((path = ft_strsplit(vlist->vcntt, ':')) != NULL)
	{
		vlist = start;
		if ((nb = check_path(&args, path)) != 0)
			if (execute_cmd(args, vlist))
				return (free_get_cmd(&args, &path, &line, -1));
	}
	return (free_get_cmd(&args, &path, &line, nb));
}
