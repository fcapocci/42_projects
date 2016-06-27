/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fonctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 13:31:58 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/13 14:28:21 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/_42sh.h"

static int					tri_ascii(char *a, char *b)
{
	unsigned int		i;

	i = 0;
	while (a[i] == (char)b[i] && a[i] != '\0' && b[i] != '\0')
		i++;
	if ((b[i] < a[i] && a[i] != '\0') || (b[i] == '\0' && a[i] != '\0'))
		return (0);
	return (1);
}

int							name_tri(void *node1, void *node2)
{
	t_bin					**tmp1;
	t_bin					**tmp2;

	tmp1 = node1;
	tmp2 = node2;
	return (tri_ascii((*tmp1)->name, (*tmp2)->name));
}
