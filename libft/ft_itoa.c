/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 11:41:42 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/19 15:59:09 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_itoa(int num)
{
	char		*out;
	int			i;
	int			isneg;

	i = 0;
	isneg = 0;
	if (num == 0 || num == -2147483648)
		return (ft_strdup(num == -2147483648 ? "-2147483648" : "0"));
	if (num < 0)
	{
		isneg = 1;
		num *= -1;
	}
	if (!(out = ft_ifalloc(isneg, ft_digitlen(num))))
		return (NULL);
	while (num != 0)
	{
		out[i++] = (num % 10) + (int)'0';
		num /= 10;
	}
	if (isneg == 1)
		out[i++] = '-';
	out[i] = '\0';
	return (ft_strrev(out));
}
