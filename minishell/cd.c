#include "minishell.h"

void			new_path(char **path, char *rep)
{
	char		*tmp;
	char		*ptr;

	ptr = ft_strchr((*path), '/');
	tmp = (*path);
	while (ft_strchr(ptr, '/'))
	{
		ptr = ft_strchr(ptr, '/');
		ptr++;
	}
	if (!ft_strcmp(rep, ".."))
		(*path) = ft_strsub(tmp, 0, (ft_strlen(tmp) - ft_strlen(ptr)) - 1);
	else if (!ft_strcmp(rep, "/"))
		(*path) = ft_strdup(rep);
	else
	{
		(*path) = ft_strjoin(tmp, "/");
		ft_memdel((void**)&tmp);
		tmp = (*path);
		(*path) = ft_strjoin(tmp, rep);
	}
	ft_memdel((void**)&tmp);
}

t_env			*change_pwd(t_env *vlist, char *rep)
{
	t_env		*nvlist;
	t_env		*tmplist;
	char		*tmp;
	char		*path;

	tmplist = vlist;
	nvlist = vlist;
	while (ft_strcmp(vlist->vname, "PWD") != 0 && vlist->next)
		vlist = vlist->next;
	path = ft_strjoin(vlist->vcntt, "/");
	tmp = path;
	path = ft_strjoin(path, rep);
	ft_memdel((void**)&tmp);
	while (ft_strcmp(tmplist->vname, "OLDPWD") != 0 && tmplist->next)
		tmplist = tmplist->next;
	if (ft_strcmp(tmplist->vname, "OLDPWD"))
	{
		ft_memdel((void**)&path);
		return (nvlist);
	}
	ft_memdel((void**)&tmplist->vcntt);
	tmplist->vcntt = ft_strdup(vlist->vcntt);
	new_path(&vlist->vcntt, rep);
	ft_memdel((void**)&path);
	return (nvlist);
}

int				move_ok(t_env *vlist, char *rep)
{
	char		*path;
	char		*tmp;

	while (ft_strcmp(vlist->vname, "PWD") != 0 && vlist->next)
		vlist = vlist->next;
	path = ft_strcmp(rep, "/") ? ft_strjoin(vlist->vcntt, "/") : ft_strdup("/");
	tmp = path;
	path = ft_strjoin(path, rep);
	ft_memdel((void**)&tmp);
	if (ft_strcmp(vlist->vname, "PWD"))
		return (quit_char(&path, -1));
	if (!chdir((!ft_strcmp(rep, "/") || !ft_strcmp(rep, "~")) ? rep : path) &&
	!access(((!ft_strcmp(rep, "/") || !ft_strcmp(rep, "~")) ? rep : path), F_OK))
		return (quit_char(&path, 1));
	return (quit_char(&path, 0));
}

t_env			*cd_env(t_env *vlist, char **args)
{
	int			len;
	int			ret;
	t_env		*start;

	start = vlist;
	len = len_y(args);
	if (len != 2)
		return (vlist);
	while (ft_strcmp(vlist->vname, "HOME") && vlist->next)
		vlist = vlist->next;
	if (!ft_strcmp(vlist->vname, "HOME") && !ft_strcmp(args[1], "~"))
	{
		ft_memdel((void**)&args[1]);
		args[1] = ft_strdup(vlist->vcntt);
	}
	vlist = start;
	if ((ret = move_ok(vlist, args[1])) == 1)
		vlist = change_pwd(vlist, args[1]);
	if (ret == 0)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(args[1]);
	}
	return (vlist);
}
