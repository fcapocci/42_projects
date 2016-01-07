/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolv_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:34:09 by vcastro-          #+#    #+#             */
/*   Updated: 2016/01/07 15:49:38 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tetri_size_h(char **tetri)
{
	int		i;
	int		j;
	int		size;

	size = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetri[i][j] != '.' && j > size)
				size = j;
			j++;
		}
		i++;
	}
	return (size);
}

int		tetri_size_v(char **tetri)
{
	int		i;
	int		j;
	int		size;

	size = 0;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tetri[i][j] != '.' && i > size)
				size = i;
			i++;
		}
		j++;
	}
	return (size);
}

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

int		is_piece_placable(char **map, int *var, int size, t_tlist *pieces)
{
	if (is_tetri_writable(map, pieces->tetri, var[0], var[1]) == 1)
	{
		if ((var[0] + tetri_size_v(pieces->tetri)) < size &&
			(var[1] + tetri_size_h(pieces->tetri)) < size)
			return (SUCCESS);
	}
	return (ERROR);
}

char	**backtrackit(char **map, int size, t_tlist *pieces)
{
	int		var[2];
	char	letter;

	printf("__ WHILE BACKTRACK __\n");
	if (!pieces)
		return (map);
	var[0] = 0;
	var[1] = 0;
	while (var[0] < size)
	{
		printf("A : %c\n", map[0][0]);
		printf("piece is placable return : %d\n", is_piece_placable(map, var, size, pieces));
		if ((is_piece_placable(map, var, size, pieces) == 1))
		{
			printf("B : %c\n", map[0][0]);
			letter = getletter(pieces->tetri);
			printf("C : %c\n", map[0][0]);
			map = add_piece(map, var, pieces->tetri);
			printf("D : %c\n", map[0][0]);
			if (backtrackit(map, size, pieces))
				return (map);
			printf("E : %c\n", map[0][0]);
			map = remove_piece(map, size, letter);
			printf("F : %c\n", map[0][0]);
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
