/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 08:45:49 by fcapocci          #+#    #+#             */
/*   Updated: 2016/07/07 15:22:03 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_select.h"

void		print_argv(t_lst *lst)
{
	size_t		save_last;

	save_last = lst->num;
	ft_putendl(lst->name);
	lst = lst->next;
	while (lst->num != save_last)
	{
		ft_putendl(lst->name);
		lst = lst->next;
	}
}
