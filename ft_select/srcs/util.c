/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 18:26:27 by fcapocci          #+#    #+#             */
/*   Updated: 2016/07/09 18:37:03 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_select.h"

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
