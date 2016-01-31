/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:42:48 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/31 18:59:17 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

#define A i[0]
#define B i[1]
#define SIZE 4

static int		check_victory(int **grid)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (i < SIZE)
	{
		y = 0;
		while (y < SIZE)
		{
			if (grid[i][y] == WIN_VALUE)
				return (2);
			y++;
		}
		i++;
	}
	return (0);
}

static int		check_adj(int **grid)
{
	int		i[2];

	A = 0;
	while (A < SIZE)
	{
		B = 0;
		while (B < SIZE)
		{
			if (A > 0)
				if (grid[A - 1][B] == grid[A][B])
					return (0);
			if (A < SIZE - 1)
				if (grid[A + 1][B] == grid[A][B])
					return (0);
			if (B < SIZE - 1)
				if (grid[A][B + 1] == grid[A][B])
					return (0);
			if (B > 0)
				if (grid[A][B - 1] == grid[A][B])
					return (0);
			B++;
		}
		A++;
	}
	return (1);
}

static int		check_lose(int **grid)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (i < SIZE)
	{
		y = 0;
		while (y < SIZE)
		{
			if (grid[i][y] == 0)
				return (0);
			y++;
		}
		i++;
	}
	return (check_adj(grid));
}

int				check_end(int **grid)
{
	return (check_victory(grid) + check_lose(grid));
}
