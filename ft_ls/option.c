/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 18:30:17 by fcapocci          #+#    #+#             */
/*   Updated: 2016/01/28 21:48:44 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		compt_option(int argc, char **argv)
{
	int		compt;
	int		i;
	int		p;

	compt = 0;
	p = 1;
	while (p < argc)
	{
		if (argv[p][0] == '-')
		{
			i = 1;
			while (argv[p][i])
			{
				ft_putchar(argv[p][i++]);
				ft_putchar('\n');
				compt++;
			}
		}
		if (argv[p][0] != '-')
			break ;
		p++;
	}
	return (compt);
}

t_opt	*creat_elem(char o)
{
	t_opt	*new;

	if ((new = (t_opt*)ft_memalloc(sizeof(t_opt))) == NULL)
		return (NULL);
	new->c = o;
	new->next = NULL;
	return (new);
}

t_opt	*take_option(int argc, char **argv)
{
	t_opt	*optl[2];
	int		i[2];

	optl[1] = NULL;
	i[0] = 1;
	while (i[0] < argc)
	{
		if (argv[i[0]][0] == '-')
		{
			i[1] = 1;
			while (argv[i[0]][i[1]])
			{
				optl[0] = creat_elem(argv[i[0]][i[1]++]);
				if (!optl[1])
					optl[1] = optl[0];
				ft_putstr("optl[0]-> = ");
				ft_putchar(optl[0]->c);
				ft_putchar('\n');
				optl[0] = optl[0]->next;
			}
		}
		if (argv[i[0]++][0] != '-')
			break ;
	}
	ft_putstr("optl[1]-> = ");
	ft_putchar(optl[1]->c);
	ft_putchar('\n');
	return (optl[1]);
}
