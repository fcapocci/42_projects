/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 23:04:03 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/19 00:27:24 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			free_link(t_env **vlist, int in)
{
	t_env		*tmp;

	if (in == 1)
	{
		tmp = (*vlist);
		(*vlist) = (*vlist)->next;
		ft_memdel((void**)&tmp->vname);
		if (tmp->vcntt)
			ft_memdel((void**)&tmp->vcntt);
		ft_memdel((void**)&tmp);
	}
	else
	{
		tmp = (*vlist)->next;
		(*vlist)->next = (*vlist)->next->next;
		ft_memdel((void**)&tmp->vname);
		if (tmp->vcntt)
			ft_memdel((void**)&tmp->vcntt);
		ft_memdel((void**)&tmp);
	}
}
