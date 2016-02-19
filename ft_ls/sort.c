/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 12:50:51 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/19 15:36:40 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_arg			*read_arg(t_opt *optl, int argc, char **argv)
{
	t_arg			*arg[2];

	arg[0] = NULL;
	arg[1] = NULL;
	argv = sort_arg_lex(argc, argv);
	while (argc-- > 1)
	{
		if (!arg[0])
		{
			if ((arg[0] = get_arg_content(*argv)))
				arg[1] = arg[0];
			else
				print_error(*argv, 0);
		}
		else
		{
			if ((arg[0]->next = get_arg_content(*argv)))
			{
				arg[0]->next->prev = arg[0];
				arg[0] = arg[0]->next;
			}
			else
				print_error(*argv, 0);
		}
		argv++;
	}
	arg[1] = (option_ok(optl, 't') == 1 ? sort_arg_time(arg[1]) : arg[1]);
	return (option_ok(optl, 'r') == 1 ? arg[0] : arg[1]);
}

t_arg			*get_arg_content(char *entity)
{
	t_arg			*arg;
	struct stat		stat;

	if ((arg = (t_arg*)ft_memalloc(sizeof(t_dir))) == NULL)
		return (NULL);
	if ((lstat(entity, &stat)) == -1)
		return (NULL);
	arg->argument = entity;
	arg->type = take_type(stat.st_mode);
	arg->time = stat.st_mtime;
	arg->prev = NULL;
	arg->next = NULL;
	return (arg);
}

char			**sort_arg_lex(int argc, char **argv)
{
	char			*tmp;
	int				i;

	i = 0;
	while (i != (argc - 2))
	{
		if (ft_strcmp(argv[i + 1], argv[i]) < 0)
		{
			tmp = argv[i + 1];
			argv[i + 1] = argv[i];
			argv[i] = tmp;
			i = -1;
		}
		i++;
	}
	return (argv);
}

t_arg			*sort_arg_time(t_arg *list)
{
	t_arg			*start;
	t_arg			*tmp;

	tmp = (t_arg*)ft_memalloc(sizeof(t_arg));
	start = list;
	while (list && list->next)
	{
		if (list->time < list->next->time)
		{
			tmp = swap_arg_content(tmp, list);
			list = swap_arg_content(list, list->next);
			list->next = swap_arg_content(list->next, tmp);
			list = start;
		}
		else
			list = list->next;
	}
	ft_memdel((void**)&tmp);
	return (start);
}

void			sort_list(t_opt *opl, t_dir **list, t_dir **slist, char *entity)
{
	if (!(*slist))
	{
		if (((*slist) = get_content(entity)))
			(*list) = (*slist);
		else
			print_error(entity, 1);
	}
	else
	{
		if (((*slist)->next = get_content(entity)))
		{
			(*slist)->next->prev = (*slist);
			(*slist) = (*slist)->next;
			(*slist)->next = NULL;
		}
		else
			print_error(entity, 1);
	}
	(*list) = sort_dir_lex((*list));
	(*list) = (option_ok(opl, 't') ? sort_dir_time((*list)) : (*list));
}
