/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 13:03:47 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/04 12:13:28 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		free_list(t_dir **list)
{
	t_dir		*tmp;

	if (list != NULL)
	{
		while ((*list) != NULL)
		{
			tmp = (*list)->next;
			ft_memdel((void**)&(*list)->name);
			ft_memdel((void**)&(*list)->date);
			ft_memdel((void**)&(*list)->grp);
			ft_memdel((void**)&(*list)->owner);
			ft_memdel((void**)&(*list)->modes);
			ft_memdel((void**)&(*list));
			(*list) = tmp;
		}
	}
}
