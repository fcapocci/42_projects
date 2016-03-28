#include "minishell.h"

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
	if (!chdir((!ft_strcmp(rep, "/") || !ft_strcmp(rep, "~")) ? rep : path) && !
	access(((!ft_strcmp(rep, "/") || !ft_strcmp(rep, "~")) ? rep : path), F_OK))
		return (quit_char(&path, 1));
	return (quit_char(&path, 0));
}
