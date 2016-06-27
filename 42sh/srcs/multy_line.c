/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multy_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 22:39:42 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/27 11:51:09 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/_42sh.h"
#include "../libft/libft.h"
#include "../incs/key.h"

#define C_LINE "\033[31m/\033[0m "


#include <stdio.h>

static char					*get_first_caractere(char *bracket, char *hook,
		char *apostrophe, char *guillemet)
{
	char					*ret;

	ret = NULL;
	if (bracket != NULL)
		ret = bracket;
	else if (hook != NULL)
		ret = hook;
	else if (apostrophe != NULL)
		ret = apostrophe;
	else if (guillemet != NULL)
		ret = guillemet;
	else
		return (NULL);
	ret = (ret > bracket) && (bracket != NULL) ? bracket : ret;
	ret = (ret > hook) && (hook != NULL) ? hook : ret;
	ret = (ret > apostrophe) && (apostrophe != NULL) ? apostrophe : ret;
	ret = (ret > guillemet) && (guillemet != NULL) ? guillemet : ret;
	return (ret);
}

static char					*get_start(char *line, char *end)
{
	char					*start;

	if ((start = get_first_caractere(ft_strchr(line, '('),
			ft_strchr(line, '['), ft_strchr(line, '\''),
			ft_strchr(line, '\"'))) == NULL)
		return (NULL);
	*end = *start == '[' ? ']' : *end;
	*end = *start == '(' ? ')' : *end;
	*end = *start == '\'' ? '\'' : *end;
	*end = *start == '\"' ? '\"' : *end;
	return (start);
}

static t_multi_line			*new_line(char **line, t_multi_line **lst)
{
	t_multi_line			*new_;
	t_multi_line			*curs;

	if (line == NULL || *line == NULL || lst == NULL)
		return (NULL);
	if ((new_ = ft_memalloc(sizeof(t_multi_line))) == NULL)
		return (NULL);
	new_->line = (*line);
	if ((curs = *lst) == NULL)
		(*lst) = new_;
	else
	{
		while (curs->next != NULL)
			curs = curs->next;
		curs->next = new_;
	}
	return (new_);
}

int							get_loop(int loop, char *start, char end,
		char *line)
{
	int						ret;
	unsigned int			i;
	static long long int	count = 0;

	if (start == NULL || line == NULL || line[0] == '\0')
		return (line == NULL ? -1 : 0);
	ret = 0;
	i = 0;
	while (line[i++] != '\0')
		if (line[i - 1] == *start)
		{
			if (*start == '\"' || *start == '\'')
				ret = count++ % 2 == 0 ? ret + 1 : ret - 1;
			else
				ret ++;
		}
		else if (line[i - 1] == end)
		{
			if (end == '\"' || end == '\'')
				ret = count++ % 2 == 1 ? ret - 1 : ret + 1;
			else
				ret--;
		}
	return (loop + ret);
}

t_multi_line				*get_multi_line(void)
{
	char					*line;
	char					*start;
	char					end;
	int						loop;
	t_multi_line			*m_line;

	signal(SIGWINCH, print_sign);
	if ((line = get_line()) == NULL)
		return (NULL);
	start = get_start(line, &end);
	m_line = NULL;
	loop = 0;
	while (new_line(&line, &m_line) != NULL &&
		(loop = get_loop(loop, start, end, line)) > 0)
	{
		signal(SIGWINCH, print_sign);
		ft_putstr(C_LINE);
		if ((line = get_line()) == NULL)
			return (m_line);
	}
	return (m_line);
}

void						del_multi_line(t_multi_line **m_line)
{
	t_multi_line			*tmp;

	if (m_line != NULL)
	{
		while ((*m_line) != NULL)
		{
			tmp = (*m_line)->next;
			ft_memdel((void**)&(*m_line)->line);
			ft_memdel((void**)m_line);
			(*m_line) = tmp;
		}
		ft_memdel((void**)m_line);
	}
}
