/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 06:23:11 by jochang           #+#    #+#             */
/*   Updated: 2019/04/16 06:23:11 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		term_init(void)
{
	t_termios	tmp;

	tcgetattr(STDERR_FILENO, &g_original);
	tcgetattr(STDERR_FILENO, &tmp);
	tmp.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDERR_FILENO, TCSANOW, &tmp);
	ft_putstr_fd(tgetstr("ti", NULL), STDERR_FILENO);
	ft_putstr_fd(tgetstr("vi", NULL), STDERR_FILENO);
}
