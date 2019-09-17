/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 13:57:17 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/19 15:17:37 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int num)
{
	char	ch;
	int		is_lim;

	is_lim = 0;
	if (num < 0)
	{
		ft_putchar('-');
		if (num == -2147483648)
		{
			num = -num - 1;
			is_lim = 1;
		}
		else
			num = -num;
	}
	if (num < 10)
		ch = (num % 10) + '0';
	else
	{
		ch = (num % 10) + '0';
		ft_putnbr(num / 10);
	}
	ft_putchar(is_lim ? 8 + '0' : ch);
}
