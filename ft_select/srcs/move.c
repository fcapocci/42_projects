/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 02:53:33 by fcapocci          #+#    #+#             */
/*   Updated: 2016/08/15 13:20:59 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_select.h"

int				move_up(t_lst **curs)
{
	(*curs) = (*curs)->prev;
	return (OK);
}

int				move_down(t_lst **curs)
{
	(*curs) = (*curs)->next;
	return (OK);
}

int				move_right(t_lst **curs, int word_col)
{
	while (word_col > 0)
	{
		(*curs) = (*curs)->next;
		word_col--;
	}
	return (OK);
}

int				move_left(t_lst **curs, int word_col)
{
	while (word_col > 0)
	{
		(*curs) = (*curs)->prev;
		word_col--;
	}
	return (OK);
}
