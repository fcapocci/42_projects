/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:47:22 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/16 12:54:07 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_count_list(t_list *lst)
{
	size_t		len;

	len = 0;
	if (!lst)
		return (len);
	while (lst)
	{
	len ++;
	lst = lst->next;
	}
	return (len);
}
