/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_winsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 10:45:01 by jochang           #+#    #+#             */
/*   Updated: 2019/04/16 10:45:02 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	get_winsize(void)
{
	ioctl(STDERR_FILENO, TIOCGWINSZ, &g_win.winsize);
	g_win.cpl = g_win.winsize.ws_col / (g_cdll->maxlen + 1);
}
