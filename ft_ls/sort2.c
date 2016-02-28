/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 13:43:02 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/28 18:53:31 by fcapocci         ###   ########.fr       */
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
