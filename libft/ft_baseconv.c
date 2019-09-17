/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_baseconv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:02:00 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/05 15:19:06 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_baseconv(int input, int base)
{
	const char *v_base = "0123456789ABCDEF";

	if (base <= 0 || input == 0)
		return ;
	if (input < 0)
	{
		ft_putchar('-');
		input *= -1;
	}
	ft_baseconv(input / base, base);
	ft_putchar(v_base[input % base]);
}
