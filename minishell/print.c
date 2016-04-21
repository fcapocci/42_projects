/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 03:11:16 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/21 12:11:24 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			no_cmd(char *name)
{
	if (*name != '\0')
	{
		ft_putstr("minishell: command not found: ");
		ft_putendl(name);
	}
}

void			not_perms(char *name)
{
	if (*name != '\0')
	{
		while (ft_strchr(name, '/'))
			name++;
		ft_putstr("minishell: permission denied: ");
		ft_putendl(name);
	}
}

void			print_env(t_env *vlist)
{
	while (vlist)
	{
		if (vlist->vname)
		{
			ft_putstr(vlist->vname);
			ft_putchar('=');
			ft_putendl(vlist->vcntt);
		}
		vlist = vlist->next;
	}
}

int				error_cd(char *str, char *path, int nb)
{
	ft_putstr(str);
	ft_putendl(path);
	return (nb);
}
