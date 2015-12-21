/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rename.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:55:36 by fcapocci          #+#    #+#             */
/*   Updated: 2015/12/17 15:19:21 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tlist	*rename_diez(t_tlist *start)
{
	t_tlist	*tmp;
	int		l;

	l = 'A';
	tmp = start;
	while (start)
	{
		start->tetri = change_diez(start->tetri, l);
		start = start->next;
		l++;
	}
	return (tmp);
}

char	**change_diez(char **tetri, int l)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetri[i][j] == '#')
				tetri[i][j] = (char)l;
			j++;
		}
		i++;
	}
	return (tetri);
}
