/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 12:04:22 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/31 18:21:21 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdlib.h>
#include <time.h>

#define SIZE 16

void			generation(int *grid, int times)
{
	int		random_i;
	int		i;

	i = 0;
	srand(time(NULL));
	while (i < times)
	{
		random_i = rand() % (SIZE);
		if (grid[random_i] == 0)
		{
			grid[random_i] = (rand() % 3) + 2;
			if (grid[random_i] == 3)
				grid[random_i] = 2;
			i++;
		}
	}
}
