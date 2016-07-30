/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 19:19:59 by fcapocci          #+#    #+#             */
/*   Updated: 2016/07/30 03:12:54 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_select.h"

void			free_lst(t_lst *lst)
{
	t_lst		*tmp;

	while (lst)
	{
		tmp = (lst->next == lst) ? NULL : lst->next;
		lst->prev->next = lst->next;
		lst->next->prev = lst->prev;
		if (lst->name)
			ft_memdel((void**)&lst->name);
		ft_memdel((void**)&lst);
		lst = tmp;
	}
}
