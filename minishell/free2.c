/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 23:04:03 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/07 14:07:40 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			quit_builts(char **line, char ***args)
{
	ft_free_strsplit(args);
	ft_memdel((void**)&(*line));
}

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

int				quit_char(char **ptr, int nb)
{
	ft_memdel((void**)&(*ptr));
	return (nb);
}

int				quit_dubblechar(char **ptr, char **str, int nb)
{
	ft_memdel((void**)&(*ptr));
	ft_memdel((void**)&(*str));
	return (nb);
}
