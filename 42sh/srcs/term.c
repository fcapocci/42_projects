/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 12:49:45 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/24 16:10:46 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/_42sh.h"
#include "../libft/libft.h"

#include <curses.h>
#include <term.h>
#include <unistd.h>

#include <stdio.h>

t_42sh						*get_struct_42sh(t_42sh **sh)
{
	static t_42sh			*adr = NULL;

	if (sh != NULL && *sh != NULL)
		adr = (*sh);
	return (adr);
}

int							save_win_size(void)
{
	t_42sh					*sh;

	if ((sh = get_struct_42sh(NULL)) == NULL)
		return (ERROR);
	if (ioctl(0, TIOCGWINSZ, &sh->info_w) < 0)
		return (ERROR);
	return (1);
}

int							init_term(t_42sh **sh)
{
	if (sh == NULL || *sh == NULL)
		return (ERROR);
	if (((*sh)->term_name = ft_strdup(getenv("TERM"))) == NULL)
		return (ERROR);
	if (tgetent(NULL, (*sh)->term_name) <= 0 || tcgetattr(0, &(*sh)->reset) < 0
			|| tcgetattr(0, &(*sh)->setting) < 0)
		return (ERROR);
	(*sh)->setting.c_lflag &= ~(ICANON);
	(*sh)->setting.c_lflag &= ~(ECHO);
	(*sh)->setting.c_lflag &= ~(ISIG);
	(*sh)->setting.c_cc[VMIN] = 1;
	(*sh)->setting.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &(*sh)->setting) == -1)
		return (ERROR);
	return (save_win_size());
}
