/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolv_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:34:09 by vcastro-          #+#    #+#             */
/*   Updated: 2016/01/08 15:57:02 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	getletter(char **tetri)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (tetri[0][i] != '.')
			return (tetri[0][i]);
		i++;
	}
	return (0);
}

int		ft_piecevalide(char **tabresult, int var[], int sizesquare,
		t_tlist *piece)
{
	int		index_i;
	int		index_j;
	int		count;

	count = 0;
	index_i = 0;
	index_j = 0;
	while ((index_i < 4) && (var[0] + index_i) < sizesquare && count < 4)
	{
		while ((index_j < 4) && (var[1] + index_j) < sizesquare && count < 4)
		{
			if (tabresult[var[0] + index_i][var[1] + index_j] != '.'
					&& piece->tetri[index_i][index_j] != '.')
				return (0);
			if (tabresult[var[0] + index_i][var[1] + index_j] == '.'
					&& piece->tetri[index_i][index_j] != '.')
				count++;
			index_j++;
		}
		index_j = 0;
		index_i++;
	}
	return ((count == 4) ? 1 : 0);
}

char	**backtrackit(char **map, int size, t_tlist *pieces)
{
	int		var[2];
	char	letter;

	if (pieces == NULL)
		return (map);
	var[0] = 0;
	var[1] = 0;
	while (var[0] < size)
	{
		if (ft_piecevalide(map, var, size, pieces))
		{
			letter = getletter(pieces->tetri);
			map = add_piece(map, size, var, pieces);
			if (backtrackit(map, size, pieces->next))
				return (map);
			map = remove_piece(map, size, letter);
		}
		var[1]++;
		if (var[1] >= size)
		{
			var[1] = 0;
			var[0]++;
		}
	}
	return ((void*)0);
}
