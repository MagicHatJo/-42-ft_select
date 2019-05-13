/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 06:19:42 by jochang           #+#    #+#             */
/*   Updated: 2019/04/16 06:19:43 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		term_check(void)
{
	char	*s;
	char	buf[1024];

	ft_bzero(&buf, 1024);
	if (!isatty(STDERR_FILENO))
	{
		ft_printf("ft_select: error: terminal not valid\n");
		return (0);
	}
	else if (!(s = getenv("TERM")))
	{
		ft_printf("ft_select: error: $TERM not found\n");
		return (0);
	}
	else if (!tgetent(buf, s))
	{
		ft_printf("ft_select: error: terminfo not found\n");
		return (0);
	}
	return (1);
}
