/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 19:13:40 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/05 19:27:58 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*dating(const time_t *clock)
{
	char	*crt_date;
	char	*date;

	date = ctime(clock);
	crt_date = ft_strsub(date, 4, 12);
	return (crt_date);
}

char		*hide_path(char *entity)
{
	char	*new;
	int		len;

	while (ft_strchr(entity, '/'))
		entity++;
	len = ft_strlen(entity);
	new = ft_strsub(entity, 0, len);
	return (new);
}

void		change_content(t_dir **list, t_dir **list_next)
{
	t_dir		*tmp;

	tmp = (t_dir*)ft_memalloc(sizeof(t_dir));
	tmp->type = (*list)->type;
	tmp->modes = (*list)->modes;
	tmp->nblink = (*list)->nblink;
	tmp->owner = (*list)->owner;
	tmp->grp = (*list)->grp;
	tmp->tall = (*list)->tall;
	tmp->date = (*list)->date;
	tmp->numdate = (*list)->numdate;
	tmp->name = (*list)->name;
	tmp->next = (*list)->next;

	(*list)->type = (*list_next)->type;
	(*list)->modes = (*list_next)->modes;
	(*list)->nblink = (*list_next)->nblink;
	(*list)->owner = (*list_next)->owner;
	(*list)->grp = (*list_next)->grp;
	(*list)->tall = (*list_next)->tall;
	(*list)->date = (*list_next)->date;
	(*list)->numdate = (*list_next)->numdate;
	(*list)->name = (*list_next)->name;
	(*list)->next = (*list_next)->next;

	(*list_next)->type = tmp->type;
	(*list_next)->modes = tmp->modes;
	(*list_next)->nblink = tmp->nblink;
	(*list_next)->owner = tmp->owner;
	(*list_next)->grp = tmp->grp;
	(*list_next)->tall = tmp->tall;
	(*list_next)->date = tmp->date;
	(*list_next)->numdate = tmp->numdate;
	(*list_next)->name = tmp->name;
	(*list_next)->next = tmp->next;
	ft_memdel((void**)&tmp);
}

void		manage(t_opt *optl, t_dir *list)
{
	t_dir		*start;

	start = list;
	while (list)
	{
		if (hide_path(list->name)[0] > hide_path(list->next->name)[0])
		{
			change_content(&list, &list->next);
		}
		list = list->next;
	}
	printing(optl, start);
}
