/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:24:06 by vcastro-          #+#    #+#             */
/*   Updated: 2015/12/02 18:39:05 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*before;
	t_list	*elem;
	t_list	*start;

	start = (void*)0;
	if (lst && (*f))
	{
		start = f(lst);
		before = start;
		lst = lst->next;
		while (lst)
		{
			elem = f(lst);
			before->next = elem;
			before = elem;
			lst = lst->next;
		}
	}
	return (start);
}
