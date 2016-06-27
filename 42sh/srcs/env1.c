/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 17:13:14 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/22 15:27:26 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/_42sh.h"
#include "../libft/libft.h"

static void					print_fail(char *name)
{
	ft_putstr(name);
	ft_putstr(" is missing\n");
}

static int					reset_nbr_env(t_env **lst)
{
	unsigned int			i;
	t_env					*curs;

	curs = (*lst);
	i = 0;
	while (curs != NULL && ++i > 0)
		curs = curs->next;
	curs = (*lst);
	while (i > 0)
	{
		curs->i = i--;
		curs = curs->next;
	}
	return (1);
}

int							del_one_env(t_env **lst, char *name)
{
	t_env					*curs;
	t_env					*prev;

	if (lst == NULL || (*lst) == NULL || name == NULL)
		return (-1);
	curs = (*lst);
	prev = NULL;
	while (curs != NULL)
	{
		if (ft_strcmp(curs->name, name) == 0)
		{
			if (prev == NULL)
				(*lst) = curs->next;
			else
				prev->next = curs->next;
			ft_memdel((void**)&curs->name);
			ft_memdel((void**)&curs->content);
			ft_memdel((void**)&curs);
			return (reset_nbr_env(lst));
		}
		prev = curs;
		curs = curs->next;
	}
	print_fail(name);
	return (1);
}

char						**new_var_env(t_42sh *sh)
{
	char					**env;
	unsigned int			nb_var;
	t_env					*curs;

	if (sh == NULL || sh->lst_env == NULL)
		return (NULL);
	nb_var = sh->lst_env->i;
	if ((env = ft_memalloc(sizeof(char *) * (nb_var + 1))) == NULL)
		return (NULL);
	curs = sh->lst_env;
	while (curs != NULL)
	{
		if ((env[--nb_var] = ft_multijoin(3, curs->name, "=", curs->content))
				== NULL)
			break ;
		curs = curs->next;
	}
	return (env);
}
