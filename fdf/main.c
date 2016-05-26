/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:10:19 by fcapocci          #+#    #+#             */
/*   Updated: 2016/05/26 15:05:08 by fcapocci         ###   ########.fr       */
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
		if ((data_list = pars(argv[1], 1, NULL)) == NULL)
		{
			file_invalid(argv[1]);
			return (0);
		}
		if ((mem = ft_strrchr(argv[1], '/')) != NULL)
			mem++;
		else
			mem = argv[1];
		draw_map(data_list, mem);
	}
	free_list(&data_list);
	return (0);
}
