/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 19:25:19 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/21 11:20:41 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <dirent.h>

t_env			*new_link(char *env)
{
	t_env			*link;
	int				len;

	if (env == NULL)
	{
		if ((link = (t_env*)ft_memalloc(sizeof(t_env))) == NULL)
			return (NULL);
		link->vname = NULL;
		link->vcntt = NULL;
		link->next = NULL;
	}
	else
	{
		len = ft_strlen(env) - ft_strlen(ft_strchr(env, '='));
		if ((link = (t_env*)ft_memalloc(sizeof(t_env))) == NULL)
			return (NULL);
		link->vname = ft_strsub(env, 0, len);
		link->vcntt = ft_strsub(env, len + 1, ft_strlen(env) - len);
		link->next = NULL;
	}
	return (link);
}

t_env			*creat_list(char **env)
{
	t_env			*list[2];

	list[0] = NULL;
	list[1] = NULL;
	if (len_y(env) == 0)
		if ((list[1] = new_link(NULL)) == NULL)
			return (NULL);
	while (*env)
	{
		if (!list[0])
		{
			if ((list[0] = new_link(*env)) == NULL)
				return (NULL);
			if (!list[1])
				list[1] = list[0];
		}
		else
		{
			if ((list[0]->next = new_link(*env)) == NULL)
				return (NULL);
			list[0] = list[0]->next;
		}
		env++;
	}
	return (list[1]);
}

t_path			*new_plink(char *path, char *d_name)
{
	t_path			*plink;

	if ((plink = (t_path*)ft_memalloc(sizeof(t_path))) == NULL)
		return (NULL);
	plink->ppath = ft_strjoin(path, "/");
	plink->pname = (d_name != NULL ? ft_strdup(d_name) : NULL);
	plink->next = NULL;
	return (plink);
}

t_path			*creat_plist(char *path)
{
	DIR				*rep;
	struct dirent	*dir;
	t_path			*plist[2];

	plist[0] = NULL;
	if ((rep = opendir(path)) == NULL)
		return (new_plink(path, NULL));
	while ((dir = readdir(rep)))
	{
		if (ft_strcmp(dir->d_name, ".") && ft_strcmp(dir->d_name, ".."))
		{
			if (!plist[0])
			{
				plist[0] = new_plink(path, dir->d_name);
				plist[1] = plist[0];
			}
			else
			{
				plist[0]->next = new_plink(path, dir->d_name);
				plist[0] = plist[0]->next;
			}
		}
	}
	closedir(rep);
	return (plist[1]);
}
