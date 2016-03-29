/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 21:50:07 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/29 12:28:43 by fcapocci         ###   ########.fr       */
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
/*
int				get_home_old(t_env *env, char *type)
{
	return(1);
}

int				change_directory(char *path, t_env **vlist)
{
	return (0);
}
*/
t_env			*cd_env(t_env *vlist, char **args)
{
	char		mem[256];
	char		*line;
	char		**split;

	split = NULL;
	if (len_y(args) != 2)
		return (vlist);
	getcwd(mem, 256);
	//if (change_directory(args[1], &vlist) == -1)
	if (move_ok(vlist, args[1]) != 1)
		return (vlist);
	line = ft_strjoin("unsetenv ", "OLDPWD");
	unset_env(&vlist, (split = ft_strsplit(line, ' ')));
	ft_free_strsplit(&split);
	ft_memdel((void**)&line);
	line = ft_strjoin("setenv OLDPWD=", mem);
	vlist = set_env(vlist, (split = ft_strsplit(line, ' ')), 0);
	ft_free_strsplit(&split);
	ft_memdel((void**)&line);
	getcwd(mem, 256);
	line = ft_strjoin("unsetenv ", "PWD");
	unset_env(&vlist, (split = ft_strsplit(line, ' ')));
	ft_free_strsplit(&split);
	ft_memdel((void**)&line);
	line = ft_strjoin("setenv PWD=", mem);
	vlist = set_env(vlist, (split = ft_strsplit(line, ' ')), 0);
	ft_free_strsplit(&split);
	ft_memdel((void**)&line);
	return (vlist);
}
