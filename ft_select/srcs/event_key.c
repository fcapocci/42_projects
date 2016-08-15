/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 01:57:09 by fcapocci          #+#    #+#             */
/*   Updated: 2016/08/15 13:21:24 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_select.h"

int				space_key(t_lst **curs)
{
	(*curs)->selected = (*curs)->selected == 1 ? 0 : 1;
	(*curs) = (*curs)->next;
	return (OK);
}

int				del_key(t_lst **lst, t_lst **curs)
{
	t_lst		*tmp;

	tmp = *curs;
	*curs = (*curs)->next;
	tmp->next->prev = tmp->prev;
	tmp->prev->next = tmp->next;
	if (tmp == tmp->next)
		return (ERR);
	else if (tmp == *lst)
		*lst = (*lst)->next;
	if (tmp->name)
		ft_memdel((void**)&tmp->name);
	ft_memdel((void**)&tmp);
	return (OK);
}

int				event_key(char *buff)
{
	t_term		*glob;

	if ((glob = get_addr()) == NULL)
		return (ERR);
	if (ESC)
		return (ERR);
	else if (UP)
		return (move_up(&(glob->curs)));
	else if (DOWN)
		return (move_down(&(glob->curs)));
	else if (RIGHT)
		return (move_right(&(glob->curs), glob->nb_word_col));
	else if (LEFT)
		return (move_left(&(glob->curs), glob->nb_word_col));
	else if (SPACE)
		return (space_key(&(glob->curs)));
	else if (DEL || DEL2)
		return (del_key(&(glob->lst), &(glob->curs)));
	else if (RET)
		return (PRINT);
	return (OK);
}
