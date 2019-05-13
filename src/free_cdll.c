/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cdll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 06:47:52 by jochang           #+#    #+#             */
/*   Updated: 2019/04/16 06:47:52 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	free_cdll(t_cdll *c)
{
	int		i;

	i = 0;
	while (++i <= c->size)
	{
		c->list = c->head;
		c->head = c->head->right;
		free(c->list->name);
		free(c->list);
	}
	free(c);
}
