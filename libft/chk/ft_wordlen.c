/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 11:13:43 by jochang           #+#    #+#             */
/*   Updated: 2018/04/26 06:47:13 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_wordlen(char const *s, char const c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}
