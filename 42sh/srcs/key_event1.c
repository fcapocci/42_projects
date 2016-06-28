/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 21:15:17 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/28 11:39:48 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/key.h"
#include "../libft/libft.h"
#include <curses.h>
#include <term.h>


int							my_out_put(int c)
{
	ft_putchar(c);
	return (1);
}

int							cmd_termcap(char *str)
{
	char					*cmd;

	if ((cmd = tgetstr(str, NULL)) == NULL)
		return (-1);
	tputs(cmd, 0, my_out_put);
	return (1);
}

int							move_one_c_left(void)
{
	if (g_i_curs == 0)
		return (0);
	g_i_curs--;
	if (cmd_termcap("le") == -1)
		return (-1);
	return (1);
}

int							move_one_c_right(void)
{
	if (g_i_curs == g_len_line)
		return (0);
	g_i_curs++;
	if (cmd_termcap("nd") == -1)
		return (-1);
	return (1);
}

/*int							del_left(void)
{
	char					*cmd;
	int						ret;
	char					*line;

	if ((ret = move_one_c_left()) == -1)
		return (-1);
	if (ret == 1)
	{
		g_len_line--;
		if ((line = save_line(0)) == NULL)
			return (-1);
		line[g_len_line] = '\0';
		if ((cmd = tgetstr("dc", NULL)) == NULL)
			return (-1);
		tputs(cmd, 0, my_out_put);
	}
	return (1);
}*/

int							del_left(void)//del
{
	char					*line;
	int						ret;
	int						decalage;

	if ((ret = move_one_c_left()) == -1)
		return (-1);
	if (ret == 1)
	{
		if ((line = get_add_line()) == NULL)
			return (-1);
/*		ft_putchar('\n');
		ft_putstr("g_len_line = ");
		ft_putnbr(g_len_line);
		ft_putstr(" g_i_curs = ");
		ft_putnbr(g_i_curs);
		ft_putchar('\n');*/
		decalage = 0;
		while (g_i_curs + decalage < g_len_line)
		{
			line[g_i_curs + decalage] = line[g_i_curs + decalage + 1];
			decalage++;
		}
		line[--g_len_line] = '\0';
		cmd_termcap("dc");
	}
	return (1);
}

int							del_right(void)//sup
{
	char					*mem_line;
	int						decalage;

	if ((mem_line = get_add_line()) == NULL)
		return (-1);
	decalage = 0;
	if (cmd_termcap("dc") == -1)
		return (-1);
	while (g_i_curs + decalage <= g_len_line)
	{
		mem_line[g_i_curs + decalage] = mem_line[g_i_curs + decalage + 1];
		decalage++;
	}
	g_i_curs = g_i_curs == g_len_line ? g_i_curs - 1 : g_i_curs;
	g_len_line--;
	return (1);
}
