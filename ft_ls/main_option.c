/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 08:37:50 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/04 11:18:27 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_opt		*opt;

	if (argc > 1)
	{
		if (take_option(&opt, argc, argv) == -1)
			return (-1);
		while (opt)
		{
			ft_putchar(opt->c);
			ft_putstr(" -- ");
			opt = opt->next;
		}
		ft_putchar('\n');
	}
	return (0);
}
