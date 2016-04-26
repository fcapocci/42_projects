/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 04:19:53 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/26 11:30:02 by fcapocci         ###   ########.fr       */
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

int				cmp_rpl(t_path *tmp, char ****args)
{
	char		*line_path;

	line_path = ft_strjoin(tmp->ppath, tmp->pname);
	if ((!ft_strcmp(tmp->pname, (**args)[0])) && ft_typefile(line_path) == 'd')
		return (quit_char(&line_path, -2));
	if ((!ft_strcmp(tmp->pname, (**args)[0])) && ft_typefile(line_path) != 'd')
	{
		ft_memdel((void**)&(**args)[0]);
		(**args)[0] = ft_strjoin(tmp->ppath, tmp->pname);
		if (!access((**args)[0], X_OK))
			return (quit_char(&line_path, 1));
		else
			return (quit_char(&line_path, -2));
	}
	return (quit_char(&line_path, 0));
}

int				check_line(char **args)
{
	if (access(args[0], F_OK) == 0 && ft_typefile(args[0]) == 'd')
		return (-2);
	if (access(args[0], F_OK) == 0 && ft_typefile(args[0]) != 'd')
	{
		if (!access(args[0], X_OK))
			return (1);
		else
			return (-2);
	}
	return (0);
}

int				check_path(char ***args, char **path)
{
	t_path		**tp;
	t_path		**start;
	t_path		*tmp;
	int			i;
	int			ret;

	i = 0;
	if ((tp = tab_list(path)) == NULL)
		return (free_tab_list(&tp, 0));
	start = tp;
	while (start[i])
	{
		tmp = start[i];
		while (tmp && tmp->pname && tmp->ppath)
		{
			if ((ret = cmp_rpl(tmp, &args)) != 0)
				return (free_tab_list(&tp, ret));
			tmp = tmp->next;
		}
		i++;
	}
	return (free_tab_list(&tp, 0));
}

int				get_cmd(char *line, t_env *vlist)
{
	char		**args;
	char		**path;
	t_env		*start;
	int			nb;

	nb = 0;
	start = vlist;
	if ((args = scan_tld(ft_strsplit(line, ' '), vlist)) == NULL)
		return (quit_char(&line, 0));
	while (vlist && vlist->vname && ft_strcmp(vlist->vname, "PATH")
	&& vlist->next)
		vlist = vlist->next;
	path = NULL;
	if (ft_strchr(args[0], '/'))
	{
		if ((nb = check_line(args)) > 0)
			if (execute_cmd(args, start))
				return (free_get_cmd(&args, &path, &line, -1));
	}
	else if ((path = ft_strsplit(vlist->vcntt, ':')) != NULL)
		if ((nb = check_path(&args, path)) > 0)
			if (execute_cmd(args, start))
				return (free_get_cmd(&args, &path, &line, -1));
	error_cmd(nb, args[0]);
	return (free_get_cmd(&args, &path, &line, nb));
}
