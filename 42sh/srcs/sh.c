/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 17:41:24 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/23 10:07:46 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incs/_42sh.h"
#include "../libft/libft.h"

#include <stdio.h>

static int					check_path_access(char **path)
{
	int						ret;
	unsigned int			i;

	if (path == NULL)
		return (0);
	i = 0;
	while (path[i] != NULL)
		if ((ret = access(path[i++], F_OK | R_OK | X_OK)) != 0)
			return (0);
	return (1);
}

static void					sort_bin_list(t_42sh *sh)
{
	unsigned int			i;

	i = 0;
	while (i < SIZE_SORT)
		sort_list(&sh->sort_bin[i++], name_tri);
}

static char					*search_home(t_42sh *sh)
{
	t_env					*curs;

	if (sh == NULL)
		return (NULL);
	curs = sh->lst_env;
	while (curs != NULL)
	{
		if (curs->name != NULL && ft_strcmp(curs->name, "HOME") == 0)
			return(curs->content);
		curs = curs->next;
	}
	return (NULL);
}

t_42sh						*init_sh(char **env)
{
	t_42sh					*sh;

	if ((sh = ft_memalloc(sizeof(*sh))) == NULL)
		return (NULL);
	get_struct_42sh(&sh);
	if ((sh->lst_env = save_env(env)) == NULL || init_term(&sh) == ERROR)
		return (NULL);
	if ((sh->path_line = ft_strdup(getenv("PATH"))) != NULL)
	{
		if ((sh->path = ft_strsplit(sh->path_line, ':')) == NULL)
			return (NULL);
		if (check_path_access(sh->path) == 0)
			return (NULL);
		if (save_hash_bin(sh) == -1)
			return (NULL);
	}
	sh->home = search_home(sh);
	sh->len_home = sh->home == NULL ? 0 : ft_strlen(sh->home);
	sort_bin_list(sh);
	return (sh);
}

int							del_sh(t_42sh **sh)
{
	if (sh == NULL || *sh == NULL)
		return (-1);
	tcsetattr(0, TCSADRAIN, &(*sh)->reset);
	del_hash_bin((*sh));
	del_env(&(*sh)->lst_env);
	if ((*sh)->path != NULL)
	{
		ft_free_strsplit((*sh)->path);
		ft_memdel((void**)&(*sh)->path_line);
	}
	if ((*sh)->term_name != NULL)
		ft_memdel((void**)&(*sh)->term_name);
	ft_memdel((void**)sh);
	return (0);
}
