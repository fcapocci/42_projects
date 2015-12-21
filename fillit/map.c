/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:32:47 by fcapocci          #+#    #+#             */
/*   Updated: 2015/12/17 16:31:23 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_map(void)
{
	char	**map;
	int		i;

	map = (char**)malloc(sizeof(char*) * 150);
	if (!map)
		return ((void*)0);
	i = 0;
	while (i < 150)
		map[i++] = (char*)malloc(sizeof(char) * 150);
	if (!(*map))
		return ((void*)0);
	map = fill_map(map);
	return (map);
}

char	**fill_map(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (i < 150)
	{
		j = 0;
		while (j < 150)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}
