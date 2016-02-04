/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:10:58 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/04 18:27:45 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	padd_nblink(t_dir *start, t_dir *list)
{
	size_t		max;

	max = 0;
	while (start)
	{
		if (ft_strlen(ft_itoa(start->nblink)) > max)
			max = ft_strlen(ft_itoa(start->nblink));
		start = start->next;
	}
	max += 2;
	while ((max - ft_strlen(ft_itoa(list->nblink))) > 0)
	{
		ft_putchar(' ');
		max--;
	}
}

void	padd_owner(t_dir *start, t_dir *list)
{
	size_t		max;

	max = 0;
	while (start)
	{
		if (ft_strlen(start->owner) > max)
			max = ft_strlen(start->owner);
		start = start->next;
	}
	max += 2;
	while ((max - ft_strlen(list->owner)) > 0)
	{
		ft_putchar(' ');
		max--;
	}
}

void	padd_grp(t_dir *start, t_dir *list)
{
	size_t		max;

	max = 0;
	while (start)
	{
		if (ft_strlen(start->grp) > max)
			max = ft_strlen(start->grp);
		start = start->next;
	}
	while ((max - ft_strlen(list->grp)) > 0)
	{
		ft_putchar(' ');
		max--;
	}
}

void	padd_tall(t_dir *start, t_dir *list)
{
	size_t		max;

	max = 0;
	while (start)
	{
		if (ft_strlen(ft_itoa(start->tall)) > max)
			max = ft_strlen(ft_itoa(start->tall));
		start = start->next;
	}
	max += 2;
	while ((max - ft_strlen(ft_itoa(list->tall))) > 0)
	{
		ft_putchar(' ');
		max--;
	}
}
