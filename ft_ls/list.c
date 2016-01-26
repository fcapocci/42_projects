/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:53:06 by fcapocci          #+#    #+#             */
/*   Updated: 2016/01/27 00:27:40 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir		*add_link(t_dir *list, struct stat stats, char *name)
{
	t_dir		*new;

	ft_putstr("yo");
	if ((new = (t_dir*)ft_memalloc(sizeof(t_dir))) == NULL)
		return (NULL);
	list->next = new;
	if ((new = add_content(new, stats, name)) == NULL)
		return (NULL);
	return (new);
}

t_dir		*add_content(t_dir *list, struct stat stats, char *name)
{
	list->type = take_type(stats.st_mode);
	list->modes = take_modes(stats.st_mode);
	list->nblink = stats.st_nlink;
	list->owner = getpwuid(stats.st_uid)->pw_name;
	list->grp = getgrgid(stats.st_gid)->gr_name;
	list->tall = stats.st_size;
	list->date = dating(&stats.st_mtime);
	list->name = strdup(name);
	list->next = NULL;
	ft_putstr("addcontent");
	return (list);
}
