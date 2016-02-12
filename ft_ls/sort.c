/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 12:50:51 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/12 14:56:13 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		**sort_arg(t_opt *optl, char **argv)
{
	char		*tmp;
	char		**start;
	t_opt		*opop;

	opop = optl;
	start = argv;
	while (argv[1])
	{
		argv = start;
		ft_putendl(argv[1]);
		ft_putendl(argv[0]);
		if (ft_strcmp(argv[1], argv[0]) == 1)
		{
			tmp = argv[0];
			argv[0] = argv[1];
			argv[1] = tmp;
		}
		argv++;
	}
	return (start);
}
