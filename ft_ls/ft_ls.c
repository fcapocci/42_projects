/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:38:23 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/13 15:13:25 by fcapocci         ###   ########.fr       */
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
	argv2 = sort_arg(optl, argv);
	while (argc-- > 1)
	{
		lstat(*argv, &stats);
		if (take_type(stats.st_mode) != 'd')
			read_file(&flist[0], &flist[1], *argv);
		argv++;
	}
	if (flist[1])
		print_file(optl, flist[1]);
	while (save-- > 1)
	{
		lstat(*argv2, &stats);
		if (take_type(stats.st_mode) == 'd')
		{
			print_path(*argv2, save + 1, flist[1]);
			if ((read_dir(optl, list, *argv2)) == -1)
				return (-1);
		}
		argv2++;
	}
	ft_memdel((void**)&flist);
	return (0);
}

int			read_file(t_dir **flist, t_dir **first, char *dirname)
{
	if (!(*flist))
	{
		(*flist) = get_content(dirname);
		(*flist)->prev = NULL;
		(*first) = (*flist);
	}
	else
	{
		(*flist)->next = get_content(dirname);
		(*flist)->next->prev = (*flist);
		(*flist) = (*flist)->next;
	}
	return (0);
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
			sort_list(optl, &list, &slist, ft_strjoin(path, dir->d_name));
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
