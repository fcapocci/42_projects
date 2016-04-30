/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 21:33:42 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/29 15:00:37 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx_macos/mlx.h"

int				manage_mlx(t_data *d_list)
{
	void		*mlx;
	void		*window;
	int			x;
	int			y;

	y = 260;
	d_list = d_list ? d_list : NULL;
	mlx = mlx_init();
	window = mlx_new_window(mlx,1500 , 800, "fdf");
	while (y < 520)
	{
		x = 500;
		while (x < 1000)
		{
			mlx_pixel_put(mlx, window, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
	sleep(10);
	return (0);
}
