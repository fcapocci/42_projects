/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 02:53:33 by fcapocci          #+#    #+#             */
/*   Updated: 2016/08/09 20:28:54 by fcapocci         ###   ########.fr       */
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
