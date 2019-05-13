/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 06:34:15 by jochang           #+#    #+#             */
/*   Updated: 2019/04/16 06:34:15 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	resize(int s)
{
	(void)s;
	get_winsize();
	CLEAR_SCREEN;
	printer();
}

static void	suspend(int s)
{
	(void)s;
	term_revert();
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
}

static void	resume(int s)
{
	(void)s;
	term_init();
	CLEAR_SCREEN;
	printer();
}

static void	kill(int s)
{
	(void)s;
	free_cdll(g_cdll);
	term_revert();
	exit(0);
}

void		signal_handler(void)
{
	signal(SIGWINCH, resize);
	signal(SIGTSTP, suspend);
	signal(SIGSTOP, suspend);
	signal(SIGCONT, resume);
	signal(SIGKILL, kill);
	signal(SIGQUIT, kill);
	signal(SIGINT, kill);
	signal(SIGABRT, kill);
	signal(SIGFPE, kill);
	signal(SIGILL, kill);
	signal(SIGINT, kill);
	signal(SIGSEGV, kill);
	signal(SIGTERM, kill);
}
