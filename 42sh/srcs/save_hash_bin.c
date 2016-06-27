/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_hash_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 15:20:06 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/22 21:44:35 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/_42sh.h"
#include "../libft/libft.h"
#include <dirent.h>

static t_bin				*new_bin(t_bin *lst[], char *name, char *path,
		int index)
{
	int						check;
	t_bin					*bin;
	t_bin					*curs;

	if (lst == NULL || (bin = ft_memalloc(sizeof(t_bin))) == NULL ||
			(bin->name = ft_strdup(name)) == NULL ||
			(bin->path = ft_strdup(path)) == NULL || (bin->path_name =
			ft_multijoin(3, bin->path, "/",  bin->name)) == NULL)
		return (NULL);
	bin->i_hash = index;
	bin->len_name = ft_strlen(bin->name);
	if ((curs = (*lst)) == NULL)
		(*lst) = bin;
	else
	{
		while (curs->h_next != NULL)
			curs = curs->h_next;
		curs->h_next = bin;
	}
	return (bin);
}

static int					find_name(t_42sh *sh, char *name, char *path)
{
	int						check;
	int						index;
	t_bin					*new_;

	if ((index = i_table_hash(name, SIZE_HASH)) == -1)
		return (-1);
	if ((new_ = new_bin(&sh->hash_bin[index], name, path, index)) != NULL)
	{
		if (save_sort_bin(sh, &new_) == -1)
			return (-1);
	}
	else
		return (-1);
	return (1);
}

static int					open_dir_path(t_42sh *sh, unsigned int i)
{
	DIR						*direct;
	struct dirent			*str_dirent;


	int						j = 0;

	if ((direct = opendir(sh->path[i])) != NULL)
	{
		while ((str_dirent = readdir(direct)) != NULL)
		{
			if (find_name(sh, str_dirent->d_name, sh->path[i]) == -1)
				return (-1);
		}
		closedir(direct);
	}
	return (0);
}


int							save_hash_bin(t_42sh *sh)
{
	unsigned int			i;

	i = 0;
	while (sh->path[i] != NULL)
		if (open_dir_path(sh, i++) == -1)
			return (-1);
	return (0);
}
