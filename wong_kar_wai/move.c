/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 15:57:30 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/31 18:15:33 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

#define A i[0]
#define B i[1]
#define C i[2]
#define CHECK i[3]
#define SIZE 4

static int	move_right(int **grid)
{
	int		i[4];

	A = 0;
	CHECK = 0;
	while (A < SIZE)
	{
		C = 0;
		while (C < SIZE - 1)
		{
			B = 0;
			while (B < SIZE - 1)
			{
				if (grid[A][B] != 0 && grid[A][B + 1] == 0)
				{
					grid[A][B + 1] = grid[A][B];
					grid[A][B] = 0;
					CHECK = 1;
				}
				B++;
			}
			C++;
		}
		A++;
	}
	return (CHECK);
}

static int	move_left(int **grid)
{
	int		i[4];

	A = 0;
	CHECK = 0;
	while (A < SIZE)
	{
		C = 0;
		while (C < SIZE - 1)
		{
			B = 0;
			while (B < SIZE - 1)
			{
				if (grid[A][B] == 0 && grid[A][B + 1] != 0)
				{
					grid[A][B] = grid[A][B + 1];
					grid[A][B + 1] = 0;
					CHECK = 1;
				}
				B++;
			}
			C++;
		}
		A++;
	}
	return (CHECK);
}

static int	move_down(int **grid)
{
	int		i[4];

	B = 0;
	CHECK = 0;
	while (B < SIZE)
	{
		C = 0;
		while (C < SIZE - 1)
		{
			A = 0;
			while (A < SIZE - 1)
			{
				if (grid[A + 1][B] == 0 && grid[A][B] != 0)
				{
					grid[A + 1][B] = grid[A][B];
					grid[A][B] = 0;
					CHECK = 1;
				}
				A++;
			}
			C++;
		}
		B++;
	}
	return (CHECK);
}

static int	move_up(int **grid)
{
	int		i[4];

	B = 0;
	CHECK = 0;
	while (B < SIZE)
	{
		C = 0;
		while (C < SIZE - 1)
		{
			A = 0;
			while (A < SIZE - 1)
			{
				if (grid[A][B] == 0 && grid[A + 1][B] != 0)
				{
					grid[A][B] = grid[A + 1][B];
					grid[A + 1][B] = 0;
					CHECK = 1;
				}
				A++;
			}
			C++;
		}
		B++;
	}
	return (CHECK);
}

int			move_grid(int **grid, int direction)
{
	int		ret;

	ret = 0;
	if (direction == KEY_RIGHT)
		ret = ret + move_right(grid);
	else if (direction == KEY_LEFT)
		ret = ret + move_left(grid);
	else if (direction == KEY_UP)
		ret = ret + move_up(grid);
	else if (direction == KEY_DOWN)
		ret = ret + move_down(grid);
	ret = ret + collision(grid, direction);
	if (direction == KEY_RIGHT)
		move_right(grid);
	else if (direction == KEY_LEFT)
		move_left(grid);
	else if (direction == KEY_UP)
		move_up(grid);
	else if (direction == KEY_DOWN)
		move_down(grid);
	return (ret);
}
