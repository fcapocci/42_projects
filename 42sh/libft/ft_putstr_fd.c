/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 21:55:28 by fcapocci          #+#    #+#             */
/*   Updated: 2017/01/27 21:55:29 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_putstr_fd(const char *s, int fd)
{
	unsigned int	len;

	len = ft_strlen(s);
	write(fd, s, len);
	return (len);
}
