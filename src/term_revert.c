/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_revert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 06:23:55 by jochang           #+#    #+#             */
/*   Updated: 2019/04/16 06:23:56 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		term_revert(void)
{
	tcsetattr(STDERR_FILENO, TCSANOW, &g_original);
	ft_putstr_fd(tgetstr("ve", NULL), STDERR_FILENO);
	ft_putstr_fd(tgetstr("te", NULL), STDERR_FILENO);
}
