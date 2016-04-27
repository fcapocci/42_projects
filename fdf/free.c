/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 19:43:15 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/27 18:12:29 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
