/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 04:51:16 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/23 00:31:56 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			quit(t_env **vlist, char **line)
{
	t_env		*tmp;

	while (*vlist)
	{
		tmp = (*vlist)->next;
		if ((*vlist)->vname)
			ft_memdel((void**)&(*vlist)->vname);
		if ((*vlist)->vcntt)
			ft_memdel((void**)&(*vlist)->vcntt);
		ft_memdel((void**)vlist);
		(*vlist) = tmp;
	}
	ft_memdel((void**)vlist);
	ft_memdel((void**)&(*line));
	exit(0);
}

int				free_get_cmd(char ***args, char ***path, char **line, int nb)
{
	ft_free_strsplit(&(*args));
	ft_free_strsplit(&(*path));
	ft_memdel((void**)&(*line));
	return (nb);
}

void			free_plist(t_path **plist)
{
	t_path		*tmp;

	if (*plist)
	{
		while (*plist)
		{
			tmp = (*plist)->next;
			ft_memdel((void**)&(*plist)->ppath);
			ft_memdel((void**)&(*plist)->pname);
			ft_memdel((void**)plist);
			(*plist) = tmp;
		}
		ft_memdel((void**)plist);
	}
}

int				free_tab_list(t_path ***tab_list, int nb)
{
	int			i;
	t_path		**tmp;

	if ((*tab_list))
	{
		i = 0;
		tmp = *tab_list;
		while ((*tab_list)[i])
		{
			free_plist(&tmp[i]);
			i++;
		}
		free_plist(&tmp[i]);
		ft_memdel((void**)&tmp);
	}
	return (nb);
}

int				is_builts(char **line, char ***args, int nb)
{
	ft_memdel((void**)&(*line));
	ft_free_strsplit(&(*args));
	return (nb);
}
