/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 11:55:15 by fcapocci          #+#    #+#             */
/*   Updated: 2016/09/08 18:41:47 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_select.h"

static t_lst	*crea_elem(char *str, size_t i)
{
	t_lst		*link;

	if ((link = ft_memalloc(sizeof(t_lst))) == NULL)
		return (NULL);
	link->name = ft_strdup(str);
	link->len_name = ft_strlen(str);
	link->type = 0;
	link->selected = 0;
	link->num = i + 1;
	link->prev = NULL;
	link->next = NULL;
	return (link);
}

t_lst			*init_lst(int argc, char **argv)
{
	t_lst		*lst[2];
	int			i;

	lst[0] = NULL;
	lst[1] = NULL;
	i = 1;
	while (i < argc)
	{
		if (!lst[0])
			lst[0] = crea_elem(argv[i], -1);
		else
		{
			lst[0]->next = crea_elem(argv[i], lst[0]->num);
			lst[0]->next->prev = lst[0];
			lst[0] = lst[0]->next;
		}
		if (!lst[1])
			lst[1] = lst[0];
		i++;
	}
	lst[1]->prev = lst[0];
	lst[0]->next = lst[1];
	return (lst[1]);
}
