/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 13:26:10 by fcapocci          #+#    #+#             */
/*   Updated: 2016/05/14 17:52:27 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx_macos/mlx.h"

int				*zerotab(t_mlx *m)
{
	int			i;

	i = 0;
	while (i < m->xsize * m->ysize)
		m->intab[i++] = 0;
	return (m->intab);
}

void			other_events(int key, t_mlx *m)
{
	if (key == 69 || (key == 78 && m->gap > 0) || key == 83 || key == 84 ||
			key == 89 || key == 91 || key == 15)
	{
		m->intab = zerotab(m);
		fillintab(m->data, m, m->intab);
		//bresenham_x(m, m->data);
		//bresenham_y(m, m->data);
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

int				key(int key, t_mlx *m)
{
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53)
		exit(0);
	direction(key, m);
	if (key == 69 && m->maxx *(m->gap + 2) < m->xsize)
		m->gap++;
	if (key == 78)
	mlx_clear_window(m->mlx, m->win);
	other_events(key, m);
	mlx_put_image_to_window(m->mlx, m->win, m->img, m->imgx, m->imgy);
	return (0);
}
