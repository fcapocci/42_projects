/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 16:25:02 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/01 19:33:41 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int argc, char **argv)
{
	t_dir		*list;
	t_opt		*optl;

	optl = NULL;
	list = NULL;
	if ((optl = take_option(argc, argv)) == NULL)
		return (-1);
	if ((read_dir(&list, argc, argv)) == -1)
		return (-1);
		/*
	if ((app_option(&list, optl)) == -1)
		return (-1);*/
	printing(list);
	return (0);
}
