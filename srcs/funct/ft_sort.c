/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 19:01:53 by jpinyot           #+#    #+#             */
/*   Updated: 2018/03/02 16:20:29 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static t_num	*ft_move(t_num **num)
{
	t_num	*tmp;
	t_num	*rtn;
	t_num	*mv;
	int		w;

	mv = *num;
	rtn = mv;
	tmp = mv->prev;
	while (tmp != NULL)
	{
		if (tmp->prev->num < mv->num)
			break ;
		tmp = tmp->prev;
	}
	while (tmp->next != NULL)
	{
		w = tmp->num;
		tmp->num = mv->num;
		mv->num = w;
		tmp = tmp->next;
	}
	return (rtn);
}

t_num	*ft_sort(t_num *num)
{
	t_num	*arr;
	t_num	*tmp;
	t_num	*rtn;
	int	i;

	i = 0;
	tmp = num;
	arr = ft_lstnew_num(tmp->num, NULL);
	rtn = arr;
	while (tmp != NULL)
	{
		if (!(arr->next = ft_lstnew_num(tmp->next->num, tmp)))
		{
			write(1, "*", 1);
			return (NULL);
		}
		if (arr->num > arr->next->num)
		{
			arr = ft_move(&(arr->next));
			write(1, "&", 1);
		}
		arr = arr->next;
		tmp = tmp->next;
	}
	return (rtn);
}
