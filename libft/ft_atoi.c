/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 08:14:18 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/19 18:17:15 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	isspace(int n)
{
	if (n == '\t' || n == '\n' || n == '\v'
			|| n == '\r' || n == '\f' || n == ' ')
		return (1);
	return (0);
}

int			ft_atoi(const char *num)
{
	long int	sign;
	long int	out;

	out = 0;
	sign = 0;
	while (isspace(*num) == 1)
		num++;
	if (*num == '-' || *num == '+')
	{
		if (*num == '-')
			sign = 1;
		num++;
	}
	while (*num && *num >= '0' && *num <= '9')
	{
		out = (out * 10) + (*num - '0');
		num++;
	}
	out = sign == 1 ? -out : out;
	return ((int)out);
}
