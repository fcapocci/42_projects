/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 21:22:30 by fcapocci          #+#    #+#             */
/*   Updated: 2016/01/31 20:49:04 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

#define DCH def[0]
#define DCOND def[1]

static int		lose_game(int **dtab, int lines, int cols)
{
	if (check_end(dtab) == 1 || check_end(dtab) == 3)
	{
		clear();
		mvprintw(lines / 4 + 2, cols / 4 + 2, "YOU LOSE");
		getch();
		return (1);
	}
	return (0);
}

static int		win_game(int *cond, int **dtab, int lines, int cols)
{
	int		ch;

	if (*cond == 0)
	{
		*cond = check_end(dtab);
		if (*cond > 0)
		{
			if (*cond > 1)
			{
				clear();
				mvprintw(lines / 4 + 2, cols / 4 + 2, "YOU WIN, CONTINUE ?");
				mvprintw(lines / 4 + 3, cols / 4 + 2, "ESC : QUIT");
				mvprintw(lines / 4 + 4, cols / 4 + 2, "KEY : CONTINUE");
			}
			ch = getch();
			if (ch == 27)
				return (1);
			clear();
		}
	}
	return (0);
}

static void		do_resize(int *tab, t_win *board, int lines, int cols)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	while (i < 16)
	{
		x = (i % 4 == 0) ? 0 : 0;
		x = (i % 4 == 1) ? cols : x;
		x = (i % 4 == 2) ? (cols * 2) : x;
		x = (i % 4 == 3) ? (cols * 3) : x;
		y = (i / 4 == 0) ? 0 : 0;
		y = (i / 4 == 1) ? lines : y;
		y = (i / 4 == 2) ? (lines * 2) : y;
		y = (i / 4 == 3) ? (lines * 3) : y;
		delwin(board[i].my_win);
		board[i].my_win = newwin(lines, cols, y, x);
		if (tab[i])
			mvprintw(y + (lines / 2), x + (cols / 2), "%d", tab[i]);
		box(board[i].my_win, 0, 0);
		wrefresh(board[i++].my_win);
		refresh();
	}
	return ;
}

static void		init_ncurses(int *tab)
{
	fill_grid(tab);
	generation(tab, 2);
	initscr();
	raw();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(FALSE);
}

int				main(void)
{
	int		def[2];
	int		**dtab;
	int		*tab;
	t_win	board[16];

	tab = NULL;
	dtab = NULL;
	if (initialisation(&DCH, &DCOND, &tab, &dtab) == -1)
		return (-1);
	init_ncurses(tab);
	while (DCH != 27 && win_game(&DCOND, dtab, LINES, COLS) == 0 &&
			lose_game(dtab, LINES, COLS) == 0)
	{
		clear();
		do_resize(tab, board, LINES / 4, COLS / 4);
		DCH = getch();
		if (DCH == 261 || DCH == 258 || DCH == 260 || DCH == 259)
			if (move_grid(dtab, DCH) >= 1)
				generation(tab, 1);
	}
	endwin();
	free(dtab);
	free(tab);
	return (0);
}
