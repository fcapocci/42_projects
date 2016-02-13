/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 22:16:11 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/13 19:41:33 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_path(char *dirname, int save, t_dir *flist)
{
	static int		loop;

	if (save > 1 && (loop > 0 || flist))
	{
		ft_putchar('\n');
		ft_putstr(dirname);
		ft_putstr(":\n");
	}
	else if (save > 1 && (loop == 0 || flist))
	{
		ft_putstr(dirname);
		ft_putstr(":\n");
	}
	loop++;
}
