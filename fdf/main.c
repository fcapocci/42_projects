/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:10:19 by fcapocci          #+#    #+#             */
/*   Updated: 2016/05/17 13:20:25 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main(int argc, char **argv)
{
	t_data		*data_list;
	char		*mem;

	data_list = NULL;
	if (argc != 2)
		usage_error(argc);
	else
	{
		if ((data_list = pars(argv[1], 1)) == NULL)
		{
			file_invalid(argv[1]);
			return (0);
		}
		if ((mem = ft_strrchr(argv[1], '/')) != NULL)
			mem++;
		else
			mem = argv[1];
		if (draw_map(data_list, mem) == -1)
		{
			free_list(&data_list);
			return (0);
		}
	}
	free_list(&data_list);
	return (0);
}
