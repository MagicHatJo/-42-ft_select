/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 03:11:35 by jochang           #+#    #+#             */
/*   Updated: 2019/04/16 03:11:36 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	del_buf(char buf[])
{
	int		len;

	len = ft_strlen(buf);
	if (!len)
		return ;
	buf[len - 1] = '\0';
}

static void	add_buf(char buf[], uint64_t cmd)
{
	int		i;
	int		len;
	t_node	*tmp;

	len = ft_strlen(buf);
	buf[len] = cmd;
	len++;
	i = -1;
	tmp = g_cdll->list;
	while (++i < g_cdll->size)
	{
		if (ft_strnequ(tmp->name, buf, len))
		{
			g_cdll->list = tmp;
			return ;
		}
		tmp = tmp->right;
	}
}

int			ft_select(void)
{
	uint64_t	cmd;

	if (!term_check())
		return (0);
	ft_bzero(&g_win.buf, 1024);
	term_init();
	get_winsize();
	signal_handler();
	while (1)
	{
		CLEAR_SCREEN;
		printer();
		cmd = 0;
		read(STDERR_FILENO, &cmd, 6);
		BREAK_CHECK(cmd == K_ENTER);
		if (cmd == 45)
			del_buf(g_win.buf);
		else if (!ft_isspace(cmd) && IS_PRINT(cmd))
			add_buf(g_win.buf, cmd);
		else
			input_handler(cmd);
	}
	term_revert();
	return (1);
}
