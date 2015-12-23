/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:44:53 by fcapocci          #+#    #+#             */
/*   Updated: 2015/12/23 15:23:14 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		solve(char ***map, int size, t_tlist *lst)
{
	int		i;
	int		j;

	i = 0;
	while (i + tetri_size_v(lst->tetri) < size && lst)
	{
		j = 0;
		while (j + tetri_size_h(lst->tetri) < size)
		{
			if (place_tetri(map, lst->tetri, i, j) == 1)
			{
				lst = lst->next;
				i = -1;
				break ;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		len_lst(t_tlist *start)
{
	t_tlist	*tmp;
	int		len;

	len = 0;
	tmp = start;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

int		virtual_size(int ntetri)
{
	int		i;

	i = 0;
	while (i * i < ntetri * 4)
		i++;
	return (i);
}

int		is_tetri_writable(char **map, char **tetri, int i, int j)
{
	int		x;
	int		y;
	int		k;

	x = 0;
	k = j;
	while (x < 4)
	{
		y = 0;
		j = k;
		while (y < 4)
		{
			if (map[i][j] != '.' && tetri[x][y] != '.')
				return (ERROR);
			j++;
			y++;
		}
		i++;
		x++;
	}
	return (SUCCESS);
}

int		place_tetri(char ***map, char **tetri, int i, int j)
{
	int		x;
	int		y;
	int		k;

	if ((is_tetri_writable(*map, tetri, i, j)) == ERROR)
		return (ERROR);
	x = 0;
	k = j;
	while (x < 4)
	{
		j = k;
		y = 0;
		while (y < 4)
		{
			if ((*map)[i][j] == '.' && tetri[x][y] != '.')
				(*map)[i][j] = tetri[x][y];
			j++;
			y++;
		}
		i++;
		x++;
	}
	return (SUCCESS);
}
