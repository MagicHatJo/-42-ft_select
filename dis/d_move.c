/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 08:02:14 by jochang           #+#    #+#             */
/*   Updated: 2019/04/16 08:02:14 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	move_up(void)
{
	int		i;
	t_node	*tmp;

	i = -1;
	tmp = g_cdll->list;
	while (++i < g_win.cpl)
	{
		tmp = tmp->left;
		if (tmp == g_cdll->head || tmp == g_cdll->tail)
		{
			i++;
			break ;
		}
	}
	if (i == g_win.cpl)
		g_cdll->list = tmp;
}

static void	move_down(void)
{
	int		i;
	t_node	*tmp;

	i = -1;
	tmp = g_cdll->list;
	while (++i < g_win.cpl)
	{
		tmp = tmp->right;
		if (tmp == g_cdll->head || tmp == g_cdll->tail)
		{
			i++;
			break ;
		}
	}
	if (i == g_win.cpl)
		g_cdll->list = tmp;
}

void		d_move(uint64_t cmd)
{
	int		i;

	i = 0;
	if (cmd == K_LEFT)
		g_cdll->list = g_cdll->list->left;
	else if (cmd == K_RIGHT)
		g_cdll->list = g_cdll->list->right;
	else if (cmd == K_UP)
		move_up();
	else if (cmd == K_DOWN)
		move_down();
}
