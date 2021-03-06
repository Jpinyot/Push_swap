/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_group_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:29:22 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/28 15:54:40 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static int	ft_g_sort(t_stack *a, t_stack *b, t_ret *ret, int p)
{
	if (b->bgn->p == p)
	{
		if (!(ft_pa(a, b, ret)))
			return (-2);
	}
	else if (b->bgn->next->p == p)
	{
		if (!(ft_sb(b, ret)) || !(ft_pa(a, b, ret)))
			return (-2);
	}
	else
	{
		if (b->bgn->next->p == p - 1)
			if (!(ft_sb(b, ret)))
				return (-2);
		if (b->bgn->p == p - 1)
		{
			if (!(ft_pa(a, b, ret)) || !(ft_sb(b, ret)) ||
					!(ft_pa(a, b, ret)) || !(ft_sa(a, ret)))
				return (-2);
			p -= 1;
		}
	}
	return (p);
}

t_stack		*ft_group_sort(t_stack *a, t_stack *b, t_ret *ret)
{
	int g;
	int p;

	g = a->l_g - 2;
	p = 2;
	while (g != -1)
	{
		if ((p = ft_g_sort(a, b, ret, p)) == -2)
			return (NULL);
		p--;
		if (p == -1)
		{
			g -= 1;
			p = 2;
		}
	}
	return (a);
}
