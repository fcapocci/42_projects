/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argv2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 07:53:44 by fcapocci          #+#    #+#             */
/*   Updated: 2016/08/16 10:12:16 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_select.h"

void			nb_select(int place, t_lst *lst, t_lst *start)
{
	int			nb;

	nb = 0;
	while (lst != start)
	{
		start = (start == NULL) ? lst : start;
		if (lst->selected == 1)
			nb++;
		lst = lst->next;
	}
	move_curs(0, place - 1);
	ft_putnbr(nb);
	ft_putstr(" obj selected");
}
