/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:03:29 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/23 00:24:12 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define INIT i = 0; p = 0; loop = 0; tmp = 0;

char			*sup_tab(char *line)
{
	char		*new_line;
	size_t		i;
	size_t		p;
	char		tmp;
	int			loop;

	new_line = ft_strnew(ft_strlen(line));
	INIT;
	while (i <= ft_strlen(line))
	{
		while ((line[i] == ' ' || line[i] == 9) && (line[i + 1] == ' ' ||
		line[i + 1] == 9 || line[i + 1] == '\0'))
			i++;
		if ((line[i] == 9 || line[i] == ' ') && loop != 0)
			tmp = ' ';
		else if (line[i] != 9 && line[i] != ' ')
			tmp = line[i];
		if (tmp)
			new_line[p++] = tmp;
		loop = 1;
		i++;
	}
	return (new_line);
}

char			**scan_tld(char **args, t_env *vlist)
{
	int			i;
	int			y;

	if (args == NULL)
		return (NULL);
	y = 0;
	i = 0;
	while (vlist && vlist->vname && ft_strcmp(vlist->vname, "HOME"))
		vlist = vlist->next;
	if (vlist == NULL)
		return (args);
	i = len_y(args);
	while (i > 0)
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
	if (line[0] == '~' && vcntt != NULL)
	{
		line++;
		new_line = ft_strjoin(vcntt, line);
		ft_memdel((void**)&tmp);
	}
	return (new_line);
}

char			**rp_shlvl(char **env)
{
	char		*tmp;
	int			i;
	int			end;
	char		**tmp_tab;

	end = len_y(env);
	i = 0;
	tmp = env[i];
	while (i != end && tmp &&
	ft_strcmp((tmp_tab = ft_strsplit(tmp, '='))[0], "SHLVL"))
	{
		i++;
		tmp = env[i];
		ft_free_strsplit(&tmp_tab);
	}
	if (tmp)
	{
		tmp[ft_strlen(tmp) - 1] += 1;
		ft_free_strsplit(&tmp_tab);
	}
	return (env);
}

void			unset_env(t_env **vlist, char **args)
{
	int			len;
	t_env		*cp;

	len = len_y(args);
	cp = (*vlist);
	if (len == 2 && cp && cp->vname)
	{
		if (cp && (!ft_strcmp(args[1], cp->vname)))
		{
			free_link(&cp, 1);
			(*vlist) = cp;
		}
		else
		{
			while (cp->next && cp->next->next
			&& (ft_strcmp(args[1], cp->next->vname)))
				cp = cp->next;
			if (cp->next && ft_strcmp(args[1], cp->next->vname) == 0)
				free_link(&cp, 0);
		}
	}
	if ((*vlist) == NULL)
		(*vlist) = new_link(NULL);
}
