/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 02:02:13 by jochang           #+#    #+#             */
/*   Updated: 2019/04/16 02:02:13 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	print_list(t_cdll *c)
{
	int		i;
	int		f;
	t_node	*tmp;

	i = 0;
	f = 0;
	tmp = c->head;
	while (++i <= c->size)
	{
		if (tmp->selected)
		{
			if (f)
				ft_putchar(' ');
			ft_printf("%s", tmp->name);
			f = 1;
		}
		tmp = tmp->right;
	}
}

int			main(int ac, char **av)
{
	if (ac == 1)
	{
		ft_printf("Usage: ./ft_select [arguments]\n");
		return (0);
	}
	g_cdll = make_list(ac - 1, &av[1]);
	if (ft_select())
		print_list(g_cdll);
	free_cdll(g_cdll);
	return (0);
}
