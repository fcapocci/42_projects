/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 04:19:53 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/12 23:43:52 by fcapocci         ###   ########.fr       */
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
	if ((!ft_strcmp(line_path, (**args)[0])
	|| !ft_strcmp(tmp->pname, (**args)[0])) && ft_typefile(line_path) == 'd')
		return (quit_char(&line_path, -2));
	if ((!ft_strcmp(line_path, (**args)[0])
	|| !ft_strcmp(tmp->pname, (**args)[0])) && ft_typefile(line_path) != 'd')
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

int				cmp_rpl2(char ****args)
{
	char		*buff;
	char		*tmp;
	char		*line_path;

	buff = ft_strnew(255);
	getcwd(buff, 255);
	tmp = (**args)[0];
	tmp++;
	line_path = ft_strjoin(buff, tmp);
	if (access(line_path, F_OK) == 0 && ft_typefile(line_path) == 'd')
		return (quit_dubblechar(&buff, &line_path, -2));
	if (access(line_path, F_OK) == 0 && ft_typefile(line_path) != 'd')
	{
		ft_memdel((void**)&(**args)[0]);
		(**args)[0] = ft_strdup(line_path);
		if (!access((**args)[0], X_OK))
			return (quit_dubblechar(&buff, &line_path, 1));
		else
			return (quit_dubblechar(&buff, &line_path, -2));
	}
	return (quit_dubblechar(&buff, &line_path, 0));
}

int				check_path(char ***args, char **path)
{
	t_path		**tp;
	t_path		**start;
	t_path		*tmp;
	int			i;
	int			ret;

	i = 0;
	if ((*args)[0][0] == '.' && (*args)[0][1] == '/')
		if ((ret = cmp_rpl2(&args)) != 0)
			return (ret);
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
	line = sup_tab(line);
	if ((args = ft_strsplit(line, ' ')) == NULL)
		return (quit_char(&line, 0));
	while (ft_strcmp(vlist->vname, "PATH") && vlist->next)
		vlist = vlist->next;
	if ((path = ft_strsplit(vlist->vcntt, ':')) != NULL)
	{
		vlist = start;
		if ((nb = check_path(&args, path)) > 0)
			if (execute_cmd(args, vlist))
				return (free_get_cmd(&args, &path, &line, -1));
	}
	if (nb == 0)
		no_cmd(args[0]);
	if (nb < 0)
		not_perms(args[0]);
	return (free_get_cmd(&args, &path, &line, nb));
}
