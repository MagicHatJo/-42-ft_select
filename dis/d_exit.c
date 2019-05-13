/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 08:04:04 by jochang           #+#    #+#             */
/*   Updated: 2019/04/16 08:04:04 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	d_exit(uint64_t cmd)
{
	(void)cmd;
	free_cdll(g_cdll);
	term_revert();
	exit(0);
}