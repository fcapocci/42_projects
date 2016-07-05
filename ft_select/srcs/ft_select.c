/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 10:08:17 by fcapocci          #+#    #+#             */
/*   Updated: 2016/07/05 20:57:54 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_select.h"

static int		init_term_env(struct termios *term)
{
	char			*name_term;

	if ((name_term = getenv("TERM")) == NULL)
	{
		ft_putendl("missing TERM env");
		return (ERR);
	}
	if (tgetent(NULL, name_term) == -1)
		return (ERR);
	if (tcgetattr(0, term) == -1)
		return (ERR);
	return (OK);
}

int				ft_select(int argc, char **argv)
{
	t_lst			*lst;
	struct termios	term;

	if ((lst = init_lst(argc, argv)) == NULL)
		return (ERR);
	if (init_term_env(&term) == ERR)
	{
		free_lst(lst);
		return (ERR);
	}
	free_lst(lst);
	return (OK);
}
