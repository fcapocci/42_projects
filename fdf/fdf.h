/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 12:02:17 by fcapocci          #+#    #+#             */
/*   Updated: 2016/05/14 17:45:00 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include "libft/libft.h"

# define WW 1380
# define HW 850

typedef struct				s_data
{
	int						x;
	int						y;
	int						h;
	struct s_data			*next;
}							t_data;

typedef struct				s_mlx
{
	int						gap;
	int						height;
	int						imgx;
	int						imgy;
	void					*mlx;
	void					*win;
	void					*img;
	int						bits;
	int						size;
	int						endian;
	int						xsize;
	int						ysize;
	int						maxx;
	int						maxy;
	int						color;
	int						*intab;
	t_data					*data;
}							t_mlx;

/*
**	parsing.c
*/

t_data						*creat_elem(int x, int y, int c);
t_data						*creat_list(t_data *d_list, char **data_tab, int y);
t_data						*pars(char *files, int ret);

/*
**	manage_mlx.c
*/

int							*fillintab(t_data *d_list, t_mlx *m, int *intab);
void						max_size(int max[2], t_data *d_list);
t_mlx						*init_mlx(t_data *d_list, char *name);
int							draw_map(t_data *data_list, char *name);

/*
**	colors.c
*/

int							color_pos(int h);
int							color_neg(int h);

/*
**	modif.c
*/

int							*zerotab(t_mlx *m);
void						other_event(int key, t_mlx *m);
void						direction(int key, t_mlx *m);
int							key(int key, t_mlx *m);

/*
**	error.c
*/

void						usage_error(int argc);

/*
**	free.c
*/

void						free_list(t_data **d_list);

#endif
