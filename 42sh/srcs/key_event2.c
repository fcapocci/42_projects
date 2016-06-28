/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 09:35:08 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/28 17:10:13 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/key.h"
#include "../libft/libft.h"
#include "../incs/_42sh.h"

static t_history_shell	*prev;

int							arrow_up(void)
{
	unsigned int			i;
	t_42sh					*sh;

	if ((sh = get_struct_42sh(NULL)) == NULL)
		return (-1);
	while (g_i_curs > 0)
		del_left();
	if (sh->curs_history == NULL)
		sh->curs_history = prev;
	if (sh->curs_history == NULL)
		return (0);
	i = 0;
	while (sh->curs_history->line[i] != '\0')
		save_line(sh->curs_history->line[i++]);
	prev = sh->curs_history;
	sh->curs_history = sh->curs_history->prev;
	return (1);
}

int							arrow_down(void)
{
	unsigned int			i;
	t_42sh					*sh;

	if ((sh = get_struct_42sh(NULL)) == NULL)
		return (-1);
	while (g_i_curs > 0)
		del_left();
	if (prev == sh->last_add)
		return (0);
	if (sh->curs_history == NULL)
		sh->curs_history = prev;
	while (g_i_curs > 0)
		del_left();
	i = 0;
	while (sh->curs_history->line[i] != '\0')
		save_line(sh->curs_history->line[i++]);
	prev = sh->curs_history;
	sh->curs_history = sh->curs_history->next;
	return (1);
}

/*int							arrow_up(void)
{
	unsigned int			i;
	t_42sh					*sh;

	if ((sh = get_struct_42sh(NULL)) == NULL)
		return (-1);
	if (sh->curs_history == NULL)
		sh->curs_history = first_adr == NULL ? last_adr : first_adr;
	if (sh->curs_history == NULL)
		return (0);
	if (sh->curs_history->prev == NULL)
		first_adr = sh->curs_history;
	while (g_i_curs > 0)
		del_left();
	i = 0;
	while (sh->curs_history->line[i] != '\0')
		save_line(sh->curs_history->line[i++]);
	sh->curs_history = sh->curs_history->prev;
	return (1);
}*/


/*int							arrow_down(void)
{
	unsigned int			i;
	t_42sh					*sh;

	if ((sh = get_struct_42sh(NULL)) == NULL)
		return (-1);
	while (g_i_curs > 0)
		del_left();
	if (sh->curs_history == NULL)
		return (0);
	if (sh->curs_history->next == NULL)
		last_adr = sh->curs_history;
	i = 0;
	while (sh->curs_history->line[i] != '\0')
		save_line(sh->curs_history->line[i++]);
	sh->curs_history = sh->curs_history->next;
	return (1);
}*/
