/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 18:36:27 by fcapocci          #+#    #+#             */
/*   Updated: 2015/12/05 16:39:10 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newelem;
	t_list	*firstelem;

	firstelem = f(lst);
	lst = lst->next;
	newelem = f(lst);
	firstelem->next = newelem;
	while (lst->next != NULL)
	{
		lst = lst->next;
		newelem->next = f(lst);
		newelem = newelem->next;
	}
	return (firstelem);
}
