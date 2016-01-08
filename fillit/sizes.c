/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:44:53 by fcapocci          #+#    #+#             */
/*   Updated: 2016/01/08 16:14:32 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		len_lst(t_tlist *start)
{
	t_tlist	*tmp;
	int		len;

	len = 0;
	tmp = start;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

int		virtual_size(int ntetri)
{
	int		i;

	i = 0;
	while (i * i < ntetri * 4)
		i++;
	return (i);
}
