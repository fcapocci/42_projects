/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 12:50:51 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/13 15:16:02 by fcapocci         ###   ########.fr       */
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

void		sort_list(t_opt *optl, t_dir **list, t_dir **slist, char *entity)
{
	t_opt		*opop;

	opop = optl;
	if (!(*slist))
	{
		(*slist) = get_content(entity);
		(*slist)->prev = NULL;
		(*list) = (*slist);
	}
	else
	{
		(*slist)->next = get_content(entity);
		(*slist)->next->prev = (*slist);
		(*slist) = (*slist)->next;
	}
}
