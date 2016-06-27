/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:29:45 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/26 22:22:15 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/key.h"
#include "../libft/libft.h"
#include <unistd.h>

#define MAX_LEN_LINE 10000

#include <stdio.h>

static char					*get_add_line(void)
{
	static char				mem_line[MAX_LEN_LINE + 1];

	return(mem_line);
}

char						*inser_c(char c)
{
	char					*mem_line;
	unsigned int			i;
	unsigned int			decalage;

	if ((mem_line = get_add_line()) == NULL)
		return (NULL);
	decalage = g_len_line - g_i_curs;
	while (decalage + 1 > 1)
	{
		mem_line[g_i_curs + decalage + 1] = mem_line[g_i_curs + decalage];
		decalage--;
	}
	mem_line[g_i_curs++] = c;
	g_len_line++;
	return (mem_line);
}


static int					add_key(char c)
{
	int						decalage;
	char					*mem_line;

	if ((mem_line = get_add_line()) == NULL)
		return (-1);
	decalage = 0;
//		ft_putnbr(decalage);
//		ft_putstr("< ");
	if (inser_c(c) == NULL)
		return (-1);
	if (g_i_curs > g_len_line++)
		mem_line[g_i_curs] = '\0';
	else
	{
		while (g_i_curs + ++decalage < g_len_line - 1)
			ft_putchar(mem_line[g_i_curs + decalage]);
		while (decalage-- > 1)
			move_one_c_left();
	}
//	ft_putendl(mem_line);
	return (0);
}

/*static int					add_key(char c)
{
	int						decalage;
	char					*mem_line;

	if ((mem_line = get_add_line()) == NULL)
		return (-1);
	decalage = g_len_line - g_i_curs;
//		ft_putnbr(decalage);
//		ft_putstr("< ");
	while (decalage >= 0)
	{
		mem_line[g_i_curs + decalage + 1] = mem_line[g_i_curs + decalage];
		decalage--;
	}
	mem_line[g_i_curs++] = c;
	if (g_i_curs > g_len_line++)
		mem_line[g_i_curs] = '\0';
	else
	{
		while (g_i_curs + ++decalage < g_len_line)
			ft_putchar(mem_line[g_i_curs + decalage]);
		while (decalage-- > 0)
			move_one_c_left();
	}
	return (0);
}*/


int							check_key(int func(char key[BUFF_SIZE_READ + 1]))
{
	char					buff[BUFF_SIZE_READ + 1];

	ft_bzero(buff, sizeof(buff));
	if (read(STDIN_FILENO, buff, BUFF_SIZE_READ) <= 0)
		return (-1);
	return (func(buff));
}

char						*save_line(char c)
{
	static char				c_prev;
	char					*mem_line;
	int						decalage;

	if ((mem_line = get_add_line()) == NULL)
		return (NULL);
	if (c != '\n'  && c != 0 && g_i_curs < MAX_LEN_LINE - 1)
		add_key(c);
	else if (c == '\n')
	{
//		ft_putstr("len = ");
//		ft_putnbr(g_len_line);
//		ft_putstr(", i_line = ");
//		ft_putnbr(g_i_curs);
//		ft_putchar('\n');
		g_i_curs = 0;
		g_len_line = 0;
	}
	if (c_prev == '\0')
		mem_line[g_i_curs] = '\0';
	c_prev = c;
	ft_putendl(mem_line);
	return (mem_line);
}
/*char						*save_line(char c)
{
	static char				mem_line[MAX_LEN_LINE + 1];
	static char				c_prev;

	if (c != '\n'  && c != 0 && g_i_curs < MAX_LEN_LINE)
	{
		mem_line[g_i_curs++] = c;
		if (g_i_curs > g_len_line)
		{
			g_len_line++;
			mem_line[g_i_curs] = '\0';
		}
	}
	else if (c == '\n')
	{
		g_i_curs = 0;
		g_len_line = 0;
	}
	if (c_prev == 0)
		mem_line[g_i_curs] = '\0';
	c_prev = c;
	return (mem_line);
}*/


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
			return (save_line(0));
	}
	return (NULL);
}
