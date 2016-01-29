/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 18:30:17 by fcapocci          #+#    #+#             */
/*   Updated: 2016/01/29 20:59:41 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_opt	*creat_elem(t_opt *optl, char o)
{
	t_opt	*new;

	if (check_option(o) == 1)
	{
		if ((new = (t_opt*)ft_memalloc(sizeof(t_opt))) == NULL)
			return (NULL);
		if (!optl)
			optl = new;
		else
			optl->next = new;
		new->c = o;
		new->next = NULL;
	}
	return (new);
}

t_opt	*take_option(int argc, char **argv)
{
	t_opt	*optl[2];
	int		i[2];

	optl[0] = NULL;
	optl[1] = NULL;
	i[0] = 1;
	while (i[0] < argc)
	{
		if (argv[i[0]][0] == '-')
		{
			i[1] = 1;
			while (argv[i[0]][i[1]])
			{
				optl[0] = creat_elem(optl[0], argv[i[0]][i[1]++]);
				if (!optl[1])
					optl[1] = optl[0];
			}
		}
		if (argv[i[0]++][0] != '-')
			break ;
	}
	return (optl[1]);
}

int		check_option(char o)
{
	if (o == 'l')
		return (1);
	if (o == 'r')
		return (1);
	if (o == 't')
		return (1);
	if (o == 'a')
		return (1);
	if (o == 'R')
		return (1);
	if (o == '1')
		return (1);
	else
	{
		illegal_option(o);
		exit (-1);
	}
	return (0);
}
