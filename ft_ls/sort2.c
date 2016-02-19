/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 13:30:05 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/19 15:28:49 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_arg			*swap_arg_content(t_arg *link1, t_arg *link2)
{
	link1->argument = link2->argument;
	link1->type = link2->type;
	link1->time = link2->time;
	return (link1);
}

t_dir			*swap_dir_content(t_dir *link1, t_dir *link2)
{
	link1->type = link2->type;
	link1->modes = link2->modes;
	link1->nblink = link2->nblink;
	link1->owner = link2->owner;
	link1->grp = link2->grp;
	link1->tall = link2->tall;
	link1->date = link2->date;
	link1->numdate = link2->numdate;
	link1->blksize = link2->blksize;
	link1->name = link2->name;
	return (link1);
}

t_dir			*sort_dir_lex(t_dir *list)
{
	t_dir			*start;
	t_dir			*tmp;

	tmp = (t_dir*)ft_memalloc(sizeof(t_dir));
	start = list;
	while (list && list->next)
	{
		if (ft_strcmp(list->next->name, list->name) == -1)
		{
			tmp = swap_dir_content(tmp, list);
			list = swap_dir_content(list, list->next);
			list->next = swap_dir_content(list->next, tmp);
			list = start;
		}
		else
			list = list->next;
	}
	ft_memdel((void**)&tmp);
	return (start);
}

t_dir			*sort_dir_time(t_dir *list)
{
	t_dir			*start;
	t_dir			*tmp;

	tmp = (t_dir*)ft_memalloc(sizeof(t_dir));
	start = list;
	while (list && list->next)
	{
		if (list->numdate < list->next->numdate)
		{
			tmp = swap_dir_content(tmp, list);
			list = swap_dir_content(list, list->next);
			list->next = swap_dir_content(list->next, tmp);
			list = start;
		}
		else
			list = list->next;
	}
	ft_memdel((void**)&tmp);
	return (start);
}
