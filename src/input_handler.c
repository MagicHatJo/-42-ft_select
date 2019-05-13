/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 08:08:26 by jochang           #+#    #+#             */
/*   Updated: 2019/04/16 08:08:27 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	input_handler(uint64_t cmd)
{
	int			i;
	const t_dis	sel[] = {
		{K_LEFT, &d_move},
		{K_RIGHT, &d_move},
		{K_UP, &d_move},
		{K_DOWN, &d_move},
		{K_SPACE, &d_select},
		{K_ESC, &d_exit},
		{K_DEL, &d_delete},
		{K_BSP, &d_delete}
	};

	i = -1;
	while (++i < OPT_COUNT)
		if (cmd == sel[i].op)
		{
			sel[i].s(cmd);
			return ;
		}
}
