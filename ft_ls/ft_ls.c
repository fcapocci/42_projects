/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:38:23 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/09 12:10:49 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			manage(int argc, char **argv, t_opt *optl)
{
	char			*dirname;
	t_dir			*flist;

	flist = NULL;
	dirname = NULL;
	if (argc == 1)
	{
		dirname = ft_strnew(1);
		dirname[0] = '.';
		if ((read_dir(optl, &flist, dirname)) == -1)
			return (-1);
		exit(0);
	}
	if (argv[0] && argv[0][0] == '\0')
	{
		ft_putstr("ls: fts_open: No such file or directory\n");
		exit(0);
	}
	else
		manage_read(argc, argv, optl);
	return (0);
}

int			manage_read(int argc, char **argv, t_opt *op)
{
	t_arg			*arg[2];
	t_dir			*flist[2];

	flist[1] = NULL;
	flist[0] = NULL;
	if ((arg[0] = read_arg(op, argc, argv)) == NULL)
		exit(0);
	arg[0] = manage_sort_arg(op, arg[0]);
	arg[1] = arg[0];
	while (arg[0])
	{
		if ((!op_ok(op, 'l') ? (arg[0]->type != 'l' &&
		arg[0]->type != 'd') : (arg[0]->type != 'd')))
			read_file(op, &flist[0], &flist[1], arg[0]->argument);
		arg[0] = arg[0]->next;
	}
	if (flist[1])
		print_file(op, flist[1]);
	if ((sub_manage(argc, op, arg[1], flist[1])) == -1)
		return (-1);
	ft_memdel((void**)arg);
	free_list(flist);
	return (0);
}

int			read_file(t_opt *op, t_dir **flist, t_dir **first, char *dirname)
{
	if (!(*flist))
	{
		if (((*flist) = get_content(op, dirname)))
			(*first) = (*flist);
		else
			print_error(dirname, 1);
	}
	else
	{
		if (((*flist)->next = get_content(op, dirname)))
		{
			(*flist)->next->prev = (*flist);
			(*flist) = (*flist)->next;
		}
		else
			print_error(dirname, 1);
	}
	return (0);
}

int			read_dir(t_opt *optl, t_dir **list, char *dirname)
{
	DIR				*rep;
	struct dirent	*dir;
	t_dir			*slist;
	char			*path;

	path = ft_strjoin(dirname, "/");
	slist = (*list);
	if ((rep = opendir(dirname)) == NULL)
		return (permis_denied(dirname));
	while ((dir = readdir(rep)))
		if ((op_ok(optl, 'a') == 0 && dir->d_name[0] != '.') ||
		(op_ok(optl, 'a') == 1 && dir->d_name[0] == '.') ||
		(op_ok(optl, 'a') == 1 && dir->d_name[0] != '.'))
			sort_list(optl, &list, &slist, ft_strjoin(path, dir->d_name));
	closedir(rep);
	(*list) = manage_sort(optl, (*list));
	ft_memdel((void**)&path);
	slist = ((*list) ? last_link((*list)) : slist);
	printing(optl, (*list), slist);
	recursion(optl, (*list), slist);
	free_list(list);
	return (0);
}

t_dir		*get_content(t_opt *op, char *entity)
{
	struct stat		stats;
	t_dir			*list;

	if ((list = (t_dir*)ft_memalloc(sizeof(t_dir))) == NULL)
		return (NULL);
	if ((lstat(entity, &stats)) == -1)
		return (NULL);
	list->type = take_type(stats.st_mode);
	list->modes = take_modes(stats.st_mode);
	list->acl = take_acl_el(entity);
	list->nblink = stats.st_nlink;
	list->owner = (!op_ok(op, 'n')
	? ft_strdup(getpwuid(stats.st_uid)->pw_name) : ft_itoa(stats.st_uid));
	list->grp = ((!op_ok(op, 'n') && (getgrgid(stats.st_gid) != NULL))
	? ft_strdup(getgrgid(stats.st_gid)->gr_name) : ft_itoa(stats.st_gid));
	list->tall = stats.st_size;
	get_minor_major(&list->minor, &list->major, stats.st_rdev);
	list->date = dating(&stats.st_mtime);
	list->numdate = stats.st_mtime;
	list->nano_numdate = stats.st_mtimespec.tv_nsec;
	list->blksize = stats.st_blocks;
	list->name = ft_strdup(entity);
	list->prev = NULL;
	list->next = NULL;
	return (list);
}
