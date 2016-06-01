/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 11:02:02 by fcapocci          #+#    #+#             */
/*   Updated: 2016/06/01 09:14:00 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_put_pixels(int x, int y, t_mlx *m, int z)
{
	if ((x + y + 135300) >= 0)
		m->intab[x + 135300 + y * m->xsize] = m->color - (z * 0x00FFFF / 10);
}

void			init_brs(t_brs *b, t_pos *p)
{
	b->ex = p->x2 - p->x1 >= 0 ? p->x2 - p->x1 : -(p->x2 - p->x1);
	b->ey = p->y2 - p->y1 >= 0 ? p->y2 - p->y1 : -(p->y2 - p->y1);
	b->dx = 2 * b->ex;
	b->dy = 2 * b->ey;
	b->gdx = b->ex;
	b->gdy = b->ey;
	b->i = 0;
	b->gxincr = p->x1 >= p->x2 ? -1 : 1;
	b->gyincr = p->y1 >= p->y2 ? -1 : 1;
}

void			trace_line(t_mlx *m, t_pos *p, int z)
{
	t_brs		b;

	init_brs(&b, p);
	while (b.i++ <= b.gdx && b.gdx >= b.gdy)
	{
		ft_put_pixels(p->x1, p->y1, m, z);
		p->x1 += b.gxincr;
		b.ex -= b.dy;
		if (b.ex < 0)
		{
			p->y1 += b.gyincr;
			b.ex += b.dx;
		}
	}
	while (b.i++ <= b.gdy && b.gdx <= b.gdy)
	{
		ft_put_pixels(p->x1, p->y1, m, z);
		p->y1 += b.gyincr;
		b.ey -= b.dx;
		if (b.ey < 0)
		{
			p->x1 += b.gxincr;
			b.ey += b.dy;
		}
	}
}

void			bresenham_x(t_mlx *m, t_data *d_list)
{
	int			i;
	t_pos		p;

	i = 0;
	while (d_list->next)
	{
		if (d_list->x == 0)
			i = 0;
		if (d_list->next->y == d_list->y)
		{
			p.x1 = i * m->gap - d_list->h * m->height;
			p.y1 = d_list->y * m->gap - d_list->h * m->height;
			p.x2 = (i + 1) * m->gap - d_list->next->h * m->height;
			p.y2 = d_list->y * m->gap - d_list->next->h * m->height;
			trace_line(m, &p, d_list->h);
			i++;
		}
		d_list = d_list->next;
	}
}

void			bresenham_y(t_mlx *m, t_data *d_list)
{
	int			i;
	int			val;
	t_pos		p;

	i = 0;
	while ((val = next_line_val(d_list, d_list->y, d_list->x)) != -20000)
	{
		if (d_list->x == 0)
			i = 0;
		p.x1 = i * m->gap - d_list->h * m->height;
		p.y1 = (d_list->y * m->gap - d_list->h * m->height);
		p.x2 = i * m->gap - val * m->height;
		p.y2 = ((d_list->y + 1) * m->gap) - val * m->height;
		trace_line(m, &p, d_list->h);
		i++;
		d_list = d_list->next;
	}
}
