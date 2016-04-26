/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:10:19 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/26 14:47:21 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main(int argc, char **argv)
{
	t_data			*data_list;

	data_list = NULL;
	if (argc != 2)
		usage_error(argc);
	else
	{
		if ((data_list = pars(argv[1])) == NULL)
			return (0);
		while (data_list)
		{
			ft_putstr("loop\n");
			ft_putnbr(data_list->x);
			ft_putchar('/');
			ft_putnbr(data_list->y);
			ft_putchar('/');
			ft_putnbr(data_list->h);
			ft_putchar('\n');
			data_list = data_list->next;
		}
	}
	return (0);
}
