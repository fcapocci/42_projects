/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolv_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:34:09 by vcastro-          #+#    #+#             */
/*   Updated: 2015/12/29 13:39:38 by fcapocci         ###   ########.fr       */
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

/*int		is_in_range(int size, char **map, chqr **tetri)
{
	int		k[2];

	k[0] = i;
	k[1] = j;
	
}*/
