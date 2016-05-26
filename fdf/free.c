/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 19:43:15 by fcapocci          #+#    #+#             */
/*   Updated: 2016/05/26 13:07:40 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx_macos/mlx.h"

void			free_list(t_data **d_list)
{
	t_data		*tmp;

	while (*d_list)
	{
		tmp = (*d_list)->next;
		ft_memdel((void**)&(*d_list));
		*d_list = tmp;
	}
	ft_memdel((void**)&(*d_list));
}

void			destroy(t_mlx *m)
{
	mlx_destroy_image(m->mlx, m->img);
	mlx_destroy_window(m->mlx, m->win);
	free_list(&m->data);
	exit(0);
}
