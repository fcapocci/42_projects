/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 04:51:16 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/14 13:46:50 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			quit(t_env **vlist, char **line)
{
	t_env		*tmp;

	while (*vlist)
	{
		tmp = (*vlist)->next;
		ft_memdel((void**)&(*vlist)->vname);
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

int				free_tab_list(t_path ***tab_list, int nb)
{
	t_path		*tmp;
	int			i;

	i = 0;
	while ((*tab_list)[i])
	{
		while ((*tab_list)[i])
		{
			tmp = (*tab_list)[i]->next;
			ft_memdel((void**)&(*tab_list)[i]->ppath);
			ft_memdel((void**)&(*tab_list)[i]->pname);
			ft_memdel((void**)&(*tab_list)[i]);
			(*tab_list)[i] = tmp;
		}
		ft_memdel((void**)&(*tab_list)[i]);
		i++;
	}
	ft_memdel((void**)*tab_list);
	return (nb);
}

int				is_builts(char **line, char ***args, int nb)
{
	ft_memdel((void**)&(*line));
	ft_free_strsplit(&(*args));
	return (nb);
}
