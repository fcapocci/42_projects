/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:10:19 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/28 22:41:11 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main(int argc, char **argv)
{
	t_data		*data_list;

	data_list = NULL;
	if (argc != 2)
		usage_error(argc);
	else
	{
		if ((data_list = pars(argv[1], 1)) == NULL)
			return (0);
		if (manage_mlx(data_list) == -1)
		{
			free_list(&data_list);
			return (0);
		}
	}
	free_list(&data_list);
	return (0);
}
