/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 19:59:02 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/22 15:37:06 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/_42sh.h"
#include "../libft/libft.h"

static int					exist(t_42sh **sh, char *name, char *content)
{
	t_env					*curs;

	curs = (*sh)->lst_env;
	while (curs != NULL)
	{
		if (ft_strcmp(curs->name, name) == 0)
		{
			ft_memdel((void**)&curs->content);
			if ((curs->content = ft_strdup(content == NULL ||
					content[0] == '\0' ? "" : content)) == NULL)
				return (-1);
			return (1);
		}
		curs = curs->next;
	}
	return (0);
}

static int					already_exist(t_42sh **sh, char *name,
		char *content)
{
	t_env					*curs;

	if (name == NULL || name[0] == '\0')
		return (0);
	curs = (*sh)->lst_env;
	while (curs != NULL)
	{
		if (ft_strcmp(curs->name, name) == 0)
			return (exist(sh, name, content));
		curs = curs->next;
	}
	return (0);
}

static int					add_env(t_42sh **sh, char *name, char *content,
		unsigned int nb_env)
{
	t_env					*new;


	if (sh == NULL || *sh == NULL || name == NULL || name[0] == '\0')
		return (-1);
	if ((new = new_env(name, content, nb_env)) == NULL)
		return (-1);
	if ((*sh)->lst_env != NULL)
		new->next = (*sh)->lst_env;
	(*sh)->lst_env = new;
	return (1);
}

static int					is_home(t_42sh **sh, char *line, int ret)
{
	if (ft_strcmp(line, "HOME") == 0)
	{
		(*sh)->home = (*sh)->lst_env->content;
		(*sh)->len_home = ft_strlen((*sh)->lst_env->content);
	}
	return (ret);
}

int							builtin_setenv(t_42sh **sh, t_multi_line **m_line)
{
	char					*egale;
	int						ret;
	unsigned int			i;
	unsigned int			nb_env;

	if (sh == NULL || *sh == NULL || m_line == NULL || *m_line == NULL)
		return (-1);
	if (ft_strncmp((*m_line)->line, "setenv", 6) == 0)
	{
		i = 0;
		while ((*m_line)->line[6 + i] == ' ')
			i++;
		if ((egale = ft_strchr(&(*m_line)->line[6 + i], '=')) != NULL)
		{
			nb_env = (*sh)->lst_env == NULL ? 0 : (*sh)->lst_env->i + 1;
			*egale = '\0';
			if ((ret = already_exist(sh, &(*m_line)->line[6 + i], egale + 1))
					== 0)
				ret = add_env(sh, &(*m_line)->line[6 + i], egale + 1, nb_env);
			return (is_home(sh, &(*m_line)->line[6 + i], ret));
		}
		return (builtin_error("setenv"));
	}
	return (0);
}
