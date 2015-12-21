/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:22:33 by vcastro-          #+#    #+#             */
/*   Updated: 2015/12/17 16:56:46 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			order_h(char **tetri)
{
	int		i;
	int		j;
	int		l;

	l = 4;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetri[i][j] != '.')
				break ;
			j++;
		}
		if (l > j)
			l = j;
		i++;
	}
	return (l);
}

int			order_v(char **tetri)
{
	int		i;
	int		j;
	int		l;

	l = 4;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tetri[i][j] != '.')
				break ;
			i++;
		}
		if (l > i)
			l = i;
		j++;
	}
	return (l);
}

char		**order_tetri_h(char **tetri)
{
	int		k;
	int		i;
	int		j;

	i = 0;
	k = order_h(tetri);
	while (k)
	{
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 3)
			{
				tetri[i][j] = tetri[i][j + 1];
				tetri[i][j + 1] = '.';
				j++;
			}
			i++;
		}
		k--;
	}
	return (tetri);
}

char		**order_tetri_v(char **tetri)
{
	int		k;
	int		i;
	int		j;

	j = 0;
	k = order_v(tetri);
	while (k)
	{
		j = 0;
		while (j < 4)
		{
			i = 0;
			while (i < 3)
			{
				tetri[i][j] = tetri[i + 1][j];
				tetri[i + 1][j] = '.';
				i++;
			}
			j++;
		}
		k--;
	}
	return (tetri);
}

t_tlist		*ordering(t_tlist *start)
{
	t_tlist	*tmp;

	tmp = start;
	while (start)
	{
		start->tetri = order_tetri_h(start->tetri);
		start->tetri = order_tetri_v(start->tetri);
		start = start->next;
	}
	return (tmp);
}
