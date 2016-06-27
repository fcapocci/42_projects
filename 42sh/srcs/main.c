/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 17:38:51 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/22 15:41:14 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/_42sh.h"
#include "../libft/libft.h"




#include <stdio.h>

int							builtin_error(char *builtin)
{
	ft_putstr(builtin);
	ft_putstr(" error\n");
	return (BUILT);
}

void						error(char *s)
{
	ft_putendl(s);
	exit (-1);
}

static void					print_lst_hash(t_bin *lst)
{
	t_bin					*curs;

	curs = lst;
	while (curs != NULL)
	{
		printf("%u \t%10s %10s\n", curs->i_hash, curs->name, curs->path);
		curs = curs->h_next;
	}
}

static void					print_lst_sort(t_bin *lst)
{
	t_bin					*curs;

	curs = lst;
	while (curs != NULL)
	{
		printf("%u %16s\n", curs->i_sort, curs->name);
		curs = curs->s_next;
	}
}


void						print_hash_sort_bin(t_42sh *sh)
{
	unsigned int			i;

	i = 0;
	while (i++ < SIZE_HASH)
		print_lst_hash(sh->hash_bin[i - 1]);
	i = 0;
	while (i < SIZE_SORT)
		print_lst_sort(sh->sort_bin[i++]);
}

int							main(int argc, char **argv, char **env)
{
	t_42sh					*sh;

	if ((sh = init_sh(env)) == NULL)
		error("Init error sh");
	loop_shell(sh);
	return (0);
}
