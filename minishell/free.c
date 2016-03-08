/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 04:51:16 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/08 13:33:02 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			free_vlist(t_env *vlist)
{
	t_env		*tmp;

	while (vlist)
	{
		tmp = vlist->next;
		ft_memdel((void**)&vlist->vname);
		ft_memdel((void**)&vlist->vcntt);
		ft_memdel((void**)&vlist);
		vlist = tmp;
	}
}

void			quit(t_env **vlist, char **line)
{
	free_vlist((*vlist));
	ft_memdel((void**)line);
	exit(0);
}
