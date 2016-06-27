/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:29:45 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/27 14:40:28 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/key.h"
#include "../libft/libft.h"
#include <unistd.h>

#define MAX_LEN_LINE 10000

#include <stdio.h>

char						*get_add_line(void)
{
	static char				mem_line[MAX_LEN_LINE + 2];
	unsigned int			i;

	i = 0;
	while (ft_isspace(mem_line[i]) == 1)
		i++;
	return(&mem_line[i]);
}

int							check_key(int func(char key[BUFF_SIZE_READ + 1]))
{
	char					buff[BUFF_SIZE_READ + 1];

	ft_bzero(buff, sizeof(buff));
	if (read(STDIN_FILENO, buff, BUFF_SIZE_READ) <= 0)
		return (-1);
	return (func(buff));
}

int							add_key(char c)
{
	char					*mem_line;
	int						decalage;

	if ((mem_line = get_add_line()) == NULL)
		return (-1);
	decalage = g_len_line - g_i_curs;
	while (decalage >= 0)
	{
		mem_line[g_i_curs + decalage + 1] = mem_line[g_i_curs + decalage];
		decalage--;
	}
	mem_line[g_i_curs] = c;
	mem_line[g_i_curs + 1] = (g_i_curs >= g_len_line) ? '\0': mem_line[g_i_curs + 1];
	ft_putstr(&mem_line[g_i_curs++]);
	g_len_line++;
	while (g_i_curs + ++decalage < g_len_line)
		if (cmd_termcap("le") == -1)
			return (-1);
	return (1);
}

char						*save_line(char c)
{
	static char				c_prev;
	char					*mem_line;

	if ((mem_line = get_add_line()) == NULL)
		return (NULL);
	if (c != '\0' && c != '\n' && g_i_curs < MAX_LEN_LINE)
		add_key(c);
	else if (c == '\n')
	{
/*		ft_putchar('\n');
		ft_putstr("g_len_line = ");
		ft_putnbr(g_len_line);
		ft_putstr(" g_i_curs = ");
		ft_putnbr(g_i_curs);*/
		g_len_line = 0;
		g_i_curs = 0;
	}
	if (c_prev == '\n')
		mem_line[g_i_curs] = '\0';
	c_prev = c;
	return (mem_line);
}

int							event_key(char b[BUFF_SIZE_READ + 1])
{
	if (TAB)
		ft_putstr("TAB\n");
	else if (DEL)
		del_left();
	else if (ARROW_LEFT)
		move_one_c_left();
	else if (ARROW_RIGHT)
		move_one_c_right();
	else if (ARROW_DOWN)
		ft_putstr("ARROW_DOWN\n");
	else if (ARROW_UP)
		ft_putstr("ARROW_UP\n");
	else if (F1)
		ft_putstr("F1\n");
	else if (F2)
		ft_putstr("F2\n");
	else if (F3)
		ft_putstr("F3\n");
	else if (F4)
		ft_putstr("F4\n");
	else if (F5)
		ft_putstr("F5\n");
	else if (F6)
		ft_putstr("F6\n");
	else if (F7)
		ft_putstr("F7\n");
	else if (F8)
		ft_putstr("F8\n");
	else if (F9)
		ft_putstr("F9\n");
	else if (F10)
		ft_putstr("F10\n");
	else if (HK)
		ft_putstr("K\n");
	else if (ENTER)
	{
		save_line(b[0]);
		return (0);
	}
	else
		save_line(b[0]);
	return(1);
}

char						*get_line(void)
{
	char					*line;
	int						ret;

	line = NULL;
	while (1)
	{
		if ((ret = check_key(event_key)) == -1)
			return (NULL);
		else if (ret == 0)
			return (ft_strdup(get_add_line()));
	}
	return (NULL);
}
