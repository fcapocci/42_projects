/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:31:09 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/27 11:44:21 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/_42sh.h"
#include "../libft/libft.h"


#include <stdio.h>

static int					exe_bin(char **argv, char **env)
{
	int						pid;
	int						status;

	if ((pid = fork()) > 0)
	{
		waitpid(pid, &status, WUNTRACED);
		print_status();
	}
	else
	{
		if (execve(argv[0], argv, env) == -1)
			return (ERROR);
		ft_free_strsplit(argv);
		ft_free_strsplit(env);
	}
	return (EXE);
}

static char					*get_start_end(char **line, char **end,
		unsigned int *len_line)
{
	char					*cpy_line;
	char					*start;
	unsigned int			i;

	if (line == NULL || *line == NULL || end == NULL || len_line == NULL)
		return (NULL);
	i = 0;
	cpy_line = *line;
	*len_line = ft_strlen(*line);
	start = *line;
	while (cpy_line[i] != '\0')
	{
		if (ft_isspace(cpy_line[i]) == 1)
			break ;
		if (cpy_line[i++] == '\\')
			start = cpy_line[i] != '\0' ? &cpy_line[i] : start;
	}
	*end = &cpy_line[i];
	return (start);
}

static t_bin				*get_bin(t_42sh *sh, char *line)
{
	char					*start;
	char					*end;
	unsigned int			key_hash;
	unsigned int			len_line;
	t_bin					*curs;

	if ((start = get_start_end(&line, &end, &len_line)) == NULL)
		return (NULL);
	if (start == end)
		return (NULL);
	*end = '\0';
	key_hash = i_table_hash(start, SIZE_HASH);
	curs = sh->hash_bin[key_hash];
	while (curs != NULL)
	{
		if (ft_strcmp(curs->name, start) == 0)
			break ;
		curs = curs->h_next;
	}
	*end = end - start < len_line ? ' ' : *end;
	return (curs);
}

static int					not_found(char *name)
{
	unsigned int			i;

	i = 0;
	while (ft_isspace(name[i]) == 1)
		i++;
	if (name[i] == '\0')
		return (0);
	ft_putstr(NAME);
	ft_putstr(": command not found: ");
	ft_putendl(name);
	return (0);
}

int							check_bin(t_42sh *sh, t_multi_line **m_line)
{
	char					**argv;
	char					**env;
	int						ret;
	t_bin					*bin;

	if ((bin = get_bin(sh, (*m_line)->line)) != NULL)
	{

		if ((env = new_var_env(sh)) == NULL)
			return (ERROR);
		if ((argv = save_argv(bin, (*m_line)->line)) == NULL)
			return (ERROR);
		ret = exe_bin(argv, env);
		ft_free_strsplit(argv);
		ft_free_strsplit(env);
		return (ret);
	}
	return(not_found((*m_line)->line));
}
