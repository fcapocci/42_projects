/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolv_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:01:28 by vcastro-          #+#    #+#             */
/*   Updated: 2016/01/08 15:56:08 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**add_piece(char **tabresult, int sizesquare, int var[], t_tlist *piece)
{
	int index_i;
	int index_j;

	index_i = 0;
	while ((index_i < 4) && (var[0] + index_i) < sizesquare)
	{
		index_j = 0;
		while ((index_j < 4) && (var[1] + index_j) < sizesquare)
		{
			if (tabresult[var[0] + index_i][var[1] + index_j] == '.'
					&& piece->tetri[index_i][index_j] != '.')
				tabresult[var[0] + index_i][var[1] + index_j] =
					piece->tetri[index_i][index_j];
			index_j++;
		}
		index_i++;
	}
	return (tabresult);
}

char	**remove_piece(char **map, int size, char letter)
{
	int		x;
	int		y;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			if (map[x][y] == letter)
				map[x][y] = '.';
			y++;
		}
		x++;
	}
	return (map);
}
