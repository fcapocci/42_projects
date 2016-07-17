/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_selected.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 00:35:10 by fcapocci          #+#    #+#             */
/*   Updated: 2016/07/18 00:45:30 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_select.h"

void			print_selected(t_lst *lst)
{
	t_lst		*tmp;
	t_lst		*start;

	tmp = lst;
	start = NULL;
	while (tmp != start)
	{
		if (tmp->selected == 1)
			ft_putendl(tmp->name);
		start = (!start) ? tmp : start;
		tmp = tmp->next;
	}
}
