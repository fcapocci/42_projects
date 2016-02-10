/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 16:25:02 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/10 18:21:46 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_opt(t_opt *optl)
{
	ft_putchar('\n');
	ft_putstr("option: ");
	while (optl)
	{
		ft_putchar('-');
		ft_putchar(optl->c);
		ft_putchar(' ');
		optl = optl->next;
	}
	ft_putstr("\n\n");
}

int		main(int argc, char **argv)
{
	t_dir		*list;
	t_opt		*optl;

	optl = NULL;
	list = NULL;
	if ((take_option(&optl, &argc, &argv)) == -1)
		return (-1);
	if ((manage(argc, argv, optl, list)) == -1)
		return (-1);
	ft_memdel((void**)&optl);
	return (0);
}
