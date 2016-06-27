/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 21:36:50 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/17 12:52:46 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/_42sh.h"

int							i_table_hash(char *s, unsigned int len_tab)
{
	unsigned int			i;
	unsigned long long int	somme_c;

	if (s == NULL || s[0] == '\0')
		return (-1);
	somme_c = 0;
	 i = 0;
	while (s[i] != '\0')
		somme_c += s[i++];
	return ((int)somme_c % len_tab);
}
