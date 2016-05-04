/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 21:33:42 by fcapocci          #+#    #+#             */
/*   Updated: 2016/05/04 17:28:23 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx_macos/mlx.h"

int				manage_mlx(t_data *d_list)
{
	void		*mlx;
	void		*window;

	d_list = d_list ? d_list : NULL;
	mlx = mlx_init();
	window = mlx_new_window(mlx,1500 , 800, "fdf");
	while (d_list)
	{
		mlx_pixel_put(mlx, window, d_list->x, d_list->y, 0xFF0000);
		d_list = d_list->next;
	}
	mlx_loop(mlx);
	return (0);
}
