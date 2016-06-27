/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 14:29:37 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/22 11:15:50 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/_42sh.h"
#include "../libft/libft.h"

t_env						*new_env(char *name, char *content, unsigned int i)
{
	t_env					*new_;

	if (name == NULL)
		return (NULL);
	if ((new_ = ft_memalloc(sizeof(t_env))) == NULL)
		return (NULL);
	if ((new_->name = ft_strdup(name)) == NULL)
		return (NULL);
	if ((new_->content = ft_strdup(content != NULL && content[0] != '\0' ?
			content : "")) == NULL)
		return (NULL);
	new_->i = i;
	return (new_);
}

t_env						*save_env(char **env)
{
	char					*start_content;
	char					*end_name;
	unsigned int			i;
	t_env					*ret;
	t_env					*new_;

	i = 0;
	ret = NULL;
	while (env[i++] != NULL)
	{
		if ((end_name = ft_strchr(env[i - 1], '=')) == NULL)
			return (NULL);
		start_content = end_name + 1;
		*end_name = '\0';
		if ((new_ = new_env(env[i - 1], start_content, i)) == NULL)
			return (NULL);
		if (ret != NULL)
			new_->next = ret;
		ret = new_;
		*end_name = '=';
	}
	return (ret);
}

void						print_env(t_42sh *sh)
{
	t_env					*curs;

	if (sh == NULL)
		return ;
	curs = sh->lst_env;
	while (curs != NULL)
	{
		ft_putnbr(curs->i);
		ft_putchar(' ');
		ft_putstr(curs->name);
		ft_putchar('=');
		ft_putendl(curs->content);
		curs = curs->next;
	}
}

t_env						*del_env(t_env **lst)
{
	t_env					*tmp;

	if (lst == NULL)
		return (NULL);
	while ((*lst) != NULL)
	{
		tmp = (*lst)->next;
		ft_memdel((void**)&(*lst)->name);
		ft_memdel((void**)&(*lst)->content);
		ft_memdel((void**)lst);
		(*lst) = tmp;
	}
	ft_memdel((void**)lst);
	return (NULL);
}
