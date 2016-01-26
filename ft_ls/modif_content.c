/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 19:13:40 by fcapocci          #+#    #+#             */
/*   Updated: 2016/01/25 19:35:53 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*dating(const time_t *clock)
{
	char	*crt_date;
	char	*date;

	date = ctime(clock);
	crt_date = ft_strsub(date, 4, 12);
	ft_memdel((void**)&date);
	return (crt_date);
}
