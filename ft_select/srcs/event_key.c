/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 01:57:09 by fcapocci          #+#    #+#             */
/*   Updated: 2016/07/16 04:00:09 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_select.h"

int				space_key(t_lst **curs)
{
	(*curs)->selected = (*curs)->selected == 1 ? 0 : 1;
	(*curs) = (*curs)->next;
	return (OK);
}

int				event_key(char *buff, t_lst **lst, t_lst **curs)
{
	if (RIGHT)
		return (move_right(&(*curs)));
	else if (LEFT)
		return (move_left(&(*curs)));
	else if (SPACE)
		return (space_key(&(*curs)));
	else if (CD)
		return (ERR);
	return (OK);
}
