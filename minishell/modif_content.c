/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:03:29 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/19 00:27:16 by fcapocci         ###   ########.fr       */
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

void			unset_env(t_env ***vlist, char **args)
{
	int			len;
	t_env		*cp;

	len = len_y(args);
	cp = (**vlist);
	if (len == 2)
	{
		if (cp->next && (!ft_strcmp(args[1], cp->vname)))
		{
			free_link(&cp, 1);
			(**vlist) = cp;
		}
		else
		{
			while ((ft_strcmp(args[1], cp->next->vname) && cp->next->vname))
				cp = cp->next;
			if (ft_strcmp(args[1], cp->next->vname) == 0)
				free_link(&cp, 0);
		}
	}
}
