/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 12:04:22 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/31 17:34:36 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

#define SIZE 16

void			fill_grid(int *grid)
{
	int		i;

	i = 0;
	while (i < SIZE)
	{
		grid[i] = 0;
		i++;
	}
}
