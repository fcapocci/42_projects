/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 13:58:58 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/20 14:02:04 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_dir		*list;
	t_opt		*optl;

	optl = NULL;
	list = NULL;
	if ((take_option(&optl, &argc, &argv)) == -1)
		return (-1);
	if ((manage(argc, argv, optl, list)) == -1)
		return (-1);
	ft_memdel((void**)&optl);
	ft_memdel((void**)&list);
	return (0);
}
