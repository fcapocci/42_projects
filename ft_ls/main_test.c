/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 16:25:02 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/05 19:10:01 by fcapocci         ###   ########.fr       */
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
	char		*dirname;

	optl = NULL;
	list = NULL;
	dirname = manage_rep(argv);
	if ((take_option(&optl, argc, argv)) == -1)
		return (-1);
	if ((read_dir(&list, dirname)) == -1)
		return (-1);
	print_opt(optl);
	manage(optl, list);
	return (0);
}
