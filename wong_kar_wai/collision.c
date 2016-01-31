/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 17:23:22 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/31 17:05:00 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <ncurses.h>

#define SIZE 4

static int	collision_right(int **grid)
{
	int		i;
	int		y;
	int		check;

	i = 0;
	check = 0;
	while (i < SIZE)
	{
		y = SIZE - 1;
		while (y > 0)
		{
			if (grid[i][y] == grid[i][y - 1] && grid[i][y] != 0)
			{
				grid[i][y] = grid[i][y] + grid[i][y - 1];
				grid[i][y - 1] = 0;
				check = 1;
			}
			y--;
		}
		i++;
	}
	return (check);
}

static int	collision_left(int **grid)
{
	int		i;
	int		y;
	int		check;

	i = 0;
	check = 0;
	while (i < SIZE)
	{
		y = 0;
		while (y < SIZE - 1)
		{
			if (grid[i][y] == grid[i][y + 1] && grid[i][y] != 0)
			{
				grid[i][y] = grid[i][y] + grid[i][y + 1];
				grid[i][y + 1] = 0;
				check = 1;
			}
			y++;
		}
		i++;
	}
	return (check);
}

static int	collision_up(int **grid)
{
	int		i;
	int		y;
	int		check;

	check = 0;
	y = 0;
	while (y < SIZE)
	{
		i = 0;
		while (i < SIZE - 1)
		{
			if (grid[i][y] == grid[i + 1][y] && grid[i][y] != 0)
			{
				grid[i][y] = grid[i][y] + grid[i + 1][y];
				grid[i + 1][y] = 0;
				check = 1;
			}
			i++;
		}
		y++;
	}
	return (check);
}

static int	collision_down(int **grid)
{
	int		i;
	int		y;
	int		check;

	y = 0;
	check = 0;
	while (y < SIZE)
	{
		i = SIZE - 1;
		while (i > 0)
		{
			if (grid[i][y] == grid[i - 1][y] && grid[i][y] != 0)
			{
				grid[i][y] = grid[i][y] + grid[i - 1][y];
				grid[i - 1][y] = 0;
				check = 1;
			}
			i--;
		}
		y++;
	}
	return (check);
}

int			collision(int **grid, int direction)
{
	int		ret;

	ret = 0;
	if (direction == KEY_RIGHT)
		ret = ret + collision_right(grid);
	else if (direction == KEY_LEFT)
		ret = ret + collision_left(grid);
	else if (direction == KEY_UP)
		ret = ret + collision_up(grid);
	else if (direction == KEY_DOWN)
		ret = ret + collision_down(grid);
	return (ret);
}
