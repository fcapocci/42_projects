/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_nano_time.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 23:30:31 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/29 17:52:16 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_splitlist_ntime(t_dir *list, t_dir **a, t_dir **b, int size)
{
	(*a) = list;
	list->prev = NULL;
	while (size-- > 1)
		list = list->next;
	(*b) = list->next;
	(*b)->prev = NULL;
	list->next = NULL;
}

t_dir		*ft_merge_ntime(t_dir *a, t_dir *b)
{
	t_dir		*tmp;
	int			i;

	i = 0;
	if (a == NULL)
		return (b);
	if (b == NULL)
		return (a);
	i = (a->numdate == b->numdate && a->nano_numdate > b->nano_numdate) ? 1 : 0;
	tmp = (i == 1) ? a : b;
	tmp->next = (i) ? ft_merge_ntime(a->next, b) : ft_merge_ntime(a, b->next);
	tmp->next->prev = tmp;
	return (tmp);
}

void		ft_split_ntime(t_dir **list, int size)
{
	t_dir		*lista;
	t_dir		*listb;

	if (!(*list) || !(*list)->next)
		return ;
	size /= 2;
	ft_splitlist_ntime((*list), &lista, &listb, size);
	ft_split_ntime(&lista, size);
	ft_split_ntime(&listb, size);
	(*list) = ft_merge_ntime(lista, listb);
}

t_dir		*ft_merge_sort_ntime(t_dir *list)
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
	ft_split_ntime(&list, size_list);
	return (list);
}
