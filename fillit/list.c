/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 14:55:10 by vcastro-          #+#    #+#             */
/*   Updated: 2015/12/14 11:26:38 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tlist	*ft_create_elem(char *file)
{
	t_tlist	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return ((void*)0);
	elem->tetri = ft_strsplit(ft_strsub(file, 0, 19), '\n');
	elem->next = NULL;
	return (elem);
}

t_tlist	*save_tetris(char *file)
{
	int		i;
	t_tlist	*start;
	t_tlist	*list;

	i = 0;
	list = ft_create_elem(file);
	start = list;
	while (i++ < 4)
		file = ft_passline(file);
	if (*file == '\n')
		file = ft_passline(file);
	while (*file)
	{
		i = 0;
		list->next = ft_create_elem(file);
		list = list->next;
		file = ft_passline(file);
		while (i++ < 4)
			file = ft_passline(file);
		if (*file == '\n')
			file = ft_passline(file);
	}
	return (start);
}
