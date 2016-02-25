/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 11:49:06 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/25 12:09:21 by fcapocci         ###   ########.fr       */
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
