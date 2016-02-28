/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 18:30:17 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/28 19:32:43 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_opt	*creat_elem(t_opt *optl, char o)
{
	t_opt	*new;

	new = NULL;
	if (check_option(o) == 1)
	{
		if ((new = (t_opt*)ft_memalloc(sizeof(t_opt))) == NULL)
			return (NULL);
		if (!optl)
			optl = new;
		else
		{
			while (optl->next)
				optl = optl->next;
			optl->next = new;
		}
		new->c = o;
		new->next = NULL;
		if (o == 'n' || o == 'f')
		{
			new->next = (o == 'n' ? creat_elem(new->next, 'l') :
			creat_elem(new->next, 'a'));
			return (new);
		}
	}
	return (new);
}

int		take_option(t_opt **optl, int *argc, char ***argv)
{
	t_opt	*optlist;
	int		i;

	(*optl) = NULL;
	optlist = NULL;
	while ((*argc) > 1)
	{
		(*argv)++;
		if ((***argv != '-') || (***argv == '-' && !(**argv)[1]))
		{
			break ;
		}
		else if (***argv == '-')
		{
			i = 1;
			while ((**argv)[i])
			{
				optlist = creat_elem(optlist, (**argv)[i++]);
				if (!(*optl))
					(*optl) = optlist;
			}
		}
		(*argc)--;
	}
	return (0);
}

int		check_option(char o)
{
	if (o == 'l')
		return (1);
	if (o == 'r')
		return (1);
	if (o == 't' || o == 'f')
		return (1);
	if (o == 'a')
		return (1);
	if (o == 'R')
		return (1);
	if (o == 'G')
		return (1);
	if (o == 'g')
		return (1);
	if (o == 'o')
		return (1);
	if (o == 'n')
		return (1);
	else
	{
		illegal_option(o);
		exit(-1);
	}
	return (0);
}

int		op_ok(t_opt *optl, char o)
{
	while (optl)
	{
		if (optl->c == o)
			return (1);
		optl = optl->next;
	}
	return (0);
}
