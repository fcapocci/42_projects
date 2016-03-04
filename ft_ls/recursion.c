/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 17:31:33 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/04 12:13:40 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		recursion(t_opt *optl, t_dir *start, t_dir *end)
{
	t_dir		*newlist;
	int			r;

	newlist = NULL;
	while ((!op_ok(optl, 'r') ? start : end))
	{
		if (op_ok(optl, 'R') && ((!op_ok(optl, 'r') ? start->type :
		end->type) == 'd') && (ft_strcmp((hide_path(!op_ok(optl, 'r')
		? start->name : end->name)), ".") != 0)
		&& (ft_strcmp((hide_path(!op_ok(optl, 'r') ? start->name :
		end->name)), "..") != 0))
		{
			print_path((!op_ok(optl, 'r') ? start->name : end->name),
			2, (!op_ok(optl, 'r') ? start : end));
			r = read_dir(optl, &newlist,
			(!op_ok(optl, 'r') ? start->name : end->name));
		}
		start = (!op_ok(optl, 'r') ? start->next : start);
		end = (!op_ok(optl, 'r') ? end : end->prev);
	}
}
