/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_sort_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 10:08:25 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/17 12:53:06 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/_42sh.h"

static void					add_new_to_sort_bin(t_bin **sort_bin, t_bin **new)
{
	t_bin					*curs;

	if ((curs = (*sort_bin)) == NULL)
		(*sort_bin) = (*new);
	else
	{
		while (curs->s_next != NULL)
			curs = curs->s_next;
		curs->s_next = (*new);
	}
}

int							save_sort_bin(t_42sh *sh, t_bin **new_)
{
	if (sh == NULL || new_ == NULL || SIZE_SORT < 27)
		return (-1);
	if ((*new_)->name == NULL || (*new_)->name[0] == '\0')
		return (-1);
	if ((*new_)->name[0] >= 'a' && (*new_)->name[0] <= 'z')
		(*new_)->i_sort = (*new_)->name[0] - 'a';
	else if ((*new_)->name[0] >= 'A' && (*new_)->name[0] <= 'Z')
		(*new_)->i_sort = (*new_)->name[0] - 'A';
	else
		(*new_)->i_sort = SIZE_SORT - 1;
	add_new_to_sort_bin(&sh->sort_bin[(*new_)->i_sort], new_);
	return (0);
}
