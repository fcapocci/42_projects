/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 13:26:10 by fcapocci          #+#    #+#             */
/*   Updated: 2016/05/30 20:27:51 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx_macos/mlx.h"

void			reset(t_mlx *m)
{
	m->height = 1;
	m->color = 16777215;
	m->xsize = WW;
	m->ysize = HW;
	m->imgx = 75;
	m->imgy = 75;
	m->gap = GAP;
}

int				*zerotab(t_mlx *m)
{
	int			i;

	i = 0;
	while (i < m->xsize * m->ysize)
		m->intab[i++] = 0;
	return (m->intab);
}

void			other_events(int keycode, t_mlx *m)
{
	if (keycode == 69 || (keycode == 78 && m->gap > 0) || keycode == 83
			|| keycode == 84 || keycode == 89 || keycode == 91 || keycode == 15)
	{
		m->intab = zerotab(m);
		fillintab(m->data, m, m->intab);
		bresenham_x(m, m->data);
		bresenham_y(m, m->data);
	}
}

void			direction(int key, t_mlx *m)
{
	if (key == 126)
		m->imgy -= 10;
	else if (key == 124)
		m->imgx += 10;
	else if (key == 125)
		m->imgy += 10;
	else if (key == 123)
		m->imgx -= 10;
}

int				key(int keycode, t_mlx *m)
{
	if (keycode == 53)
		destroy(m);
	direction(keycode, m);
	if (keycode == 69 && m->maxx * (m->gap + 2) < 1300)
		m->gap++;
	else if (keycode == 78 && m->gap > 0)
		m->gap--;
	else if (keycode == 83)
		m->color -= 512;
	else if (keycode == 84)
		m->color += 512;
	else if (keycode == 89 && m->height > -3)
		m->height--;
	else if (keycode == 91 && m->height < 3)
		m->height++;
	else if (keycode == 15)
		reset(m);
	mlx_clear_window(m->mlx, m->win);
	other_events(keycode, m);
	mlx_put_image_to_window(m->mlx, m->win, m->img, m->imgx, m->imgy);
	return (0);
}
