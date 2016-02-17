/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:38:23 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/17 02:47:08 by fcapocci         ###   ########.fr       */
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
	t_arg			*arg[2];
	t_dir			*flist[2];

	flist[1] = NULL;
	flist[0] = NULL;
	arg[0] = read_arg(optl, argc, argv);
	arg[1] = arg[0];
	while (arg[0])
	{
		if (arg[0]->type != 'd')
			read_file(&flist[0], &flist[1], arg[0]->argument);
		arg[0] = (option_ok(optl, 'r') == 1 ? arg[0]->prev : arg[0]->next);
	}
	if (flist[1])
		print_file(optl, flist[1]);
	while (arg[1])
	{
		if (arg[1]->type == 'd')
		{
			print_path(arg[1]->argument, argc, flist[1]);
			if ((read_dir(optl, list, arg[1]->argument)) == -1)
				return (-1);
		}
		arg[1] = (option_ok(optl, 'r') == 1 ? arg[1]->prev : arg[1]->next);
	}
	ft_memdel((void**)arg);
	ft_memdel((void**)flist);
	return (0);
}

int			read_file(t_dir **flist, t_dir **first, char *dirname)
{
	if (!(*flist))
		if (((*flist) = get_content(dirname)))
			(*first) = (*flist);
		else
			print_error(dirname);
	else
		if (((*flist)->next = get_content(dirname)))
		{
			(*flist)->next->prev = (*flist);
			(*flist) = (*flist)->next;
		}
		else
			print_error(dirname);
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
		return (permis_denied(dirname));
	while ((dir = readdir(rep)))
		if ((option_ok(optl, 'a') == 0 && dir->d_name[0] != '.') ||
		(option_ok(optl, 'a') == 1 && dir->d_name[0] == '.') ||
		(option_ok(optl, 'a') == 1 && dir->d_name[0] != '.'))
			sort_list(&list, &slist, ft_strjoin(path, dir->d_name));
	closedir(rep);
	ft_memdel((void**)&path);
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
	if ((lstat(entity, &stats)) == -1)
		return (NULL);
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
	list->prev = NULL;
	list->next = NULL;
	return (list);
}
