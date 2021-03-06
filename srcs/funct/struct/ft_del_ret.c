/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_ret.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 18:21:42 by jpinyot           #+#    #+#             */
/*   Updated: 2018/05/06 22:08:02 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

void	ft_del_ret(t_ret **lst)
{
	t_ret *tmp;
	t_ret *l;

	if (!(*lst))
		return ;
	l = *lst;
	while (l)
	{
		tmp = l->next;
		ft_strdel(&(l->tp));
		free(l);
		l = tmp;
	}
	l = NULL;
}
