/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 03:11:16 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/13 02:16:59 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			no_cmd(char *name)
{
	ft_putstr("minishell: command not found: ");
	ft_putendl(name);
}

int				print_env(t_env *vlist, int nb)
{
	while (vlist)
	{
		ft_putstr(vlist->vname);
		ft_putchar('=');
		ft_putendl(vlist->vcntt);
		vlist = vlist->next;
	}
	return (nb);
}
