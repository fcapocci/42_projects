/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 14:13:18 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/08 23:03:29 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t			nb_link(t_dir *list)
{
	size_t		i;

	i = 1;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

t_dir		*sort_merge(t_dir *list)
{
	size_t		nbl;

	nbl = nb_link(list) / 2;
	ft_putchar('\n');
	return (list);
}

void		manage_list(t_opt *optl, t_dir *list)
{
	t_dir		*start;

	start = list;
	list = sort_merge(list);
	//if (option_ok(optl, 't') == 1)
	//	list =  sort_opt_t(t);
	//if (option_ok(optl, 'r') == 1)
	//	list =  sort_opt_r(r);
	printing(optl, list, start);
}
