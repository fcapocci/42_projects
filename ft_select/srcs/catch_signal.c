/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 16:12:32 by fcapocci          #+#    #+#             */
/*   Updated: 2016/09/08 17:12:17 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_select.h"

#define END_SIGNAL 32
#define START_SIGNAL 1

static char				*g_tab_error[END_SIGNAL] =
{"terminal line hangup", "interrupt program", "quit program",
	"illegal instruction", "trace trap", "abort program",
	"emulate instruction executed", "floating-point exception", "kill program",
	"bus error", "segmentation violation", "non-existent system call invoked",
	"write on a pipe with no reader", "real-time timer expired",
	"software termination signal", "urgent condition present on socket", "stop",
	"stop signal generated from keyboard", "continue after stop",
	"child status has changed",
	"background read attempted from control terminal",
	"background write attempted to control terminal",
	"I/O is possible on a descriptor", "cpu time limit exceeded",
	"file size limit exceeded", "virtual time alarm", "profiling timer alarm",
	"Window size change", "status request from keyboard",
	"User defined signal 1", "User defined signal 2", ""};

void					print_sign(int signal)
{
	if (signal == SIGTSTP || signal == SIGINT)
		ft_putendl(g_tab_error[signal]);
	if (signal == SIGWINCH)
		print_argv(0);
}

void					print_status(void)
{
	int						i;

	i = START_SIGNAL;
	while (i < END_SIGNAL)
		signal(i++, print_sign);
}
