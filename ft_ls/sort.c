/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 12:50:51 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/12 18:28:40 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		**sort_arg(t_opt *optl, char **argv)
{
	char		*tmp;
	int			i;

	i = 0;
	while (argv[i + 1])
	{
		if (ft_strcmp(argv[i], argv[i + 1]) == (option_ok(optl, 'r')
			== 1 ? -1 : 1))
		{
			tmp = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	return (argv);
}
