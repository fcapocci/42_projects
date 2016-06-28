/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 22:17:43 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/28 13:14:02 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/_42sh.h"
#include "../libft/libft.h"
#include "../incs/key.h"

/*t_history_shell				*add_new_line_head(char **line, t_history_shell **lst)
{
	t_history_shell			*new;

	if (lst == NULL || line == NULL || *line == NULL)
		return (NULL);
	if ((new = ft_memalloc(sizeof(t_history_shell))) == NULL)
		return (*lst);
	new->line = *line;
	if (*lst == NULL)
		*lst = new;
	else
	{
		new->next = *lst;
		(*lst)->prev = new;
		(*lst) = new;
	}
	return (*lst);
}*/

t_history_shell				*add_new_line_tail(char **line, t_history_shell **lst)
{
	t_history_shell			*new;
	t_history_shell			*curs;

	if (lst == NULL || line == NULL || *line == NULL)
		return (NULL);
	if ((new = ft_memalloc(sizeof(t_history_shell))) == NULL)
		return (*lst);
	new->line = *line;
	if ((curs = *lst) == NULL)
		*lst = new;
	else
	{
		while (curs->next != NULL)
			curs = curs->next;
		curs->next = new;
		new->prev = curs;
	}
	return (new);
}

int							save_history(t_42sh *sh)
{
	char					*line;

	if ((sh->fd_history = ft_fopen(HISTORY_NAME, "r")) < 0)
		return (0);
	while (get_next_line(sh->fd_history, &line) > 0)
		if ((sh->last_add = add_new_line_tail(&line, &sh->history)) == NULL)
			return (-1);
	close(sh->fd_history);
	sh->curs_history = sh->last_add;
	return (1);
}

void						del_history(void)
{
	t_history_shell			*curs;
	t_history_shell			*tmp;
	t_42sh					*sh;

	if ((sh = get_struct_42sh(NULL)) == NULL)
		return ;
	curs = sh->history;
	if ((sh->fd_history = ft_fopen(HISTORY_NAME, "w+")) < 0)
		return ;
	while (curs != NULL)
	{
		tmp = curs->next;
		if (curs->line != NULL)
		{
			ft_putendl_fd(curs->line, sh->fd_history);
			ft_memdel((void**)&curs->line);
		}
		ft_memdel((void**)&curs);
		curs = tmp;
	}
	close(sh->fd_history);
}

void						print_history(void)
{
	char					*mem_line;
	t_history_shell			*curs;
	t_42sh					*sh;

	if ((sh = get_struct_42sh(NULL)) == NULL)
		return ;
	if ((curs = sh->last_add) == NULL)
		return ;
	if ((mem_line = get_add_line()) == NULL)
		return ;
	ft_putchar('\n');
	while (curs != NULL)
	{
		ft_putendl(curs->line);
		curs = curs->prev;
	}
	print_promt(sh);
	if (g_len_line > 0)
		ft_putstr(mem_line);
}

int							save_m_line(t_42sh *sh, t_multi_line **m_line)
{
	t_multi_line			*curs;

	if (sh == NULL || m_line == NULL || *m_line == NULL)
		return (-1);
	curs = *m_line;
	while (curs != NULL)
	{
		if (curs->line == NULL || curs->line[0] == '\0')
			break ;
		if ((sh->last_add = add_new_line_tail(&curs->line, &sh->history)) == NULL)
			return (-1);
		curs = curs->next;
	}
	sh->curs_history = sh->last_add;
	return (-1);
}
