/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checktetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:18:02 by vcastro-          #+#    #+#             */
/*   Updated: 2016/01/12 14:27:29 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_tetri_ok(char *file, char **piece)
{
	int		i;
	int		j;
	int		count;

	while (*file != '\0')
	{
		count = 0;
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				if (*file == piece[i][j])
					count++;
				j++;
				file++;
			}
			i++;
		}
		if (count == 16)
			return (SUCCESS);
	}
	return (ERROR);
}

int		are_tetris_ok(t_tlist *list)
{
	char	*file;

	file = malloc(sizeof(char) * 305);
	file = "#...##...#.......##.##...........#..##..#.......##...##.........##";
	file = ft_strjoin(file, "...#...#........#.###.........###.#...........#.");
	file = ft_strjoin(file, "..#...##......#...#...#...#...####............##");
	file = ft_strjoin(file, "#..#..........#...##..#........#..###..........#");
	file = ft_strjoin(file, "..##...#......##..#...#.......#...###..........#");
	file = ft_strjoin(file, "...#..##......###...#.........##..##..........");
	while (list)
	{
		if (is_tetri_ok(file, list->tetri) == ERROR)
			return (ERROR);
		list = list->next;
	}
	return (SUCCESS);
}
