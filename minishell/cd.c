/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 21:50:07 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/05 12:41:54 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				error_cd(char *str, char *path, int nb)
{
	ft_putstr(str);
	ft_putendl(path);
	return (nb);
}

int				check_droit(char *path)
{
	if (access(path, F_OK) == -1)
		return (error_cd("cd: no such file or directory: ", path, -1));
	if (chdir(path) == -1)
		return (error_cd("cd: permission denied: ", path, -1));
	return (1);
}

int				get_home_old(t_env *vlist, char *type)
{
	while (vlist)
	{
		if (ft_strcmp(vlist->vname, type) == 0)
		{
			if (ft_strcmp(type, "OLDPWD") == 0)
				ft_putendl(vlist->vcntt);
			if (chdir(vlist->vcntt) == -1)
				return (error_cd("cd: no such file or directory: ",
				vlist->vcntt, -1));
			else
				return (-1);
		}
		vlist = vlist->next;
	}
	return (error_cd("cd: no such file or directory: ", type, -1));
}

int				change_directory(char *path, t_env **vlist)
{
	if ((path == NULL || path == '\0'))
		get_home_old(*vlist, "HOME");
	else if (ft_strcmp(path, "~") == 0 || ft_strcmp(path, "-") == 0)
		get_home_old(*vlist, path[0] == '~' ? "HOME" : "OLDPWD");
	else
	{
		if (check_droit(path) == -1)
			return (-1);
	}
	return (0);
}

t_env			*cd_env(t_env *vlist, char **args)
{
	char		mem[256];
	char		*line;
	char		**split;

	split = NULL;
	if (len_y(args) != 2)
		return (vlist);
	getcwd(mem, 256);
	if (change_directory(args[1], &vlist) == -1)
		return (vlist);
	line = ft_strjoin("unsetenv ", "OLDPWD");
	unset_env(&vlist, (split = ft_strsplit(line, ' ')));
	quit_builts(&line, &split);
	line = ft_strjoin("setenv OLDPWD=", mem);
	vlist = set_env(vlist, (split = ft_strsplit(line, ' ')), 0);
	quit_builts(&line, &split);
	getcwd(mem, 256);
	line = ft_strjoin("unsetenv ", "PWD");
	unset_env(&vlist, (split = ft_strsplit(line, ' ')));
	quit_builts(&line, &split);
	line = ft_strjoin("setenv PWD=", mem);
	vlist = set_env(vlist, (split = ft_strsplit(line, ' ')), 0);
	quit_builts(&line, &split);
	return (vlist);
}
