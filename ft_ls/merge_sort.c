/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 23:30:31 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/29 17:43:30 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_splitlist(t_dir *list, t_dir **lista, t_dir **listb, int size)
{
	(*lista) = list;
	list->prev = NULL;
	while (size-- > 1)
		list = list->next;
	(*listb) = list->next;
	(*listb)->prev = NULL;
	list->next = NULL;
}

t_dir		*ft_merge(t_dir *a, t_dir *b)
{
	t_dir		*tmp;
	int			i;

	i = 0;
	if (a == NULL)
		return (b);
	if (b == NULL)
		return (a);
	i = (ft_strcmp(a->name, b->name) < 0) ? 1 : 0;
	tmp = (i == 1) ? a : b;
	tmp->next = (i) ? ft_merge(a->next, b) : ft_merge(a, b->next);
	tmp->next->prev = tmp;
	return (tmp);
}

void		ft_split(t_dir **list, int size)
{
	t_dir		*lista;
	t_dir		*listb;

	if (!(*list) || !(*list)->next)
		return ;
	size /= 2;
	ft_splitlist((*list), &lista, &listb, size);
	ft_split(&lista, size);
	ft_split(&listb, size);
	(*list) = ft_merge(lista, listb);
}

t_dir		*ft_merge_sort(t_dir *list)
{
	t_dir		*tmp;
	int			size_list;

	size_list = 0;
	tmp = list;
	while (tmp)
	{
		size_list++;
		tmp = tmp->next;
	}
	ft_split(&list, size_list);
	return (list);
}
