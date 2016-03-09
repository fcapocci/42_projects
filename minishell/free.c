/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 04:51:16 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/09 15:17:23 by fcapocci         ###   ########.fr       */
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
		ft_memdel((void**)&(*vlist));
		(*vlist) = tmp;
	}
	ft_memdel((void**)&(*line));
	exit(0);
}

int				free_get_cmd(char ***args, char ***path, char **line)
{
	ft_free_strsplit(args);
	ft_free_strsplit(path);
	ft_memdel((void**)&(*line));
	return (-1);
}
