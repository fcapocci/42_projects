/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 10:25:56 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/21 12:16:18 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env			*creat_link_env(char **args, int rp)
{
	t_env		*nlist;

	nlist = NULL;
	if ((nlist = (t_env*)ft_memalloc(sizeof(t_env))) == NULL)
		return (NULL);
	if (len_y(args) > 2)
	{
		nlist->vname = ft_strdup(args[1]);
		nlist->vcntt = (rp == 0 ? ft_strdup("\0") : ft_strdup(args[2]));
	}
	else
	{
		nlist->vname = ft_strdup(args[0]);
		nlist->vcntt = (rp == 0 ? ft_strdup("\0") : ft_strdup(args[1]));
	}
	nlist->next = NULL;
	return (nlist);
}

t_env			*insert_cntt(t_env *vlist, char *cntt, int rp)
{
	if (rp > 0)
	{
		ft_memdel((void**)&vlist->vcntt);
		vlist->vcntt = ft_strdup(cntt);
	}
	return (vlist);
}

t_env			*set_env(t_env *vlist, char **ag, int rp)
{
	t_env		*nvlist;
	char		**tmp;
	size_t		len;

	len = len_y(ag);
	nvlist = vlist;
	if (len < 2 || (len > 3) || (ft_strchr(ag[1], '=') && len > 2)
	|| (!ft_strchr(ag[1], '=') && len == 2) || (ag[1][0] == '='))
		return (nvlist);
	tmp = (ft_strchr(ag[1], '=') ? ft_strsplit_guil(ag[1], '=') : NULL);
	while (vlist->vname && (ft_strcmp((tmp ? tmp[0] : ag[1]), vlist->vname)
	&& vlist->next))
		vlist = vlist->next;
	rp = (tmp ? ft_strlen(tmp[1]) : ft_strlen(ag[2]));
	if (vlist->vname && !ft_strcmp((tmp ? tmp[0] : ag[1]), vlist->vname))
		vlist = insert_cntt(vlist, (tmp ? tmp[1] : ag[2]), rp);
	else
		vlist->next = creat_link_env((tmp ? tmp : ag), rp);
	ft_free_strsplit(&tmp);
	if (vlist->vname == NULL && vlist->vcntt == NULL)
	{
		nvlist = vlist->next;
		ft_memdel((void**)&vlist);
	}
	return (nvlist);
}
