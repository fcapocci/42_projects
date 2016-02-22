/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 17:31:33 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/22 22:59:30 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		recursion(t_opt *optl, t_dir *start, t_dir *end)
{
	t_dir		*newlist;

	newlist = NULL;
	while ((!op_ok(optl, 'r') ? start : end))
	{
		if ((op_ok(optl, 'R') && ((!op_ok(optl, 'r') ? start->type :
		end->type) == 'd') && (ft_strcmp((!op_ok(optl, 'r') ? start->name :
		end->name), "."))) || (op_ok(optl, 'R') && ((!op_ok(optl, 'r') ?
		start->type : end->type) == 'd')
		&& (ft_strcmp((!op_ok(optl, 'r') ? start->name : end->name), ".."))))
		{
			print_path((!op_ok(optl, 'r') ? start->name : end->name),
			2, (!op_ok(optl, 'r') ? start : end));
			if ((read_dir(optl, &newlist,
			(!op_ok(optl, 'r') ? start->name : end->name))) == -1)
			{
				ft_putstr("ca va pas");
				exit (0);
			}
		}
		if (!op_ok(optl, 'r'))
			start = start->next;
		else if (op_ok(optl, 'r'))
			end = end->prev;
	}
}
