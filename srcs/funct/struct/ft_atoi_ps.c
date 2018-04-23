/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:53:01 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/23 21:12:05 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

int		ft_atoi_ps(const char *str)
{
	long	n;
	size_t	i;
	size_t	neg;

	n = 0;
	i = 0;
	neg = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			neg++;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		n = (10 * n) + (str[i] - 48);
		i++;
	}
	if (neg > 0)
		n *= -1;
	if (n > 2147483647 || n < -2147483648)
		return (-1);
	return (0);
}
