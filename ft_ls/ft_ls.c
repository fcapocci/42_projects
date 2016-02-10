/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:38:23 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/10 20:20:53 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			manage(int argc, char **argv, t_opt *optl, t_dir *list)
{
	char			*dirname;
	t_dir			*flist;

	flist = NULL;
	dirname = NULL;
	if (argc == 1)
	{
		dirname = ft_strnew(1);
		dirname[0] = '.';
		if ((read_dir(optl, flist, dirname)) == -1)
			return (-1);
		exit(0);
	}
	else
		manage_read(argc, argv, optl, list);
	return (0);
}

int			manage_read(int argc, char **argv, t_opt *optl, t_dir *list)
{
	char			**argv2;
	struct stat		stats;
	t_dir			*flist[2];
	int				save;

	flist[0] = NULL;
	flist[1] = NULL;
	save = argc;
	argv2 = argv;
	while (argc-- > 1)
	{
		lstat(*argv, &stats);
		if (take_type(stats.st_mode) != 'd')
			flist[0] = read_file(flist[1], (*argv)++);
		if (!flist[1])
			flist[1] = flist[0];
	}
	print_file(optl, flist[1], flist[0]);
	ft_memdel((void**)&flist);
	while (save-- > 1)
	{
		lstat(*argv2, &stats);
		if (take_type(stats.st_mode) == 'd')
			if ((read_dir(optl, list, *argv2++)) == -1)
				return (-1);
	}
	return (0);
}

t_dir		*read_file(t_dir *flist, char *dirname)
{
	t_dir			*newlist;

	newlist = NULL;
	if (!flist)
	{
		newlist = get_content(dirname);
		newlist->prev = NULL;
	}
	else
	{
		newlist->next = get_content(dirname);
		newlist->next->prev = newlist;
		newlist = newlist->next;
	}
	return (newlist);
}

int			read_dir(t_opt *optl, t_dir *list, char *dirname)
{
	DIR				*rep;
	struct dirent	*dir;
	t_dir			*slist;
	char			*path;

	path = ft_strjoin(dirname, "/");
	slist = list;
	if ((rep = opendir(dirname)) == NULL)
		exit(-1);
	while ((dir = readdir(rep)))
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
	closedir(rep);
	printing(optl, list, slist);
	ft_memdel((void**)&list);
	return (0);
}

t_dir		*get_content(char *entity)
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
	list->blksize = stats.st_blocks;
	list->name = strdup(entity);
	list->next = NULL;
	return (list);
}
