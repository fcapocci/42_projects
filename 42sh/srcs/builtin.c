/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 12:35:22 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/24 16:41:29 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/_42sh.h"
#include "../libft/libft.h"

static void					builtin_exit(t_42sh **sh, t_multi_line **line)
{
	int						nb_exit;
	int						i;

	nb_exit = 0;
	if (ft_strncmp((*line)->line, "exit", 4) == 0)
	{
		if ((*line)->line[4] != '\0')
		{
			if (ft_isspace((*line)->line[4]) == 0)
				return ;
			i = 0;
			while ((*line)->line[4 + i] == ' ')
				i++;
			if (ft_is_number(&(*line)->line[4 + i]) == 1)
				nb_exit = ft_atoi(&(*line)->line[4 + i]);
		}
		del_multi_line(line);
		del_sh(sh);
		exit(nb_exit);
	}
}

static int					builtin_env(t_42sh **sh, t_multi_line **m_line)
{
	if (ft_strncmp((*m_line)->line, "env", 3) == 0)
		if ((*m_line)->line[3] == '\0')
		{
			print_env(*sh);
			return (1);
		}
	return (0);
}

static int					builtin_unsetenv(t_42sh **sh, t_multi_line **m_line)
{
	unsigned int			i;

	if (ft_strncmp((*m_line)->line, "unsetenv", 8) == 0)
	{
		i = 0;
		while ((*m_line)->line[8 + i] == ' ')
			i++;
		if (ft_strcmp(&(*m_line)->line[8 + i], "HOME") == 0)
		{
			(*sh)->home = NULL;
			(*sh)->len_home = 0;
		}
		return (del_one_env(&(*sh)->lst_env, &(*m_line)->line[8 + i]));
	}
	return (0);
}

int							check_builtin(t_42sh **sh, t_multi_line **line)
{
	if (sh == NULL || *sh == NULL || line == NULL || *line == NULL ||
			(*line)->line == NULL)
		return (-1);
	builtin_exit(sh, line);
	if (builtin_echo(sh, line) == 1 || builtin_env(sh, line) == 1 ||
			builtin_unsetenv(sh, line) == 1 || builtin_setenv(sh, line) == 1)
		return (BUILT);
	return (EXE);
}
