/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 19:19:59 by fcapocci          #+#    #+#             */
/*   Updated: 2016/07/16 21:00:42 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_select.h"

void			free_lst(t_lst *lst)
{
	t_lst		*tmp;

	if (lst)
	{
		while (lst)
		{
			tmp = lst->next;
			if (lst->name)
				ft_memdel((void**)&lst->name);
			lst->prev->next = NULL;
			ft_memdel((void**)&lst);
			lst = tmp;
		}
		ft_memdel((void**)&lst);
	}
}

