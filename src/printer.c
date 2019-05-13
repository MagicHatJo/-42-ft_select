/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 06:54:58 by jochang           #+#    #+#             */
/*   Updated: 2019/04/16 06:54:59 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	set_text(t_node *node)
{
	struct stat		info;

	if (node == g_cdll->list)
		ft_putstr_fd(tgetstr("us", NULL), STDERR_FILENO);
	if (node->selected)
		ft_putstr_fd(tgetstr("so", NULL), STDERR_FILENO);
	if (!(stat(node->name, &info)))
	{
		if (S_ISDIR(info.st_mode))
			ft_putstr_fd(C_BOLDBLUE, STDERR_FILENO);
		else if (info.st_mode & S_IXUSR)
			ft_putstr_fd(C_RED, STDERR_FILENO);
		if (S_ISLNK(info.st_mode))
			ft_putstr_fd(C_PURPLE, STDERR_FILENO);
		else if (S_ISSOCK(info.st_mode))
			ft_putstr_fd(C_GREEN, STDERR_FILENO);
		else if (S_ISBLK(info.st_mode))
			ft_putstr_fd("\033[44m", STDERR_FILENO);
		else if (S_ISCHR(info.st_mode))
			ft_putstr_fd("\033[34;43m", STDERR_FILENO);
	}
}

static void	unset_text(void)
{
	ft_putstr_fd(tgetstr("ue", NULL), STDERR_FILENO);
	ft_putstr_fd(tgetstr("se", NULL), STDERR_FILENO);
	ft_putstr_fd(C_DEFAULT, STDERR_FILENO);
}

static void	to_output(char *s, int w)
{
	char	buf[1024];

	ft_memset(&buf, ' ', 1024);
	ft_strcpy(buf, s);
	buf[w] = '\0';
	write(STDERR_FILENO, buf, w);
}

void		printer(void)
{
	int		i;
	int		f;
	t_node	*tmp;

	i = -1;
	f = 1;
	if (g_win.winsize.ws_col > g_cdll->maxlen)
	{
		ft_putstr_fd("Search: ", STDERR_FILENO);
		ft_putstr_fd(g_win.buf, STDERR_FILENO);
		tmp = g_cdll->head;
		while (++i < g_cdll->size)
		{
			if (!(i % g_win.cpl))
				ft_putchar_fd('\n', STDERR_FILENO);
			else if (!f)
				ft_putchar_fd(' ', STDERR_FILENO);
			set_text(tmp);
			to_output(tmp->name, g_cdll->maxlen + 1);
			unset_text();
			tmp = tmp->right;
			f = 0;
		}
	}
}
