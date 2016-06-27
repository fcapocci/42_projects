/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocompletion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 17:42:04 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/17 12:51:41 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/_42sh.h"
#include "../libft/libft.h"


#include <stdio.h>

static int					cmp_names(char *lst_name, char *entry,
		size_t len_entry, char *from)
{
	size_t					i;

	i = len_entry;
	while (i-- > 0)
		if (lst_name[i] != entry[i])
			return (0);
	return (1);
}

static int					select_names(t_bin *lst, char *entry)
{
	size_t					len_entry;
	t_bin					*curs;

	if ((curs = lst) == NULL || entry == NULL)
		return (-1);
	len_entry = ft_strlen(entry);
	while (curs != NULL && len_entry < curs->len_name &&
			cmp_names(curs->name, entry, len_entry,"1") == 0)
		curs = curs->s_next;
	while (curs != NULL)
	{
		if (curs->len_name >= len_entry &&
				cmp_names(curs->name, entry, len_entry, "2") == 1)
			ft_putendl(curs->name);
		curs = curs->s_next;
	}
	ft_putchar('\n');
	return (0);
}

int							autocompletion(t_42sh *sh, char *entry)
{
	int						index;

	if (entry == NULL || entry[0] == '\0' || SIZE_SORT < 27 || sh == NULL)
		return (-1);
	if (entry[0] >= 'a' && entry[0] <= 'z')
		index = entry[0] - 'a';
	else if(entry[0] >= 'A' || entry[0] <= 'Z')
		index = entry[0] - 'A';
	else
		index = SIZE_SORT - 1;
	printf("index = %d\n", index);
	return (select_names(sh->sort_bin[index], entry));
}
