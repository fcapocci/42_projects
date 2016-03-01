/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 13:43:02 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/01 16:05:00 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_arg			*sort_arg_nanotime(t_opt *optl, t_arg *argument)
{
	t_arg			*start;
	t_arg			*tmp;

	tmp = (t_arg*)ft_memalloc(sizeof(t_arg));
	start = argument;
	while (argument && argument->next)
	{
		if ((!op_ok(optl, 'r') && argument->time == argument->next->time &&
		argument->nanotime < argument->next->nanotime)
		|| (op_ok(optl, 'r') && argument->time == argument->next->time &&
		argument->nanotime > argument->next->nanotime))
		{
			tmp = swap_arg_content(tmp, argument);
			argument = swap_arg_content(argument, argument->next);
			argument->next = swap_arg_content(argument->next, tmp);
			argument = start;
		}
		else
			argument = argument->next;
	}
	ft_memdel((void**)&tmp);
	return (start);
}

t_arg			*swap_arg_content(t_arg *link1, t_arg *link2)
{
	link1->argument = link2->argument;
	link1->type = link2->type;
	link1->time = link2->time;
	link1->nanotime = link2->nanotime;
	return (link1);
}

t_dir			*manage_sort(t_opt *optl, t_dir *list)
{
	t_dir			*slist;

	slist = NULL;
	if (!op_ok(optl, 'f'))
	{
		slist = ft_merge_sort(list);
		slist = (op_ok(optl, 't') ? ft_merge_sort_time(slist) : (slist));
		slist = (op_ok(optl, 't') ? ft_merge_sort_ntime(slist) : (slist));
	}
	else
		slist = list;
	return (slist);
}

t_arg			*manage_sort_arg(t_opt *optl, t_arg *arg)
{
	t_arg			*sarg;

	sarg = NULL;
	if (!op_ok(optl, 'f'))
	{
		sarg = (op_ok(optl, 't')) ? sort_arg_time(optl, arg) : sarg;
		sarg = (op_ok(optl, 't')) ? sort_arg_nanotime(optl, sarg) : sarg;
	}
	else
		sarg = arg;
	return (arg);
}
