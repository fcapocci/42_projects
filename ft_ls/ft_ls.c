/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:38:23 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/06 18:39:13 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*manage_rep(char **argv)
{
	char			*dirname;

	dirname = NULL;
	while (argv[1][0] == '-')
		argv++;
	dirname = argv[1];
	return (dirname);
}

int		read_dir(t_opt *optl, t_dir *list, char *dirname)
{
	DIR				*rep;
	struct dirent	*dir;
	t_dir			*slist;
	char			*path;

	ft_memdel((void**)&list);
	path = ft_strjoin(dirname, "/");
	slist = list;
	if ((rep = opendir(dirname)) == NULL)
		exit(-1);
	while ((dir = readdir(rep)))
	{
		if ((option_ok(optl, 'a') == 0 && dir->d_name[0] != '.') ||
			(option_ok(optl, 'a') == 1 && dir->d_name[0] == '.') ||
			(option_ok(optl, 'a') == 1 && dir->d_name[0] != '.'))
		{
			if (!slist)
			{
				slist = get_content(ft_strjoin(path, dir->d_name));
				slist->prev = NULL;
				list = slist;
			}
			else
			{
				slist->next = get_content(ft_strjoin(path, dir->d_name));
				slist->next->prev = slist;
				slist = slist->next;
			}
		}
	}
	closedir(rep);
	printing(optl, list);
	return (0);
}

t_dir	*get_content(char *entity)
{
	struct stat		stats;
	t_dir			*list;

	if ((list = (t_dir*)ft_memalloc(sizeof(t_dir))) == NULL)
		return (NULL);
	lstat(entity, &stats);
	list->type = take_type(stats.st_mode);
	list->modes = take_modes(stats.st_mode);
	list->nblink = stats.st_nlink;
	list->owner = getpwuid(stats.st_uid)->pw_name;
	list->grp = getgrgid(stats.st_gid)->gr_name;
	list->tall = stats.st_size;
	list->date = dating(&stats.st_mtime);
	list->numdate = stats.st_mtime;
	list->name = strdup(entity);
	list->next = NULL;
	return (list);
}
