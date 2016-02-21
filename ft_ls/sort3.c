/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 13:43:02 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/21 18:10:27 by fcapocci         ###   ########.fr       */
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
		if ((!option_ok(optl, 'r') && argument->time == argument->next->time &&
		argument->nanotime < argument->next->nanotime)
		|| (option_ok(optl, 'r') && argument->time == argument->next->time &&
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
