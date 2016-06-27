/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_hash_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 15:21:50 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/17 12:51:56 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/_42sh.h"
#include "../libft/libft.h"

static void					del_hash_lst(t_bin **lst)
{
	unsigned int			i;
	t_bin					*tmp;
	t_bin					*curs;
	t_bin					*mem;

	curs = (*lst);
	i = 0;
	while (curs != NULL)
	{
		ft_memdel((void**)&curs->name);
		ft_memdel((void**)&curs->path);
		ft_memdel((void**)&curs->path_name);
		mem = curs;
		curs = curs->h_next;
		ft_memdel((void**)&mem);
	}
}

int							del_hash_bin(t_42sh *sh)
{
	unsigned int			i;

	i = 0;
	while (i < SIZE_HASH)
		del_hash_lst(&sh->hash_bin[i++]);
	return (0);
}
