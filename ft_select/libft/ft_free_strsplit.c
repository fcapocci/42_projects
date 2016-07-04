/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strsplit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 14:52:13 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/17 11:31:23 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_strsplit(char ***tab)
{
	unsigned int	y;

	y = 0;
	if ((*tab) != NULL)
	{
		while ((*tab)[y] != NULL)
		{
			free((*tab)[y]);
			(*tab)[y++] = NULL;
		}
		free(*tab);
		*tab = NULL;
	}
}
