/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_group.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:35:25 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/28 15:36:45 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static t_stack	*ft_sort_until_g(t_stack *a, int g, t_ret *res)
{
	if (ft_check_side_g(a, g) == 1)
		while (a->bgn->g != g)
			ft_ra(a, res);
	else
		while (a->bgn->g != g)
			a = ft_rra(a, res);
	ft_pb(a, a->s_b, res);
	return (a);
}

static int		ft_final_sort(t_stack *a, t_ret *res)
{
	if (!(ft_group_one_sort(a, res)))
		return (-1);
	if (!(ft_group_sort(a, a->s_b, res)))
		return (-1);
	ft_del_stack(&a);
	return (0);
}

t_ret			*ft_bubble_group(t_num *bgn)
{
	int		p;
	int		g;
	t_ret	*res;
	t_stack	*a;

	if (!(res = ft_ret_new(3)))
		return (NULL);
	if (!(a = ft_stacknew(bgn)))
		return (NULL);
	p = 0;
	g = 0;
	while (g < (a->l_g - 1))
	{
		ft_sort_until_g(a, g, res);
		p++;
		if (p == 3)
		{
			g += 1;
			p = 0;
		}
	}
	if (ft_final_sort(a, res) == -1)
		return (NULL);
	return (res);
}
