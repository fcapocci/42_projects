/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolv_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:01:28 by vcastro-          #+#    #+#             */
/*   Updated: 2016/01/07 14:24:03 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**add_piece(char **map, int *var, char **tetri)
{
	int		x;
	int		y;
	int		k;

	x = 0;
	k = var[1];
	while (x < 4)
	{
		var[1] = k;
		y = 0;
		while (y < 4)
		{
			if (map[var[0]][var[1]] == '.' && tetri[x][y] != '.')
				map[var[0]][var[1]] = tetri[x][y];
			var[1]++;
			y++;
		}
		var[0]++;
		x++;
	}
	return (map);
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
