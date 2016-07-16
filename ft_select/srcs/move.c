/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 02:53:33 by fcapocci          #+#    #+#             */
/*   Updated: 2016/07/16 03:47:10 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_select.h"

int				move_left(t_lst **curs)
{
	(*curs) = (*curs)->prev;
	return (OK);
}

int				move_right(t_lst **curs)
{
	(*curs) = (*curs)->next;
	return (OK);
}
