/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_passline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 18:08:39 by fcapocci          #+#    #+#             */
/*   Updated: 2015/12/12 18:13:38 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_passline(char **buff)
{
	while (**buff != '\n' && **buff !='\0')
		(*buff)++;
	if (**buff == '\n')
		(*buff)++;
}
