/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:03:29 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/17 18:23:34 by fcapocci         ###   ########.fr       */
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

t_env			*unset_env(t_env *vlist, char **args)
{
	t_env		*nvlist;

	nvlist = vlist;
	while ((ft_strcmp(args[0], vlist->vname) && vlist->next))
		vlist = vlist->next;
	if (!ft_strcmp(args[0], vlist->vname))
	{
		if (vlist->vname)
			ft_memdel((void**)&vlist->vname);
		if (vlist->vcntt)
			ft_memdel((void**)&vlist->vcntt);
	}
	return (nvlist);
}
