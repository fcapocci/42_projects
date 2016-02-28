/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 11:49:06 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/28 15:39:51 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			sub_manage(int argc, t_opt *op, t_arg *arg, t_dir *flist)
{
	t_dir		*list;

	list = NULL;
	while (arg)
	{
		if ((arg->type == 'd') || (!op_ok(op, 'l') && arg->type == 'l'))
		{
			print_path(arg->argument, argc, flist);
			if ((read_dir(op, &list, arg->argument)) == -1)
				return (-1);
		}
		arg = arg->next;
	}
	return (0);
}

t_dir		*last_link(t_dir *list)
{
	t_dir		*tmp;

	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
