/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_delete.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 08:04:30 by jochang           #+#    #+#             */
/*   Updated: 2019/04/16 08:04:31 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	d_delete(uint64_t cmd)
{
	t_node	*prev;
	t_node	*next;

	if (g_cdll->size <= 1)
		d_exit(cmd);
	if (g_cdll->list == g_cdll->head)
		g_cdll->head = g_cdll->head->right;
	if (g_cdll->list == g_cdll->tail)
		g_cdll->tail = g_cdll->tail->left;
	prev = g_cdll->list->left;
	next = g_cdll->list->right;
	prev->right = next;
	next->left = prev;
	free(g_cdll->list->name);
	free(g_cdll->list);
	g_cdll->list = next;
	g_cdll->size--;
}
