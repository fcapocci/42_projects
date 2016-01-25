/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:53:06 by fcapocci          #+#    #+#             */
/*   Updated: 2016/01/25 19:35:45 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir		*add_link(t_dir *list, struct stats)
{
	t_dir		*new;

	if ((new = (t_dir*)ft_memalloc(sizeof(t_dir))) == NULL)
		return (NULL);
	if ((new = add_content(new, stats)) == NULL)
		return (NULL);
	return (new);
}

t_dir		*add_content(t_dir *list, struct stats)
{
	list->type = take_type(stats.st_mode);
	list->modes = take_mode(stats.st_mode);
	list->nblink = stats.st_nlink;
	list->owner = getpwuid(stats.st_uid)->pw_name;
	list->grp = getgrgid(stat.st_gid)->gr_name;
	list->tall = stats.st_size;
	list->date = dating(stats.st_mtime);
	list->name = strdup();
	list->next = NULL;

	return (list);
}
