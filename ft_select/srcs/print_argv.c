/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 08:45:49 by fcapocci          #+#    #+#             */
/*   Updated: 2016/07/16 04:01:23 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_select.h"

#define CURS "\033[4m"
#define SELECT "\033[7m"
#define C_SELC "\033[7;4m"
#define RES "\033[0m"

static void		put_word(char *s)
{
	ft_putendl(s);
	ft_putstr(RES);
}

void			print_argv(t_lst *lst, t_lst *curs)
{
	t_lst		*start;

	exe_cmd("cl");
	start = NULL;
	while (lst != start)
	{
		start = (start == NULL) ? lst : start;
		if (lst == curs)
			ft_putstr(lst->selected == 1 ? C_SELC : CURS);
		else
			ft_putstr(lst->selected == 1 ? SELECT : RES);
		put_word(lst->name);
		lst = lst->next;
	}
}
