/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 04:19:53 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/12 03:57:42 by fcapocci         ###   ########.fr       */
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

	tablst_path = tab_list(path);
	start = tablst_path;
	while (*start)
	{
		while (*start)
		{
			if (!ft_strcmp((*start)->pname, (*args)[0]))
			{
				(*args)[0] = ft_strjoin((*start)->ppath, (*start)->pname);
				free_tab_list(&tablst_path, 1);
				return (1);
			}
			(*start) = (*start)->next;
		}
		start++;
	}
	free_tab_list(&tablst_path, 0);
	return (0);
}

int				get_cmd(char *line, t_env *vlist)
{
	char		**args;
	char		**path;
	t_env		*start;
	int			nb;

	start = vlist;
	line = sup_tab(line);
	args = ft_strsplit(line, ' ');
	while (ft_strcmp(vlist->vname, "PATH"))
		vlist = vlist->next;
	path = ft_strsplit(vlist->vcntt, ':');
	vlist = start;
	if ((nb = check_path(&args, path)) != 0)
		if (execute_cmd(args, vlist))
			return (free_get_cmd(&args, &path, &line, -1));
	return (free_get_cmd(&args, &path, &line, nb));
}
