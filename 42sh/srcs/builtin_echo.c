/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 22:03:51 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/27 11:52:36 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/_42sh.h"
#include "../libft/libft.h"

static void					print_one_line(char *line)
{
	unsigned int			i;

	i = 0;
	while (line[i] == ' ')
		i++;
	ft_putendl(&line[i]);
}

int							builtin_echo(t_42sh **sh, t_multi_line **m_line)
{
	unsigned int			i;
	t_multi_line			*curs;

	if (sh == NULL || *sh == NULL || m_line == NULL || *m_line == NULL ||
			(*m_line)->line == NULL)
		return (ERROR);
	if (ft_strncmp((*m_line)->line, "echo", 4) == 0)
	{
		curs = (*m_line);
		i = 0;
		while ((*m_line)->line[4 + i] == ' ')
			i++;
		ft_putendl(&(*m_line)->line[4 + i]);
		curs = curs->next;
		while (curs != NULL)
		{
			ft_putendl(curs->line);
			curs = curs->next;
		}
		return (1);
	}
	return (0);
}
