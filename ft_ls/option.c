/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 18:30:17 by fcapocci          #+#    #+#             */
/*   Updated: 2016/01/27 20:54:33 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		compt_option(int argc, char **argv)
{
	int		compt;

	compt = 0;
	while (argc-- > 0)
	{
		if (argv[0][0] == '-')
			compt++;
		(*argv)++;
	}
	return (compt);
}

t_opt	*save_opt(int argc, char **argv)
{
	t_opt	*optl[2];

	if ((optl[0] = (t_opt*)ft_memalloc(sizeof(t_opt))) == NULL)
		return (NULL);
	while (argc-- > 0)
	{
		if (argv[0][0] == '-')
		{
			while (**argv != '\0')
			{
				optl[0]->o = **argv;
				if (!optl[1])
					optl[1] = optl[0];
				optl[0]->next = optl[0];
				(**argv)++;
			}
		}
		argc--;
	}
	return (optl[1]);
}

void	choice_opt_apt(t_opt *opt, t_dir *lst)
{
}
