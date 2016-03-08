/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 18:07:32 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/08 23:08:43 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <unistd.h>
# include <sys/wait.h>

typedef struct				s_env
{
	char					*vname;
	char					*vcntt;
	struct s_env			*next;
}							t_env;

/* ** list.c ** */

t_env						*creat_list(char **env);
t_env						*new_link(char *env);

/* ** cmd.c ** */

int							check_path(char ***args, char **path);
char						*sup_tab(char *line);
int							get_cmd(char *line, t_env *env_list, char **env);

/* ** free.c ** */

void						free_vlist(t_env *vlist);

/* ** execute.c ** */

int							execute_cmd(char **args, char **env);
void						quit(t_env **list, char **line);

#endif
