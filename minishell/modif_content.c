/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:03:29 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/16 10:44:32 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*sup_tab(char *line)
{
	char		*new_line;
	size_t		i;
	size_t		p;
	char		tmp;

	new_line = ft_strnew(ft_strlen(line));
	i = 0;
	p = 0;
	while (i <= ft_strlen(line))
	{
		if (i == 0 && (line[i] == ' ' || line[i] == 9))
			while (line[i] == ' ' || line[i] == 9)
				i++;
		if (line[i] == 9)
			tmp = ' ';
		else
			tmp = line[i];
		new_line[p++] = tmp;
		while (line[i] && (line[i] == ' ' || line[i] == 9) &&
		(line[i + 1] == ' ' || line[i + 1] == 9))
			i++;
		i++;
	}
	return (new_line);
}

t_env			*insert_cntt(t_env *vlist, char *cntt, int rp)
{
	if (rp > 0)
	{
		ft_memdel((void**)&vlist->vcntt);
		vlist->vcntt = ft_strdup(cntt);
	}
	return (vlist);
}

t_env			*set_env(t_env *vlist, char *name, char *cntt, int rp)
{
	t_env		*nvlist;

	nvlist = vlist;
	if (!name)
		return (nvlist);
	while (vlist && ft_strcmp(name, vlist->vname))
		vlist = vlist->next;
	if (!ft_strcmp(name, vlist->vname))
		vlist = insert_cntt(vlist, cntt, rp);
	else
	{
		if ((vlist = (t_env*)ft_memalloc(sizeof(t_env))) == NULL)
			return (NULL);
		vlist->vname = ft_strdup(name);
		vlist->vcntt = (rp == 0 ? ft_strdup("\0") : ft_strdup(cntt));
		vlist->next = NULL;
	}
	return (nvlist);
}
/*
t_env			*unset_env(t_env *vlist, char *name)
{
	t_env		*nvlist;
	return (nvlist);
}

t_env			*cd_env(t_env *vlist, char *name)
{
	t_env		*nvlist;
	return (nvlist);
}
*/
