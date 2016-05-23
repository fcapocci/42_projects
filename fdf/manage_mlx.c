/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 21:33:42 by fcapocci          #+#    #+#             */
/*   Updated: 2016/05/23 18:29:35 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx_macos/mlx.h"

int				*fillintab(t_data *d_list, t_mlx *m, int *intab)
{
	int				x;
	int				y;

	while (d_list)
	{
		x = d_list->x * m->gap - d_list->h * m->height;
		y = d_list->y * m->gap * m->xsize - d_list->h * m->height * m->xsize;
		if ((x + y + 135300) >= 0)
			intab[x + y + 135300] = 0xFFFFFF - (d_list->h * 256);
		d_list = d_list->next;
	}
	return (intab);
}

void			max_sizes(int max[2], t_data *d_list)
{
	max[0] = 0;
	max[1] = 0;
	while (d_list)
	{
		if ((d_list->x + 1) > max[0])
			max[0] = d_list->x + 1;
		if (d_list->y > max[1])
			max[1] = d_list->y;
		d_list = d_list->next;
	}
}

void			init_mlx(t_mlx *m, t_data *d_list, char *name)
{
	int				max[2];

	max_sizes(max, d_list);
	m->height = 1;
	m->color = 16777215;
	m->data = d_list;
	m->mlx = mlx_init();
	m->xsize = WW;
	m->ysize = HW;
	m->maxx = max[0];
	m->maxy = max[1];
	m->imgx = 75;
	m->imgy = 75;
	m->gap = GAP;
	m->win = mlx_new_window(m->mlx, m->xsize, m->ysize, name);
	m->img = mlx_new_image(m->mlx, m->xsize, m->ysize);
	m->intab = fillintab(d_list, m, (int*)mlx_get_data_addr(m->img, &m->bits,
				&m->size, &m->endian));
}

int				draw_map(t_data *d_list, char *name)
{
	t_mlx			m;

	init_mlx(&m, d_list, name);
	bresenham_x(&m, d_list);
	bresenham_y(&m, d_list);
	mlx_put_image_to_window(m.mlx, m.win, m.img, m.imgx, m.imgy);
	mlx_hook(m.win, 2, 1, key, &m);
	mlx_loop(m.mlx);
	return (0);
}
