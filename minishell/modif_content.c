/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:03:29 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/13 19:08:21 by fcapocci         ###   ########.fr       */
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

char			**scan_tld(char **args, t_env *vlist)
{
	int			i;
	int			y;

	y = 1;
	i = 0;
	while (vlist && ft_strcmp(vlist->vname, "HOME"))
		vlist = vlist->next;
	if (vlist == NULL)
		return (args);
	i = len_y(args);
	while (i != 1)
	{
		args[y] = srch_tld(args[y], vlist->vcntt);
		i--;
		y++;
	}
	return (args);
}

char			*srch_tld(char *line, char *vcntt)
{
	char		*new_line;
	char		*tmp;

	tmp = line;
	new_line = line;
	if ((line = ft_strchr(line, '~')) != NULL && vcntt != NULL)
	{
		line++;
		new_line = ft_strjoin(vcntt, line);
		ft_memdel((void**)&tmp);
	}
	return (new_line);
}

void			unset_env(t_env **vlist, char **args)
{
	int			len;
	t_env		*cp;

	len = len_y(args);
	cp = (*vlist);
	if (len == 2)
	{
		if (cp->next && (!ft_strcmp(args[1], cp->vname)))
		{
			free_link(&cp, 1);
			(*vlist) = cp;
		}
		else
		{
			while (cp->next->next && (ft_strcmp(args[1], cp->next->vname)))
				cp = cp->next;
			if (ft_strcmp(args[1], cp->next->vname) == 0)
				free_link(&cp, 0);
		}
	}
}
