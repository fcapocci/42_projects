/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 12:02:17 by fcapocci          #+#    #+#             */
/*   Updated: 2016/06/01 09:02:16 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include "libft/libft.h"

# define WW 2048
# define HW 1024
# define GAP 8;

typedef struct				s_data
{
	int						x;
	int						y;
	int						h;
	struct s_data			*next;
}							t_data;

typedef struct				s_brs
{
	int						ex;
	int						ey;
	int						dx;
	int						dy;
	int						gdx;
	int						gdy;
	int						i;
	int						gxincr;
	int						gyincr;
}							t_brs;

typedef struct				s_pos
{
	int						x1;
	int						y1;
	int						x2;
	int						y2;
}							t_pos;

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

int							chek_lenline(char *line);
int							next_line_val(t_data *d_list, int y, int x);
t_data						*creat_elem(int x, int y, int c);
t_data						*creat_list(t_data *d_list, char **data_tab, int y);
t_data						*pars(char *files, int ret, char *line);

/*
**	manage_mlx.c
*/

int							*fillintab(t_data *d_list, t_mlx *m, int *intab);
void						max_size(int max[2], t_data *d_list);
void						init_mlx(t_mlx *m, t_data *d_list, char *name);
int							draw_map(t_data *data_list, char *name);

/*
**	brasenham.c
*/

void						ft_put_pixels(int x, int y, t_mlx *m, int z);
void						init_brs(t_brs *b, t_pos *p);
void						trace_line(t_mlx *m, t_pos *p, int z);
void						bresenham_x(t_mlx *m, t_data *d_list);
void						bresenham_y(t_mlx *m, t_data *d_list);

/*
**	colors.c
*/

int							color_pos(int h);
int							color_neg(int h);

/*
**	modif.c
*/

void						reset(t_mlx *m);
int							*zerotab(t_mlx *m);
void						other_event(int key, t_mlx *m);
void						direction(int key, t_mlx *m);
int							key(int key, t_mlx *m);

/*
**	error.c
*/

void						usage_error(int argc);
void						file_invalid(char *name);

/*
**	free.c
*/

void						free_list(t_data **d_list);
void						destroy(t_mlx *m);

#endif
