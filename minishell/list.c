/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 19:25:19 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/07 04:12:07 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env			*new_link(char *env)
{
	t_env		*link;
	int			len;

	len = ft_strlen(env) - ft_strlen(ft_strchr(env, '='));
	if ((link = (t_env*)ft_memalloc(sizeof(t_env))) == NULL)
		return (NULL);
	link->vname = ft_strsub(env, 0, len);
	link->vcntt = ft_strsub(env, len + 1, ft_strlen(env) - len);
	return (link);
}

t_env			*creat_list(char **env)
{
	t_env		*list[2];

	list[0] = NULL;
	list[1] = NULL;
	while (*env)
	{
		if (!list[0])
		{
			list[0] = new_link(*env);
			if (!list[1])
				list[1] = list[0];
		}
		else
		{
			list[0]->next = new_link(*env);
			list[0] = list[0]->next;
		}
		env++;
	}
	return (list[1]);
}
