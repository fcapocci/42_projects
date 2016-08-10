/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 18:26:27 by fcapocci          #+#    #+#             */
/*   Updated: 2016/08/10 19:35:02 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_select.h"

void		error(char *s)
{
	exe_cmd("cl");
	ft_putstr(s);
}

int			ft_ouct(int c)
{
	write(0, &c, 1);
	return (OK);
}

int			exe_cmd(char *s)
{
	char			*res;

	if ((res = tgetstr(s, NULL)) == NULL)
		return (ERR);
	if (tputs(res, 0, ft_ouct))
		return (ERR);
	return (OK);
}

int			move_curs(int x, int y)
{
	char			*str_cm;
	char			*char_goto;

	if ((str_cm = tgetstr("cm", NULL)) == NULL)
		return (ERR);
	if ((char_goto = tgoto(str_cm, x, y)) == NULL)
		return (ERR);
	if (tputs(char_goto, 0, ft_ouct))
		return (ERR);
	return(OK);
}
