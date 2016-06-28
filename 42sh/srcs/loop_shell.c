/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 12:22:43 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/28 12:48:36 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/_42sh.h"
#include "../libft/libft.h"
#include "../incs/key.h"





#include <stdio.h>

#define SIZE_PROMT 2000
#define COLOR_PROMT "\033[032;1m"
#define COLOR_LINE "\033[034;1;4m"
#define COLOR_LAST "\033[036;1m"
#define RESET_COLOR "\033[0m"

void						print_header(t_42sh *sh)
{
	ft_putstr("HOME = ");
	ft_putstr(sh->home == NULL ? "" : sh->home);
	ft_putstr("\nnb_row = ");
	ft_putnbr(sh->info_w.ws_row);
	ft_putstr("\nnb_col = ");
	ft_putnbr(sh->info_w.ws_col);
	ft_putstr("\nPATH = ");
	ft_putstr(sh->path_line);
	ft_putstr("\nSHLVL = ");
	ft_putstr(getenv("SHLVL"));
	ft_putstr("\nnb var env ");
	ft_putnbr(sh->lst_env == NULL ? 0 : sh->lst_env->i);
	ft_putstr("\n\n");
}

int							print_promt(t_42sh *sh)
{
	char					promt[SIZE_PROMT + 5];
	unsigned int			i;

	getcwd(promt, SIZE_PROMT);
	if (&promt[0] == NULL)
		return (0);
	if (sh->home == NULL)
		i = 0;
	else
		i = ft_strncmp(promt, sh->home, sh->len_home) == 0 ? sh->len_home : 0;
	if (i > 0)
		promt[--i] = '~';
	ft_strcat(promt, " ?> ");
	ft_putstr(COLOR_PROMT);
	ft_putstr(&promt[i]);
	ft_putstr(RESET_COLOR);
	return (1);
}

/*void						prin_new_env(t_42sh *sh)
{
	char					**env;
	unsigned int			i;

	if ((env = new_var_env(sh)) != NULL)
	{
		for (i = 0; env[i] != NULL; i++)
			printf("env[%2d] = %s\n", i, env[i]);
		ft_free_strsplit(env);
	}
}*/

static int					print_line_shell(t_multi_line *m_line)
{
	unsigned int			i;
	t_multi_line			*curs;

	curs = m_line;
	i = 0;
	ft_putchar('\n');
	while (ft_isspace(curs->line[i]) == 1)
		i++;
	if (curs->line[i] != '\0')
	{
		ft_putstr(COLOR_LINE);
		while (curs != NULL)
		{
			ft_putendl(curs->line);
			curs = curs->next;
		}
		ft_putstr(RESET_COLOR);
	}
	else
		ft_putstr("vide\n");
	return (1);
}

void						loop_shell(t_42sh *sh)
{
	t_multi_line			*m_line;

	print_header(sh);
	while (print_promt(sh))
	{
		if ((m_line = get_multi_line()) == NULL)
			break ;
		print_line_shell(m_line);
		save_m_line(sh, &m_line);
		if (m_line->line[0] != '\0')
			if (check_builtin(&sh, &m_line) != BUILT)
				check_bin(sh, &m_line);
		del_multi_line(&m_line);
	}
}
