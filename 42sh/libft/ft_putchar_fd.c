/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <florianpasquereau37@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 10:29:32 by fpasquer          #+#    #+#             */
/*   Updated: 2015/11/30 23:00:38 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putchar_fd(unsigned char c, int fd)
{
	write(fd, &c, 1);
}