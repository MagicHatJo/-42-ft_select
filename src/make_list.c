/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 02:12:14 by jochang           #+#    #+#             */
/*   Updated: 2019/04/16 02:12:14 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_cdll	*init_cdll(void)
{
	t_cdll	*cdll;

	cdll = ft_memalloc(sizeof(t_cdll));
	cdll->size = 0;
	cdll->maxlen = 0;
	cdll->head = NULL;
	cdll->tail = NULL;
	cdll->list = NULL;
	return (cdll);
}

static t_node	*new_node(char *val)
{
	t_node	*node;

	node = ft_memalloc(sizeof(t_node));
	node->name = ft_strdup(val);
	node->selected = 0;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

static void		add_node(t_cdll *cdll, t_node *node)
{
	if (cdll->size == 0)
	{
		cdll->head = node;
		cdll->tail = node;
		cdll->list = node;
		node->left = node;
		node->right = node;
	}
	else
	{
		cdll->tail->right = node;
		node->left = cdll->tail;
		cdll->tail = node;
		node->right = cdll->head;
		cdll->head->left = cdll->tail;
	}
	cdll->size++;
}

t_cdll			*make_list(int ac, char **av)
{
	int		i;
	t_cdll	*cdll;
	t_node	*node;
	int		len;

	cdll = init_cdll();
	i = -1;
	while (++i < ac)
	{
		node = new_node(av[i]);
		add_node(cdll, node);
		len = ft_strlen(node->name);
		cdll->maxlen = len > cdll->maxlen ? len : cdll->maxlen;
	}
	return (cdll);
}
