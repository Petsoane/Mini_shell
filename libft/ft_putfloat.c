/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 09:49:04 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/06/27 10:00:42 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putfloat(double num, int precision)
{
	int		base;
	int		fract;

	base = num;
	fract = (num - base) * precision + 0.001;
	ft_putnbr(base);
	ft_putchar('\n');
	ft_putnbr(fract);
}
