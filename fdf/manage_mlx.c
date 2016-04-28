/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 21:33:42 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/28 22:27:49 by fcapocci         ###   ########.fr       */
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
	window = mlx_new_window(mlx,500 , 500, "fdf");
	sleep(5);
	return (0);
}
