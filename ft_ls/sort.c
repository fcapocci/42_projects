/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 12:50:51 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/17 02:52:05 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_arg			*read_arg(t_opt *optl, int argc, char **argv)
{
	t_arg			*arg[2];
	t_opt			*opi;

	opi = optl;
	arg[0] = NULL;
	while (argc-- > 1)
	{
		if (!arg[0])
			if ((arg[0] = get_arg_content(*argv)))
				arg[1] = arg[0];
			else
				print_error(*argv);
		else
			if ((arg[0]->next = get_arg_content(*argv)))
			{
				arg[0]->next->prev = arg[0];
				arg[0] = arg[0]->next;
			}
			else
				print_error(*argv);
		argv++;
	}
	arg[0] = sort_arg_lex(optl, arg[1]);
	if (option_ok(optl, 't') == 1)
		arg[0] = sort_arg_time(optl, arg[1]);
	return (arg[1]);
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

t_arg			*sort_arg_lex(t_opt *optl, t_arg *argument)
{
	t_arg			*arg[2];

	arg[1] = argument;
	while (argument->next)
	{
		if (ft_strcmp(argument->argument, argument->next->argument) == 1)
		{
			argument->next->prev = argument->prev;
			argument->prev = argument->next;
			argument->next = argument->next->next;
			argument->next->next = argument;
			argument = arg[1];
		}
		argument = argument->next;
	}
	arg[0] = argument;
	return (option_ok(optl, 'r') == 1 ? arg[0] : arg[1]);
}

t_arg			*sort_arg_time(t_opt *optl, t_arg *argument)
{
	t_arg			*arg[2];

	arg[1] = argument;
	while (argument->next)
	{
		if (argument->time > argument->next->time)
		{
			argument->next->prev = argument->prev;
			argument->prev = argument->next;
			argument->next = argument->next->next;
			argument->next->next = argument;
			argument = arg[1];
		}
		argument = argument->next;
	}
	arg[0] = argument;
	return (option_ok(optl, 'r') == 1 ? arg[0] : arg[1]);
}

void			sort_list(t_dir **list, t_dir **slist, char *entity)
{
	t_dir			*ptr;

	ptr = (*list);
	if (!(*slist))
		if (((*slist) = get_content(entity)))
			(*list) = (*slist);
		else
			print_error(entity);
	else
		/*
		if (ft_strcmp(get_content(entity)->name, (*slist)->name) == 1)
		{
			(*slist)->next = get_content(entity);
			(*slist)->next->prev = (*slist);
			(*slist) = (*slist)->next;
		}
		else
		{
			(*list)->prev = get_content(entity);
			(*list)->prev->next = (*list);
			(*list) = (*list)->prev;
		}
		*/
		if (((*slist)->next = get_content(entity)))
		{
			(*slist)->next->prev = (*slist);
			(*slist) = (*slist)->next;
			(*slist)->next = NULL;
		}
		else
			print_error(entity);
}
