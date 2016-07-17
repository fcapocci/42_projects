/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 19:19:59 by fcapocci          #+#    #+#             */
/*   Updated: 2016/07/18 00:13:13 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_select.h"

void			free_lst(t_lst *lst)
{
	t_lst		*tmp;

	while (lst)
	{
		tmp = (lst->next == lst) ? NULL : lst->next;
		if (lst->name)
			ft_memdel((void**)&lst->name);
		lst->prev->next = NULL;
		ft_memdel((void**)&lst);
		lst = tmp;
	}
	if (lst)
		ft_memdel((void**)&lst);
}

