/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 12:13:08 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/31 21:10:30 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include <curses.h>
# include <signal.h>
# include <stdlib.h>

enum					e_const
{
	WIN_VALUE = 64
};

typedef struct			s_win
{
	WINDOW		*my_win;
}						t_win;

int						check_end(int **grid);
int						move_grid(int **grid, int direction);
int						collision(int **grid, int direction);
void					generation(int *grid, int times);
int						**ft_d_array(int *tab);
void					fill_grid(int *grid);
int						initialisation(int *a, int *b, int **tab, int ***dtab);

#endif
