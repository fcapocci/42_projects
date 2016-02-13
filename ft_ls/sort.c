/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 12:50:51 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/13 19:33:59 by fcapocci         ###   ########.fr       */
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

void		sort_list(t_dir **list, t_dir **slist, char *entity)
{
	t_dir		*ptr;

	ptr = (*list);
	if (!(*slist))
	{
		//ft_putendl("test1");
		(*slist) = get_content(entity);
		(*list) = (*slist);
	}
	else
	{
		/*
		(*slist)->next = get_content(entity);
		(*slist) = (*slist)->next;
		ft_putendl("test");
		while (ptr->next && ft_strcmp((*slist)->name, ptr->name) == 1)
		{
			ft_putendl("pouet");
			ptr = ptr->next;
		}
		if (!ptr->prev)
		{
			ft_putendl("test2");
			ptr->prev = (*slist);
			ptr->prev->next = ptr;
			ptr->prev->prev = NULL;
			(*list) = ptr->prev;
		}
		else
		{
			ft_putendl("test3");
			ptr->prev->next = (*slist);
			ptr->next->prev = (*slist);
		}
		(*slist) = (*slist)->next;
		*/
		(*slist)->next = get_content(entity);
		(*slist)->next->prev = (*slist);
		(*slist) = (*slist)->next;
		(*slist)->next = NULL;
	}
}
