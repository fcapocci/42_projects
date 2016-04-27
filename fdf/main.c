/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:10:19 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/27 20:43:48 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main(int argc, char **argv)
{
	t_data		*data_list;
	t_data		*tmp;

	data_list = NULL;
	if (argc != 2)
		usage_error(argc);
	else
	{
		if ((data_list = pars(argv[1], 1)) == NULL)
			return (0);
	}
	tmp = data_list;
	while (tmp)
	{
		ft_putnbr(tmp->y);
		ft_putchar('/');
		ft_putnbr(tmp->x);
		ft_putchar('/');
		ft_putnbr(tmp->h);
		ft_putchar('\n');
		tmp = tmp->next;
	}
	free_list(&data_list);
	return (0);
}
